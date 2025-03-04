// 发布建图的map与fast lio的camera_init的坐标变换
#include "ros/ros.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "map_camera_init_transform_publisher");
    ros::NodeHandle node;

    tf2_ros::TransformBroadcaster br;

    ros::Rate rate(10.0); // 10 Hz

    while (node.ok()) {
        geometry_msgs::TransformStamped transformStamped;
        transformStamped.header.stamp = ros::Time::now();
        transformStamped.header.frame_id = "map";
        transformStamped.child_frame_id = "camera_init";

        // 设置平移和旋转值。这里以固定值为例，实际应用中这些值应来自传感器或其他计算。
        transformStamped.transform.translation.x = 0.0;
        transformStamped.transform.translation.y = 0.0;
        transformStamped.transform.translation.z = 0.0;

        tf2::Quaternion q;
        // q.setRPY(0, M_PI, 0); // 按需设置翻滚(roll)、俯仰(pitch)、偏航(yaw)
        q.setRPY(0, 0, 0); // 按需设置翻滚(roll)、俯仰(pitch)、偏航(yaw)
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