import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
import select
import os
import time
from threading import Thread

# 平台检测和输入处理
if os.name == 'nt':
    import msvcrt
else:
    import tty
    import termios

# 机器人参数配置
ROBOT_PARAMS = {
    'burger': {'max_lin': 1.22, 'max_ang': 2.84},
    'waffle': {'max_lin': 1.26, 'max_ang': 1.82},
    'waffle_pi': {'max_lin': 1.26, 'max_ang': 1.82},
    'default': {'max_lin': 1.22, 'max_ang': 2.84}
}

# 控制参数
LIN_VEL_STEP = 0.05
ANG_VEL_STEP = 0.1

HELP_MESSAGE = """
Control Your Rover!
---------------------------
Moving around:
        w
   a    s    d
        x

w/x : increase/decrease linear velocity 
a/d : increase/decrease angular velocity

space key, s : force stop

CTRL-C to quit
"""

ERROR_MESSAGE = "Communications Failed"

class TeleopKeyboard(Node):
    def __init__(self):
        super().__init__('teleop_keyboard')
        
        # 参数配置
        self.declare_parameter('model', 'burger')
        self.robot_model = self.get_parameter('model').value
        
        # 初始化发布器
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        
        # 控制变量
        self.target_linear = 0.0
        self.target_angular = 0.0
        self.control_linear = 0.0
        self.control_angular = 0.0
        
        # 终端设置
        if os.name != 'nt':
            self.settings = termios.tcgetattr(sys.stdin)
        
        # 创建键盘监听线程
        self.key_thread = Thread(target=self._key_listener)
        self.key_thread.daemon = True
        self.key_thread.start()
        
        # 创建控制定时器
        self.timer = self.create_timer(0.1, self._timer_callback)
        
        self.get_logger().info(HELP_MESSAGE)

    def _get_max_vel(self, vel_type):
        """获取最大速度限制"""
        return ROBOT_PARAMS.get(
            self.robot_model, 
            ROBOT_PARAMS['default']
        )[f'max_{"lin" if vel_type == "linear" else "ang"}']

    def _constrain(self, value, min_val, max_val):
        """数值范围限制"""
        return max(min(value, max_val), min_val)

    def _key_listener(self):
        """独立键盘监听线程"""
        try:
            while rclpy.ok():
                key = self._get_key()
                self._process_key(key)
        except Exception as e:
            self.get_logger().error(f"Keyboard error: {str(e)}")

    def _get_key(self):
        """跨平台获取键盘输入"""
        if os.name == 'nt':
            return msvcrt.getch().decode() if msvcrt.kbhit() else ''
        
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
        key = sys.stdin.read(1) if rlist else ''
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
        return key

    def _process_key(self, key):
        """处理键盘输入"""
        if key == 'w':
            self.target_linear += LIN_VEL_STEP
        elif key == 'x':
            self.target_linear -= LIN_VEL_STEP
        elif key == 'a':
            self.target_angular += ANG_VEL_STEP
        elif key == 'd':
            self.target_angular -= ANG_VEL_STEP
        elif key in (' ', 's'):
            self.target_linear = 0.0
            self.target_angular = 0.0
        elif key == '\x03':  # CTRL-C
            raise KeyboardInterrupt
        
        # 应用速度限制
        max_lin = self._get_max_vel('linear')
        max_ang = self._get_max_vel('angular')
        self.target_linear = self._constrain(self.target_linear, -max_lin, max_lin)
        self.target_angular = self._constrain(self.target_angular, -max_ang, max_ang)

    def _timer_callback(self):
        """定时器回调生成平滑速度"""
        # 线性速度平滑
        if self.control_linear < self.target_linear:
            self.control_linear = min(self.target_linear, self.control_linear + LIN_VEL_STEP/2)
        else:
            self.control_linear = max(self.target_linear, self.control_linear - LIN_VEL_STEP/2)
        
        # 角速度平滑
        if self.control_angular < self.target_angular:
            self.control_angular = min(self.target_angular, self.control_angular + ANG_VEL_STEP/2)
        else:
            self.control_angular = max(self.target_angular, self.control_angular - ANG_VEL_STEP/2)
        
        # 发布控制指令
        twist = Twist()
        twist.linear.x = self.control_linear
        twist.angular.z = self.control_angular
        self.publisher.publish(twist)

    def stop(self):
        """停止机器人并重置终端"""
        twist = Twist()
        self.publisher.publish(twist)
        if os.name != 'nt':
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)

def main(args=None):
    rclpy.init(args=args)
    node = TeleopKeyboard()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down...")
    finally:
        node.stop()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()