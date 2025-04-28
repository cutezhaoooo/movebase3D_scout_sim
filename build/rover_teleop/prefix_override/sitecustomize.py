import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/liu/ROS2_MoveBase_3D/install/rover_teleop'
