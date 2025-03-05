#include <ros/ros.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "pcd_publisher");
    ros::NodeHandle nh;

    // 创建一个发布者，发布到/map话题，消息类型为sensor_msgs::PointCloud2
    // 被重映射了 要用重映射的名字
    ros::Publisher remap_pub = nh.advertise<sensor_msgs::PointCloud2>("/rtabmap/cloud_map", 1);
    ros::Publisher pub = nh.advertise<sensor_msgs::PointCloud2>("/map", 1);

    // 加载PCD文件
    pcl::PointCloud<pcl::PointXYZ> cloud;
    // if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/z/ws_livox/src/FAST_LIO/PCD/scans.pcd", cloud) == -1) //* load the file
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/z/movebase3d_scout_sim/src/FAST_LIO/PCD/scans.pcd", cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file your_pcd_file.pcd \n");
        return (-1);
    }
    // ROS_INFO("Loaded %d data points from your_pcd_file.pcd", cloud.width * cloud.height);

    // 将PCL点云数据转换为ROS消息类型
    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(cloud, output);

    // 设置frame_id属性
    output.header.frame_id = "map";

    ros::Rate loop_rate(1); // 发布频率可以根据需要调整
    while (ros::ok())
    {
        // 发布点云数据
        pub.publish(output);
        remap_pub.publish(output);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}