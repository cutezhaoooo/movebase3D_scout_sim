#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud2_iterator.h>
#include <livox_ros_driver/CustomMsg.h>

/**
 * 将Livox的CustomMsg转换为ROS的PointCloud2
 * @param custom_msg Livox自定义消息
 * @return 转换后的PointCloud2消息
 */
sensor_msgs::PointCloud2 convertCustomMsgToPointCloud2(const livox_ros_driver::CustomMsg& custom_msg) {
    // 创建PointCloud2消息
    sensor_msgs::PointCloud2 pc2_msg;

    // 设置Header
    pc2_msg.header = custom_msg.header;
    pc2_msg.header.frame_id="body";

    // 设置点云结构
    pc2_msg.height = 1;                      // 无序点云，height为1
    pc2_msg.width = custom_msg.point_num;     // 点云数量

    // 定义字段描述：x, y, z, intensity, tag, line
    pc2_msg.fields.resize(6);
    pc2_msg.fields[0].name = "x";
    pc2_msg.fields[0].offset = 0;
    pc2_msg.fields[0].datatype = sensor_msgs::PointField::FLOAT32;
    pc2_msg.fields[0].count = 1;

    pc2_msg.fields[1].name = "y";
    pc2_msg.fields[1].offset = 4;
    pc2_msg.fields[1].datatype = sensor_msgs::PointField::FLOAT32;
    pc2_msg.fields[1].count = 1;

    pc2_msg.fields[2].name = "z";
    pc2_msg.fields[2].offset = 8;
    pc2_msg.fields[2].datatype = sensor_msgs::PointField::FLOAT32;
    pc2_msg.fields[2].count = 1;

    pc2_msg.fields[3].name = "intensity";
    pc2_msg.fields[3].offset = 12;
    pc2_msg.fields[3].datatype = sensor_msgs::PointField::UINT8;
    pc2_msg.fields[3].count = 1;

    pc2_msg.fields[4].name = "tag";
    pc2_msg.fields[4].offset = 13;
    pc2_msg.fields[4].datatype = sensor_msgs::PointField::UINT8;
    pc2_msg.fields[4].count = 1;

    pc2_msg.fields[5].name = "line";
    pc2_msg.fields[5].offset = 14;
    pc2_msg.fields[5].datatype = sensor_msgs::PointField::UINT8;
    pc2_msg.fields[5].count = 1;

    // 配置数据布局参数
    pc2_msg.is_bigendian = false;            // 小端模式
    pc2_msg.point_step = 15;                 // 每个点占15字节 (4*3 + 1*3)
    pc2_msg.row_step = pc2_msg.point_step * pc2_msg.width;
    pc2_msg.is_dense = true;                 // 假设所有点有效

    // 分配数据存储空间
    pc2_msg.data.resize(pc2_msg.row_step);

    // 使用PointCloud2Iterator填充数据
    sensor_msgs::PointCloud2Iterator<float> iter_x(pc2_msg, "x");
    sensor_msgs::PointCloud2Iterator<float> iter_y(pc2_msg, "y");
    sensor_msgs::PointCloud2Iterator<float> iter_z(pc2_msg, "z");
    sensor_msgs::PointCloud2Iterator<uint8_t> iter_intensity(pc2_msg, "intensity");
    sensor_msgs::PointCloud2Iterator<uint8_t> iter_tag(pc2_msg, "tag");
    sensor_msgs::PointCloud2Iterator<uint8_t> iter_line(pc2_msg, "line");

    for (const auto& point : custom_msg.points) {
        *iter_x = point.x;
        *iter_y = point.y;
        *iter_z = point.z;
        *iter_intensity = point.reflectivity;
        *iter_tag = point.tag;
        *iter_line = point.line;

        ++iter_x;
        ++iter_y;
        ++iter_z;
        ++iter_intensity;
        ++iter_tag;
        ++iter_line;
    }

    return pc2_msg;
}

/**
 * 示例回调函数，接收CustomMsg并发布PointCloud2
 * @param custom_msg Livox自定义消息
 * @param pub PointCloud2发布器
 */
void customMsgCallback(const livox_ros_driver::CustomMsg::ConstPtr& custom_msg, ros::Publisher& pub) {
    // 转换消息
    sensor_msgs::PointCloud2 pc2_msg = convertCustomMsgToPointCloud2(*custom_msg);

    // 发布消息
    pub.publish(pc2_msg);
}

int main(int argc, char** argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "livox_to_pointcloud2");
    ros::NodeHandle nh;

    // 创建发布器
    // ros::Publisher pub = nh.advertise<sensor_msgs::PointCloud2>("pointCloud", 10);
    ros::Publisher pub = nh.advertise<sensor_msgs::PointCloud2>("output_filter", 10);

    // 创建订阅器，绑定回调函数
    ros::Subscriber sub = nh.subscribe<livox_ros_driver::CustomMsg>(
        "/livox/lidar", 10, boost::bind(customMsgCallback, _1, boost::ref(pub)));

    

    // 进入ROS循环
    ros::spin();

    return 0;
}