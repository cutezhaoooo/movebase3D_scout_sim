#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

// 回调函数：当接收到cmd_vel消息时被调用
void cmd_vel_callback(const geometry_msgs::Twist& cmd_vel){
    // 打印线速度和角速度信息
    ROS_INFO("Received linear velocity: x=[%f], y=[%f], z=[%f]", 
             cmd_vel.linear.x, cmd_vel.linear.y, cmd_vel.linear.z);
    ROS_INFO("Received angular velocity: x=[%f], y=[%f], z=[%f]", 
             cmd_vel.angular.x, cmd_vel.angular.y, cmd_vel.angular.z);
}

int main(int argc, char** argv){
    // 初始化ROS节点
    ros::init(argc, argv, "cmd_vel_listener");
    ros::NodeHandle nh;

    // 订阅cmd_vel话题
    ros::Subscriber cmd_vel_sub = nh.subscribe("/cmd_vel", 1000, cmd_vel_callback);

    // 进入ROS循环，等待回调函数被调用
    ros::spin();

    return 0;
}