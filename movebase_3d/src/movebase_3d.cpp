#include <ros/ros.h>
// PCL specific includes 用PCL的时候需要用到的库
#include <sensor_msgs/PointCloud2.h>
#include <tf/transform_listener.h>
#include <vector>

using namespace std;
using namespace std_msgs;

// 先声明发布器，因为回调函数里面会用到
ros::Publisher pub;
float filter_z_min, filter_z_max;
tf::TransformListener listener;

int main(int argc, char **argv)
{
    // Initialize ROS
    ros::init(argc, argv, "movebase_3d");
    ros::NodeHandle nh;

    nh.param("filter_z_min", filter_z_min, -0.5f);
    nh.param("filter_z_max", filter_z_max, 1.6f);

    ros::Rate loop_rate(10); // HZ
    while (true)
    {
        ROS_ERROR("*********movebase_3d*******");

        tf::StampedTransform transform;
        while (true && ros::ok())
        {
            if (listener.waitForTransform("/map", "/base_link", ros::Time(0), ros::Duration(1.0)))
            {
                try
                {
                    listener.lookupTransform("/map", "/base_link", ros::Time(0), transform); // 查询变换
                    break;
                }
                catch (tf::TransformException &ex)
                {
                    continue;
                }
            }
            else
            {
                ROS_ERROR("Transform not available within timeout.");
            }
        }
        // start_pt << transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z();

        ros::spinOnce();
        loop_rate.sleep(); // 等待loop_rate設定的時間
    }
}
