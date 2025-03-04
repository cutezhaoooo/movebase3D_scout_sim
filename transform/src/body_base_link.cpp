// 使用fast lio做的定位 
// fast lio中body坐标系是预测的雷达坐标系
// camera init是雷达第一帧的坐标系

// 所以现在需要补充一个body到base_link的坐标变换 也就是雷达到base_link的坐标变换

// body -> odom body其实是雷达坐标系 
// 
#include "ros/ros.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "body_base_link_transform_publisher");
    ros::NodeHandle node;

    tf2_ros::TransformBroadcaster br;

    ros::Rate rate(10.0); // 10 Hz

    while (node.ok()) {
        geometry_msgs::TransformStamped transformStamped;
        transformStamped.header.stamp = ros::Time::now();
        transformStamped.header.frame_id = "body";
        transformStamped.child_frame_id = "base_link";

        // 设置平移值为0，因为没有平移
        transformStamped.transform.translation.x = 0.0;
        transformStamped.transform.translation.y = 0.0;
        transformStamped.transform.translation.z = -0.36;

        // 创建四元数并设置为180度（π弧度）的俯仰旋转
        tf2::Quaternion q;
        // q.setRPY(0, M_PI, 0); // 按需设置翻滚(roll)、俯仰(pitch)、偏航(yaw)，这里设置180度的俯仰旋转
        q.setRPY(0, 0, 0); // 按需设置翻滚(roll)、俯仰(pitch)、偏航(yaw)，这里设置180度的俯仰旋转

        transformStamped.transform.rotation.x = q.x();
        transformStamped.transform.rotation.y = q.y();
        transformStamped.transform.rotation.z = q.z();
        transformStamped.transform.rotation.w = q.w();

        // 发布变换
        br.sendTransform(transformStamped);

        rate.sleep();
    }

    return 0;
}