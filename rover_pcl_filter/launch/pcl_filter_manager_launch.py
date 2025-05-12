from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    return LaunchDescription([
        # 参数声明
        DeclareLaunchArgument('x_min', default_value='-0.3'),
        DeclareLaunchArgument('x_max', default_value='0.3'),
        DeclareLaunchArgument('y_min', default_value='-0.3'),
        DeclareLaunchArgument('y_max', default_value='0.3'),
        DeclareLaunchArgument('z_min', default_value='0.0'),
        DeclareLaunchArgument('z_max', default_value='0.4'),
        DeclareLaunchArgument('filter_z_min', default_value='-0.5'),
        DeclareLaunchArgument('filter_z_max', default_value='1.6'),
        
        # 节点配置
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
            output='screen'
        )
    ])