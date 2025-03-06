#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

serial::Serial ser;

// 直接发送cmd_vel中的数据
void cmd_vel_callback(const geometry_msgs::Twist& cmd_vel){
    uint8_t s_buffer[16]; // 假设缓冲区大小足够存储所有需要的数据
    memset(s_buffer, 0, sizeof(s_buffer));

    // 数据打包
    s_buffer[0] = 0xff; // 起始标志位1
    s_buffer[1] = 0xfe; // 起始标志位2

    // 将浮点数转换为字节并添加到缓冲区
    memcpy(&s_buffer[2], &cmd_vel.linear.x, sizeof(float)); // Vx
    memcpy(&s_buffer[6], &cmd_vel.angular.z, sizeof(float)); // W

    // 简单的CRC校验，实际应用中应使用更强的校验算法
    for(int i = 2; i < 10; ++i) {
        s_buffer[10] ^= s_buffer[i];
    }

    try {
        size_t bytes_written = ser.write(s_buffer, 11); // 发送11字节的数据（包括起始标志和CRC）
        ROS_INFO_STREAM("Sent " << bytes_written << " bytes over serial.");
    } catch (serial::IOException& e) {
        ROS_ERROR_STREAM("Failed to write to serial port: " << e.what());
    }
}

int main(int argc, char** argv){
    ros::init(argc, argv, "direct_serial_sender");
    ros::NodeHandle nh;

    // 订阅/turtle1/cmd_vel话题用于测试 $ rosrun turtlesim turtle_teleop_key
    ros::Subscriber write_sub = nh.subscribe("/cmd_vel", 1000, cmd_vel_callback);

    try {
        ser.setPort("/dev/ttyUSB0");
        ser.setBaudrate(115200);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException& e) {
        ROS_ERROR_STREAM("Unable to open port: " << e.what());
        return -1;
    }

    if(ser.isOpen()){
        ROS_INFO_STREAM("Serial Port initialized");
    }
    else{
        return -1;
    }

    ros::Rate loop_rate(10); // 设置循环频率为10Hz

    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}