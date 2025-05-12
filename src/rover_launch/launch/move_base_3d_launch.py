from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch_ros.descriptions import ParameterFile
from nav2_common.launch import RewrittenYaml

import os

def generate_launch_description():
    # 功能包路径参数化
    global_planner_share = get_package_share_directory('global_planner_3d')
    rover_gpr_share = get_package_share_directory('rover_gpr')

     # 是否使用仿真时间，我们用gazebo，这里设置成true
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    # 命名空间
    namespace = LaunchConfiguration("namespace")
    # 参数文件
    params_file_obs = LaunchConfiguration("params_file_obs")
    params_file_global = LaunchConfiguration("params_file_global")
    params_file_local = LaunchConfiguration("params_file_local")

    # yaml参数文件重写
    configured_params_obs = ParameterFile(
        RewrittenYaml(
            source_file=params_file_obs,
            root_key=namespace,
            param_rewrites={},
            convert_types=True,
        ),
        allow_substs=True,
    )
    configured_params_global = ParameterFile(
        RewrittenYaml(
            source_file=params_file_global,
            root_key=namespace,
            param_rewrites={},
            convert_types=True,
        ),
        allow_substs=True,
    )
    configured_params_local = ParameterFile(
        RewrittenYaml(
            source_file=params_file_local,
            root_key=namespace,
            param_rewrites={},
            convert_types=True,
        ),
        allow_substs=True,
    )

    declare_namespace_cmd = DeclareLaunchArgument(
        "namespace",
        default_value="/red_standard_robot1",
        # default_value="",
        description="Top-level namespace"
    )

    declare_params_file_obs_cmd = DeclareLaunchArgument(
        "params_file_obs",
        default_value=os.path.join(
            global_planner_share, "config", "move_base_global_obs.yaml"
        ),
        description="Full path to the ROS2 parameters file to use for all launched nodes"
    )

    declare_params_file_global_cmd = DeclareLaunchArgument(
        "params_file_global",
        default_value=os.path.join(
            global_planner_share, "config", "move_base_global.yaml"
        ),
        description="Full path to the ROS2 parameters file to use for all launched nodes"
    )

    declare_params_file_local_cmd = DeclareLaunchArgument(
        "params_file_local",
        default_value=os.path.join(
            global_planner_share, "config", "move_base_local.yaml"
        ),
        description="Full path to the ROS2 parameters file to use for all launched nodes"
    )

    return LaunchDescription([
        declare_namespace_cmd,
        declare_params_file_obs_cmd,
        declare_params_file_global_cmd,
        declare_params_file_local_cmd,
        # 路径点生成
        Node(
            package= 'rviz_waypoint_generator_plungins',
            executable='waypoint_generator',
            parameters=[
                {'waypoint_type': 'manual-lonely-waypoint'},
                {'use_sim_time': use_sim_time},
            ],
            remappings=[
                ('goal', '/goal'),
                ('waypoints', '/waypoint_generator/waypoints'),
                ('/tf', [namespace, '/tf']),
                ('/tf_static', [namespace, '/tf_static'])
            ],
        ),

        # 全局规划器
        Node(
            package='global_planner_3d',
            executable='global_planning_node',
            name='global_planning_node',
            output='screen',
            parameters=[
                {os.path.join(global_planner_share, 'config/move_base_3d/move_base_global.yaml')},
                {'use_sim_time': use_sim_time},
            ],
            remappings=[
                ('waypoints', '/waypoint_generator/waypoints'),
                ('global_map', 'global_map'),
                ('/tf', [namespace, '/tf']),
                ('/tf_static', [namespace, '/tf_static'])
            ],
            namespace=namespace
        ),
        
        # 障碍物处理节点
        Node(
            package='global_planner_3d',
            executable='global_planning_obs',
            name='global_planning_obs',
            output='screen',
            parameters=[
                {os.path.join(global_planner_share, 'config/move_base_3d/move_base_global_obs.yaml')},
                {'use_sim_time': use_sim_time}
            ],
            remappings=[
                ('pointCloud', 'cloud_registered'),
                ('global_map', 'global_map'),
                ('/tf', [namespace, '/tf']),
                ('/tf_static', [namespace, '/tf_static'])
            ],
            namespace=namespace
        ),
        
        # 地形分析模块
        Node(
            package='rover_gpr',
            executable='gpr_path',
            name='gpr_path',
            output='screen',
            parameters=[
                {'file.cfg_path': os.path.join(rover_gpr_share, 'config/hyperparam.txt')},
                {'use_sim_time': use_sim_time}
            ],
            namespace=namespace
        ),
        
        # 局部规划器
        Node(
            package='local_planner_3d',
            executable='local_planner_node',
            name='local_planner_3d',
            output='screen',
            parameters=[
                {os.path.join(global_planner_share, 'config/move_base_3d/move_base_local.yaml')},
                {'use_sim_time': use_sim_time},
            ],
            remappings=[
                ('/tf', [namespace, '/tf']),
                ('/tf_static', [namespace, '/tf_static'])
            ],
            namespace=namespace
        ),

         # 参数声明
        DeclareLaunchArgument('x_min', default_value='-0.3'),
        DeclareLaunchArgument('x_max', default_value='0.3'),
        DeclareLaunchArgument('y_min', default_value='-0.3'),
        DeclareLaunchArgument('y_max', default_value='0.3'),
        DeclareLaunchArgument('z_min', default_value='0.0'),
        DeclareLaunchArgument('z_max', default_value='0.4'),
        DeclareLaunchArgument('filter_z_min', default_value='-0.5'),
        DeclareLaunchArgument('filter_z_max', default_value='1.6'),

        # 点云过滤器
        Node(
            package='rover_pcl_filter',
            executable='pcl_filter_manager',
            name='pcl_filter_manager',
            parameters=[
                {
                    'x_min': LaunchConfiguration('x_min'),
                    'x_max': LaunchConfiguration('x_max'),
                    'y_min': LaunchConfiguration('y_min'),
                    'y_max': LaunchConfiguration('y_max'),
                    'z_min': LaunchConfiguration('z_min'),
                    'z_max': LaunchConfiguration('z_max'),
                    'filter_z_min': LaunchConfiguration('filter_z_min'),
                    'filter_z_max': LaunchConfiguration('filter_z_max')
                }
            ],
            remappings=[
                ('pointCloud', 'cloud_registered')
            ],
            output='screen',
            namespace=namespace
        ),

        # rviz2
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            parameters=[{'use_sim_time': True}],
        )
    ])