import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
import rclpy.time
from std_msgs.msg import Bool, Float64,Float32MultiArray,Int16
from geometry_msgs.msg import Pose, PoseArray, PoseStamped, Point, Twist
from nav_msgs.msg import Path
from rover_msgs.msg import RoverGoalStatus
import numpy as np
from tf2_ros import Buffer,TransformListener
from visualization_msgs.msg import Marker,MarkerArray
import math
from scipy.spatial.transform import Rotation
import time
import threading
from concurrent.futures import ThreadPoolExecutor
from functools import partial
# import casadi as ca

# PENDING = 0       # 任务处于等待状态，尚未开始
# ACTIVE = 1        # 任务正在进行中
# PREEMPTED = 2     # 任务被抢占，执行中止
# SUCCEEDED = 3     # 任务成功完成
# ABORTED = 4       # 任务由于某种原因被中止
# REJECTED = 5      # 任务被拒绝，未开始执行
# PREEMPTING = 6    # 任务正在被抢占的过程中
# RECALLING = 7     # 任务正在被召回的过程中
# RECALLED = 8      # 任务已被成功召回
# LOST = 9          # 任务状态丢失或未知

class Local_Planner(Node):
    def __init__(self):
        super().__init__('local_planner')

        # 创建回调组
        self.timer_callback_group = rclpy.callback_groups.ReentrantCallbackGroup()
        self.subscription_callback_group = rclpy.callback_groups.MutuallyExclusiveCallbackGroup()
        self.planning_callback_group = rclpy.callback_groups.MutuallyExclusiveCallbackGroup()
        
        # 添加线程锁
        self._lock = threading.Lock()

        # declare parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('replan_period',0.01),
                ('cmd_period', 0.01),
                ('state_period', 0.1),
                ('reached_position_tolerance', 0.2),
                ('reached_yaw_tolerance', 0.2),
                ('goal_status_period', 0.1),
                ('goal_min_angular_speed', -0.5),
                ('goal_max_angular_speed', 0.5),
                ('goal_angular_gain', 2.0),
                ('map_frame_id', 'map'),
                ('base_frame_id', 'odom'),
                ('global_path_step', 10),
                ('dwa_lookhead_step', 0.1),
                ('predict_time', 2.0),
                ('goal_weight', 1.0),
                ('speed_weight', 0.5),
                ('obstacle_weight', 1.9),
                ('safe_distance', 0.3),
                ('omega_min', -1.0),
                ('omega_max', 1.0),
                ('v_min', -0.2),
                ('v_max', 0.6)
            ]
        )
        # parameters initialization
        self.curr_state = np.zeros(5)
        self.z = 0
        self.local_plan = np.zeros([self.get_parameter('global_path_step').value, 2])
        self.best_control = [0.0, 0.0]  # 最优控制输入 [v, ω]

        self.goal_state = np.zeros([self.get_parameter('global_path_step').value, 4])
        self.ref_path_close_set = False
        self.goal_position_reached = False  # 标记是否到达目标点(x,y)
        self.goal_yaw_reached = False  # 标记是否到达目标点(yaw)

        self.reached_position_tolerance = self.get_parameter('reached_position_tolerance').value  # 到达目标点的速度容差
        self.goal_position = None
        self.cur_position = [0.0, 0.0, 0.0]
        self.goal_yaw = 0
        self.cur_yaw = 0

        self.target_state = np.array([-1, 4, np.pi/2])
        self.target_state_close = np.zeros(3)
        self.desired_global_path = [np.zeros([300, 4]), 0]
        self.is_close = False
        self.is_get = False
        self.is_grasp = False
        self.is_all_task_down = False
        self.robot_state_set = False
        self.ref_path_set = False
        self.ob = []
        self.is_end = 0
        self.ob_total = []
        self.last_states_sol = np.zeros(self.get_parameter('global_path_step').value +1)
        self.control_cmd = Twist()

        self.last_cmd_sol = np.zeros([self.get_parameter('global_path_step').value, 2])

        self.rover_goal_status = RoverGoalStatus()

        self.control_cmd = Twist()

        self.times = 0
        self.obstacle_markerarray = MarkerArray()

        # TF2
        self.tf_buffer=Buffer(cache_time=Duration(seconds=10))
        self.tf_listener=TransformListener(self.tf_buffer,self)
        # Subscription (使用订阅回调组)
        self.create_subscription(
            Float32MultiArray, '/obs_raw', self.obs_cb, 10,
            callback_group=self.subscription_callback_group)
        self.create_subscription(
            Float32MultiArray, '/surf_predict_pub', self.global_path_callback, 10,
            callback_group=self.subscription_callback_group)
        self.create_subscription(
            PoseStamped, '/cur_goal', self.rcv_goal_callback, 10,
            callback_group=self.subscription_callback_group)
        # Publisher
        self.pub = self.create_publisher(Twist, 'cmd_vel_nav2_result', 10)
        self.pub_status = self.create_publisher(RoverGoalStatus, '/cur_local_goal_status', 10)
        self.pub_local_path = self.create_publisher(Path, '/local_path', 10)
        self.ob_pub = self.create_publisher(MarkerArray, '/ob_draw', 10)
        # Timer (使用定时器回调组)
        self.create_timer(0.1, self.timer_callback, 
                         callback_group=self.timer_callback_group)
    
    def timer_callback(self):
        self.replan_cb()
        self.pub_cmd()
        self.pub_goal_status()
    
    def obs_cb(self, data):
        self.ob = []
        start_time = time.time()  # 记录起始时间
        if (len(data.data) != 0):

            size = len(data.data)/3
            for i in range(int(size)):
                self.ob.append(
                    ((data.data[3*i]//0.3)*0.3, (data.data[3*i+1]//0.3)*0.3))
            dic = list(set([tuple(t) for t in self.ob]))
            self.ob = [list(v) for v in dic]
            end_time = time.time()  # 记录结束时间
            elapsed_time = end_time - start_time
            # print(f"obs_cb time: {elapsed_time:.6f} seconds")

    def global_path_callback(self, data):
        print('******************global_path_callback*******************')
        if (len(data.data) != 0):
            self.ref_path_set = True
            size = len(data.data)/5
            self.desired_global_path[1] = size
            for i in range(int(size)):
                self.desired_global_path[0][i,
                                            0] = data.data[5*(int(size)-i)-5]
                self.desired_global_path[0][i,
                                            1] = data.data[5*(int(size)-i)-4]
                self.desired_global_path[0][i,
                                            2] = data.data[5*(int(size)-i)-2]
                self.desired_global_path[0][i,
                                            3] = data.data[5*(int(size)-i)-1]
                
    def rcv_goal_callback(self, msg):
        self.goal_position_reached = False  # 重新置位
        self.goal_yaw_reached = False
        # 输出路径包含的点数量
        print('******************rcvGoalCallBack New Goal Pose*******************')
        self.get_logger().info('******************rcvGoalCallBack New Goal Pose*******************')

        self.goal_position = msg.pose.position
        print('Goal Position:')
        print(self.goal_position.x)
        print(self.goal_position.y)
        print(self.goal_position.z)
        # 获取四元数
        orientation_q = msg.pose.orientation
        quaternion = [orientation_q.x, orientation_q.y,
                      orientation_q.z, orientation_q.w]
        self.goal_yaw = self.quaternion_to_yaw(quaternion)

        self.rover_goal_status.x = msg.pose.position.x
        self.rover_goal_status.y = msg.pose.position.y
        self.rover_goal_status.z = msg.pose.position.z
        self.rover_goal_status.orientation_x = msg.pose.orientation.x
        self.rover_goal_status.orientation_y = msg.pose.orientation.y
        self.rover_goal_status.orientation_z = msg.pose.orientation.z
        self.rover_goal_status.orientation_w = msg.pose.orientation.w

    def replan_cb(self):
        if self.goal_position_reached and self.goal_yaw_reached:
            self.rover_goal_status.status = 3

        if self.goal_position_reached:  # 机器人已经到达目标点，停止路径规划
            return

        if self.robot_state_set and self.ref_path_set:
            # 更轻量级的检查，不阻塞主线程
            if hasattr(self, '_planning_future') and not self._planning_future.done():
                self.get_logger().warn("Previous planning still running, skipping...")
                return
            
            # 创建和运行规划任务
            self._planning_future = rclpy.task.Future()
            
            # 使用线程池执行耗时操作
            threading.Thread(target=self._run_planning, daemon=True).start()
        elif self.robot_state_set == False and self.ref_path_set == True:
            print("no pose")
            self.best_control = [0.0, 0.0]  # 如果规划失败，设置默认值
        elif self.robot_state_set == True and self.ref_path_set == False:
            self.best_control = [0.0, 0.0]  # 如果规划失败，设置默认值
        else:
            print("********please set your init pose !*********")

            self.best_control = [0.0, 0.0]  # 如果规划失败，设置默认值

    def _run_planning(self):
        try:
            # 选择目标状态
            self.choose_goal_state()
            
            # 执行规划
            start_time = time.time()
            trajectory, best_control, isOK = self.localPlan(
                self.cur_position, self.goal_position, self.ob, 
                self.control_cmd.linear.x, self.control_cmd.angular.z)
            elapsed_time = time.time() - start_time
            
            # 使用锁保护共享数据访问
            with self._lock:
                self.best_control = best_control
                # 如果规划成功，发布路径
                if isOK and not self.goal_position_reached:
                    self.publish_local_plan(trajectory)
                    self.rover_goal_status.status = 1
                    
                # 如果规划失败
                if not isOK:
                    self.rover_goal_status.status = 5
                    
            self.get_logger().info(f"localPlan execution time: {elapsed_time:.6f} seconds")
        except Exception as e:
            self.get_logger().error(f"Planning error: {str(e)}")
        finally:
            self._planning_future.set_result(None)

    def choose_goal_state(self):
        num = self.find_min_distance(self.curr_state)
        scale = 1
        num_list = []
        for i in range(self.get_parameter('global_path_step').value):
            num_path = min(self.desired_global_path[1]-1, int(num+i*scale))
            num_list.append(num_path)
        if (num >= self.desired_global_path[1]):
            self.is_end = 1
        for k in range(self.get_parameter('global_path_step').value):
            self.goal_state[k] = self.desired_global_path[0][int(num_list[k])]
        
    def find_min_distance(self, c1):
        number = np.argmin(np.array([self.distance_global(
            c1, self.desired_global_path[0][i]) for i in range(int(self.desired_global_path[1]))]))
        return number
    
    def distance_global(self, c1, c2):
        distance = np.sqrt((c1[0]-c2[0])*(c1[0]-c2[0]) +
                           (c1[1]-c2[1])*(c1[1]-c2[1]))
        return distance

    def publish_local_plan(self, trajectory):
        local_path = Path()
        sequ = 0
        local_path.header.stamp = self.get_clock().now().to_msg()
        local_path.header.frame_id = self.get_parameter('map_frame_id').value

        length = trajectory.shape[0]
        for i in range(length):
            this_pose_stamped = PoseStamped()
            this_pose_stamped.pose.position.x = trajectory[i, 0]
            this_pose_stamped.pose.position.y = trajectory[i, 1]
            this_pose_stamped.pose.position.z = self.z + 0.5  
            sequ += 1
            this_pose_stamped.header.stamp = self.get_clock().now().to_msg()
            this_pose_stamped.header.frame_id = self.get_parameter('map_frame_id').value
            local_path.poses.append(this_pose_stamped)

        self.pub_local_path.publish(local_path)

    def has_reached_goal(self):
        """
        判断是否已经到达目标点。
        :return: True 如果到达目标点，否则 False。
        """
        current_position = self.curr_state[:2]
        distance = np.sqrt((current_position[0] - self.goal_position.x) ** 2 +
                           (current_position[1] - self.goal_position.y) ** 2)
        return distance <= self.reached_position_tolerance
    
    def localPlan(self,cur_position, goal_position, obstacles, cur_v=0.0, cur_omega=0.0):

        # 参数设置
        v_min, v_max = self.get_parameter('v_min').value, self.get_parameter('v_max').value   # 线速度范围 (m/s)
        omega_min, omega_max = self.get_parameter('omega_min').value, self.get_parameter('omega_max').value  # 角速度范围 (rad/s)
        predict_time = self.get_parameter('predict_time').value          # 轨迹预测时间 (s)
        dt = self.get_parameter('dwa_lookhead_step').value               # 采样时间步长 (s)
        safe_distance = self.get_parameter('safe_distance').value       # 障碍物安全距离 (m)
        goal_weight = self.get_parameter('goal_weight').value          # 朝向目标的权重
        speed_weight = self.get_parameter('speed_weight').value         # 保持速度的权重
        obstacle_weight = self.get_parameter('obstacle_weight').value      # 避障的权重

        # 当前状态
        x = cur_position[0]
        y = cur_position[1]
        theta = cur_position[2]
        
        goal = self.goal_state[:,:3]
        
        cur_x = goal[-1, 0]  
        cur_y = goal[-1, 1]  
        cur_z = goal[-1, 2]  

        # 定义采样参数
        v_samples = np.arange(max(v_min, 0), min(v_max, 0.6), 0.1)
        omega_samples = np.arange(max(omega_min, -1.0), min(omega_max, 1.0), 0.1)
        
        # 创建采样网格
        v_grid, omega_grid = np.meshgrid(v_samples, omega_samples)
        v_flat = v_grid.flatten()
        omega_flat = omega_grid.flatten()
        
        # 使用线程池并行评估轨迹
        with ThreadPoolExecutor(max_workers=8) as executor:
            # 创建部分应用的函数，为每个线程提供初始参数
            eval_func = partial(
                self.evaluate_trajectory, 
                x=x, y=y, theta=theta, 
                predict_time=predict_time, dt=dt, 
                goal_x=cur_x, goal_y=cur_y,
                obstacles=obstacles, safe_distance=safe_distance,
                goal_weight=goal_weight, speed_weight=speed_weight, 
                obstacle_weight=obstacle_weight
            )
            
            # 提交所有任务
            futures = [executor.submit(eval_func, v, omega) for v, omega in zip(v_flat, omega_flat)]
            
            # 收集结果
            results = []
            for future in futures:
                try:
                    results.append(future.result())
                except Exception as e:
                    self.get_logger().error(f"轨迹评估错误: {str(e)}")
        
        # 提取结果
        if not results:
            return None, [0.0, 0.0], False
            
        # 找到最佳轨迹
        best_idx = np.argmax([r[0] for r in results])
        best_score = results[best_idx][0]
        best_trajectory = results[best_idx][1]
        best_control = [v_flat[best_idx], omega_flat[best_idx]]
        
        isOK = best_trajectory is not None and len(best_trajectory) > 0
        return np.array(best_trajectory) if isOK else None, best_control, isOK
    
    def evaluate_trajectory(self, v, omega, x, y, theta, predict_time, dt, 
                          goal_x, goal_y, obstacles, safe_distance,
                          goal_weight, speed_weight, obstacle_weight):
        """
        评估单个轨迹参数组合
        返回: (总分数, 轨迹)
        """
        # 模拟轨迹
        trajectory = self.simulate_trajectory(x, y, theta, v, omega, predict_time, dt)
        
        if len(trajectory) == 0:
            return float('-inf'), []
            
        # 计算各项得分
        goal_score = goal_weight * self.evaluate_goal_cost(trajectory, goal_x, goal_y)
        speed_score = speed_weight * v
        obstacle_score = -obstacle_weight * self.evaluate_obstacle_cost(trajectory, obstacles, safe_distance)
        
        total_score = goal_score + speed_score + obstacle_score
        
        return total_score, trajectory
    
    def simulate_trajectory(self,x, y, theta, v, omega, predict_time, dt):
        """
        模拟机器人在一段时间内的轨迹。使用向量化操作优化性能。
        """
        # 预计算时间序列
        time_steps = np.arange(0, predict_time, dt)
        n_steps = len(time_steps)
        
        # 预分配轨迹数组
        trajectory = np.zeros((n_steps, 3))
        
        if omega == 0:
            # 直线运动的特殊情况
            trajectory[:, 0] = x + v * np.cos(theta) * time_steps
            trajectory[:, 1] = y + v * np.sin(theta) * time_steps
            trajectory[:, 2] = theta  # 角度保持不变
        else:
            # 曲线运动
            dtheta = omega * time_steps
            trajectory[:, 2] = theta + dtheta  # 角度逐步变化
            
            # 计算位置
            if abs(omega) < 1e-6:  # 接近直线运动
                trajectory[:, 0] = x + v * np.cos(theta + dtheta/2) * dt * np.arange(n_steps)
                trajectory[:, 1] = y + v * np.sin(theta + dtheta/2) * dt * np.arange(n_steps)
            else:  # 明显的曲线运动
                # 使用运动学方程，避免累积误差
                radius = v / omega
                trajectory[:, 0] = x + radius * (np.sin(theta + dtheta) - np.sin(theta))
                trajectory[:, 1] = y - radius * (np.cos(theta + dtheta) - np.cos(theta))
        
        return trajectory
    
    def evaluate_goal_cost(self,trajectory, goal_x, goal_y):
        """
        计算轨迹到目标的得分（目标距离）。
        """
        last_state = trajectory[-1]
        dist_to_goal = math.sqrt(
            (last_state[0] - goal_x)**2 + (last_state[1] - goal_y)**2)
        return -dist_to_goal  # 距离越近，得分越高
    
    def evaluate_obstacle_cost(self, trajectory, obstacles, safe_distance):
        """
        使用向量化操作计算轨迹与障碍物的代价
        """
        # 防御性编程：检查数据类型和形状
        trajectory = np.array(trajectory)[:, :2]  # 确保提取前两列（x,y）
        
        # 检查障碍物数据是否为空或格式不正确
        if not obstacles or len(obstacles) == 0:
            return 0.0  # 无障碍物，返回0成本
        
        try:
            obstacles = np.array(obstacles)
            # 确保obstacles是二维数组
            if len(obstacles.shape) == 1:
                # 如果是一维数组，尝试将其重塑为Nx2数组
                if obstacles.size % 2 == 0:  # 确保元素个数是偶数
                    obstacles = obstacles.reshape(-1, 2)
                else:
                    # 数据格式不正确，无法重塑
                    self.get_logger().warn(f"Invalid obstacles data shape: {obstacles.shape}")
                    return 0.0
            
            # 计算每个轨迹点到每个障碍物的距离矩阵 - 使用广播
            # 形状: (n_trajectory_points, n_obstacles)
            # 使用更高效的向量化计算
            cost = 0.0
            epsilon = 1e-6
            
            # 为了优化性能，分批处理
            batch_size = 50  # 每批处理的轨迹点数
            for i in range(0, len(trajectory), batch_size):
                batch = trajectory[i:i+batch_size]
                # 使用广播计算每个轨迹点到每个障碍物的欧氏距离
                # 重塑为便于广播的形状
                traj_batch = batch[:, np.newaxis, :]  # shape: (batch, 1, 2)
                obs = obstacles[np.newaxis, :, :]     # shape: (1, n_obstacles, 2)
                
                # 计算欧氏距离
                dists = np.sqrt(np.sum((traj_batch - obs)**2, axis=2))  # shape: (batch, n_obstacles)
                
                # 只考虑小于安全距离的障碍物
                mask = dists < safe_distance
                if np.any(mask):
                    close_dists = dists[mask]
                    weights = 1 / (close_dists ** 2 + epsilon)
                    batch_cost = np.sum(weights * (safe_distance - close_dists) ** 2)
                    cost += batch_cost
            
            return cost
            
        except Exception as e:
            self.get_logger().error(f"Error in obstacle cost calculation: {str(e)}")
            return 0.0  # 出错时返回0成本，确保规划继续

    def pub_goal_status(self):
        self.pub_status.publish(self.rover_goal_status)

    def pub_cmd(self):
        self.cmd(self.best_control)

        try:
            now=rclpy.time.Time()
            transform = self.tf_buffer.lookup_transform(
                self.get_parameter('map_frame_id').value,
                self.get_parameter('base_frame_id').value,
                # self.get_clock().now().to_msg(),
                # time=rclpy.time.Time(),  # 获取最新可用变换
                now
                )
            
            trans = transform.transform.translation
            rot = transform.transform.rotation
            
            roll, pitch, yaw = self.quart_to_rpy(
                rot.x, rot.y, rot.z, rot.w)
            self.curr_state[0] = trans.x
            self.curr_state[1] = trans.y
            self.curr_state[2] = (yaw+np.pi) % (2*np.pi)-np.pi
            self.curr_state[3] = roll
            self.curr_state[4] = pitch

            self.z = trans.z
            self.robot_state_set = True
            self.cur_yaw = yaw

            self.cur_position[0] = trans.x
            self.cur_position[1] = trans.y
            self.cur_position[2] = (yaw+np.pi) % (2*np.pi)-np.pi

        except Exception as e:
                self.get_logger().error(f'TF error: {str(e)}')
        return
        
    def quart_to_rpy(self, x, y, z, w):
        r = math.atan2(2*(w*x+y*z), 1-2*(x*x+y*y))
        p = math.asin(2*(w*y-z*x))
        y = math.atan2(2*(w*z+x*y), 1-2*(z*z+y*y))
        return r, p, y
    
    def cmd(self, data):
        # 如果目标未到达，正常行驶
        if not self.goal_position_reached:
            self.control_cmd.linear.x = data[0]
            self.control_cmd.angular.z = data[1]
        else:
            yaw_difference = (self.goal_yaw - self.cur_yaw +
                              np.pi) % (2 * np.pi) - np.pi  # 差值归一化到 [-π, π]

            if abs(yaw_difference) > self.get_parameter('reached_yaw_tolerance').value:
                # 动态调整角速度
                self.control_cmd.angular.z = max(self.get_parameter('goal_min_angular_speed'), min(
                    self.get_parameter('goal_max_angular_speed').value, self.get_parameter('goal_angular_gain') * yaw_difference))
            elif abs(yaw_difference) > 0.05:  # 设置更小的误差范围平滑停止
                self.control_cmd.angular.z = 0.1 * \
                    np.sign(yaw_difference)  # 低速微调
            else:
                self.goal_yaw_reached = True
                # 误差小于阈值范围，停止旋转
                self.control_cmd.angular.z = 0

            self.control_cmd.linear.x = 0  # 停止前进

        self.pub.publish(self.control_cmd)

    def quaternion_to_yaw(self, quaternion):
        # 创建四元数对象
        r = Rotation.from_quat(quaternion)
        # 提取yaw (绕z轴的旋转角)
        yaw = r.as_euler('xyz', degrees=False)[2]
        return yaw
    
    # def choose_goal_state(self):
    #     num = self.find_min_distance(self.curr_state)
    #     scale = 1
    #     num_list = []
    #     for i in range(self.get_parameter('global_path_step').value):
    #         num_path = min(self.desired_global_path[1]-1, int(num+i*scale))
    #         num_list.append(num_path)
    #     if (num >= self.desired_global_path[1]):
    #         self.is_end = 1
    #     for k in range(self.get_parameter('global_path_step').value):
    #         self.goal_state[k] = self.desired_global_path[0][int(num_list[k])]

def main(args=None):
    rclpy.init(args=args)
    planner = Local_Planner()
    
    # 使用多线程执行器
    executor = rclpy.executors.MultiThreadedExecutor(num_threads=3)
    executor.add_node(planner)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        planner.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()