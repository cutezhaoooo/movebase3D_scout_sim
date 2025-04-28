from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    rover_teleop_share = get_package_share_directory('rover_teleop')

    return LaunchDescription([

    ])