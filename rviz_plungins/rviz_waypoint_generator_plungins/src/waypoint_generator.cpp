#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/vector3.hpp>
#include <nav_msgs/msg/path.hpp>
#include <tf2/LinearMath/Quaternion.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/utils.hpp>
#include <rviz_waypoint_generator_plungins/sample_waypoints.h>
#include <vector>
#include <deque>
#include <boost/format.hpp>
#include <Eigen/Dense>
#include <memory>
// #include <utils.hpp>

using namespace std;
using bfmt = boost::format;

class WayPointGenerator  :public rclcpp::Node
{
public:
    WayPointGenerator() : Node("waypoint_generator")
    {
        this->declare_parameter<std::string>("waypoint_type","manual");
        waypoint_type = this->get_parameter("waypoint_type").get_value<string>();

        pub1_=this->create_publisher<nav_msgs::msg::Path>("waypoints",50);
        pub2_=this->create_publisher<geometry_msgs::msg::PoseArray>("waypoints_vis",10);
        

        sub1_=this->create_subscription<nav_msgs::msg::Odometry>(
            "/icp_odom", 10, std::bind(&WayPointGenerator::odom_callback, this, std::placeholders::_1));
        sub2_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "goal", 10, std::bind(&WayPointGenerator::goal_callback, this, std::placeholders::_1));
        sub3_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "traj_start_trigger", 10, std::bind(&WayPointGenerator::traj_start_trigger_callback, this, std::placeholders::_1)); 
        
        is_odom_ready = false;
        trigged_time = this->now();
    }
private:
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr pub1_;
    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr pub2_;
    // rclcpp::Publisher<> pub3;

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub1_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr sub2_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr sub3_;

    string waypoint_type;
    bool is_odom_ready;
    nav_msgs::msg::Odometry odom;
    nav_msgs::msg::Path waypoints;

    // series waypoint needed
    std::deque<nav_msgs::msg::Path> waypointSegments;
    rclcpp::Time trigged_time;

    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        is_odom_ready = true;
        odom = *msg;

        if (!waypointSegments.empty())
        {
            // auto expected_time = waypointSegments.front().header.stamp;
            rclcpp::Time expected_time(waypointSegments.front().header.stamp);
            rclcpp::Time odom_time(odom.header.stamp);
            if (odom_time >= expected_time)
            {
                waypoints = waypointSegments.front();

                std::stringstream ss;
                ss << bfmt("Series send %.3f from start:\n") % trigged_time.seconds();
                for (auto &pose_stamped : waypoints.poses)
                {
                    ss << bfmt("P[%.2f, %.2f, %.2f] q(%.2f,%.2f,%.2f,%.2f)") %
                            pose_stamped.pose.position.x % pose_stamped.pose.position.y %
                            pose_stamped.pose.position.z % pose_stamped.pose.orientation.w %
                            pose_stamped.pose.orientation.x % pose_stamped.pose.orientation.y %
                            pose_stamped.pose.orientation.z
                    << std::endl;
                }
                RCLCPP_INFO(this->get_logger(), "%s", ss.str().c_str());

                publish_waypoints_vis();
                publish_waypoints();
                waypointSegments.pop_front();
            }
        }
    }

    void goal_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
        trigged_time = this->now(); // odom.header.stamp;

        this->get_parameter("waypoint_type",waypoint_type);

        if (waypoint_type == string("circle"))
        {
            waypoints = circle();
            publish_waypoints_vis();
            publish_waypoints();
        }
        else if (waypoint_type == string("eight"))
        {
            waypoints = eight();
            publish_waypoints_vis();
            publish_waypoints();
        }
        else if (waypoint_type == string("point"))
        {
            waypoints = point();
            publish_waypoints_vis();
            publish_waypoints();
        }
        else if (waypoint_type == string("series"))
        {
            load_waypoints(trigged_time);
        }
        else if (waypoint_type == string("manual-lonely-waypoint"))
        {
            cout << "recieve_x:  " << msg->pose.position.x << endl;
            cout << "recieve_y:  " << msg->pose.position.y << endl;
            cout << "recieve_z:  " << msg->pose.position.z << endl;

            if (msg->pose.position.z >= 0)
            {
                // if height >= 0, it's a valid goal;
                geometry_msgs::msg::PoseStamped pt = *msg;
                waypoints.poses.clear();
                waypoints.poses.push_back(pt);
                publish_waypoints_vis();
                publish_waypoints();
            }
            else
            {
                RCLCPP_WARN(this->get_logger(),"[waypoint_generator] invalid goal in manual-lonely-waypoint mode.");
            }
        }
        else
        {
            if (msg->pose.position.z > 0)
            {
                // if height > 0, it's a normal goal;
                geometry_msgs::msg::PoseStamped pt = *msg;
                if (waypoint_type == string("noyaw"))
                {
                    // tf2::Quaternion q;
                    // q.setRPY(0.0,0.0,0.0);  // yaw初始化为0
                    // pt.pose.orientation = tf2::toMsg(q);
                    double yaw = tf2::getYaw(odom.pose.pose.orientation);
                    tf2::Quaternion q;
                    q.setRPY(0.0,0.0,yaw);  // yaw初始化为0
                    pt.pose.orientation = tf2::toMsg(q);
                }
                waypoints.poses.push_back(pt);
                publish_waypoints_vis();
            }
            else if (msg->pose.position.z > -1.0)
            {
                // if 0 > height > -1.0, remove last goal;
                if (waypoints.poses.size() >= 1)
                {
                    waypoints.poses.erase(std::prev(waypoints.poses.end()));
                }
                publish_waypoints_vis();
            }
            else
            {
                // if -1.0 > height, end of input
                if (waypoints.poses.size() >= 1)
                {
                    publish_waypoints_vis();
                    publish_waypoints();
                }
            }
        }
    }

    void traj_start_trigger_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) 
    {
        if (!is_odom_ready) {
            RCLCPP_ERROR(this->get_logger(), "No odom!");
            return;
        }

        RCLCPP_WARN(this->get_logger(), "Trigger!");
        trigged_time = odom.header.stamp;
        this->get_parameter("waypoint_type", waypoint_type);

        RCLCPP_ERROR(this->get_logger(), "Pattern %s generated!", waypoint_type.c_str());
        if (waypoint_type == "free") {
            // Implement point()
        } else if (waypoint_type == "circle") {
            // Implement circle()
        } else if (waypoint_type == "series") {
            load_waypoints(trigged_time);
        }
    }

    void publish_waypoints()
    {
        waypoints.header.frame_id = std::string("map");
        waypoints.header.stamp = this->now();
        pub1_->publish(waypoints);

        geometry_msgs::msg::PoseStamped init_pose;
        init_pose.header = odom.header;
        init_pose.pose = odom.pose.pose;
        waypoints.poses.insert(waypoints.poses.begin(), init_pose);
        waypoints.poses.clear();
    }

    void publish_waypoints_vis()
    {
        nav_msgs::msg::Path wp_vis = waypoints;
        geometry_msgs::msg::PoseArray poseArray;
        poseArray.header.frame_id = std::string("map");
        poseArray.header.stamp = this->now();

        {
            geometry_msgs::msg::Pose init_pose;
            init_pose = odom.pose.pose;
            poseArray.poses.push_back(init_pose);
        }

        for (auto it = waypoints.poses.begin(); it != waypoints.poses.end(); ++it)
        {
            geometry_msgs::msg::Pose p;
            p = it->pose;
            poseArray.poses.push_back(p);
        }
        pub2_->publish(poseArray);
    }

    void load_waypoints(const rclcpp::Time & time_base)
    {
        int seg_cnt = 0;
        waypointSegments.clear();
        this->get_parameter("segment_cnt",seg_cnt);
        for (int i = 0; i < seg_cnt; ++i)
        {
            load_seg(i, time_base);
            if (i > 0)
            {
                rclcpp::Time prev_time(waypointSegments[i-1].header.stamp);
                rclcpp::Time curr_time(waypointSegments[i].header.stamp);
                if (prev_time >= curr_time)  // 使用rclcpp::Time比较
                {
                    RCLCPP_FATAL(this->get_logger(), "Invalid segment timing");
                    exit(1);
                }
            }
        }
        RCLCPP_INFO(this->get_logger(),"Overall load %zu segments", waypointSegments.size());
    }

    void load_seg(int segid, const rclcpp::Time &time_base) {
        std::string seg_str = boost::str(bfmt("seg%d.") % segid);
        double yaw;
        double time_from_start;

        RCLCPP_INFO(this->get_logger(), "Getting segment %d", segid);
        this->get_parameter(seg_str + "yaw", yaw);
        if (yaw <= -3.1499999 || yaw >= 3.1499999) {
            RCLCPP_FATAL(this->get_logger(), "yaw=%.3f", yaw);
            exit(1);
        }
        this->get_parameter(seg_str + "time_from_start", time_from_start);
        if (time_from_start < 0.0) {
            RCLCPP_FATAL(this->get_logger(), "Invalid time_from_start");
            exit(1);
        }

        std::vector<double> ptx, pty, ptz;
        this->get_parameter(seg_str + "x", ptx);
        this->get_parameter(seg_str + "y", pty);
        this->get_parameter(seg_str + "z", ptz);

        if (ptx.empty() || ptx.size() != pty.size() || ptx.size() != ptz.size()) {
            RCLCPP_FATAL(this->get_logger(), "Invalid waypoint parameters");
            exit(1);
        }

        nav_msgs::msg::Path path_msg;
        path_msg.header.stamp = time_base + rclcpp::Duration::from_seconds(time_from_start);
        path_msg.header.frame_id = "map";

        double baseyaw = tf2::getYaw(odom.pose.pose.orientation);

        for (size_t k = 0; k < ptx.size(); ++k) {
            geometry_msgs::msg::PoseStamped pt;
            tf2::Quaternion q;
            q.setRPY(0, 0, baseyaw + yaw);
            pt.pose.orientation = tf2::toMsg(q);

            Eigen::Vector2d dp(ptx[k], pty[k]);
            Eigen::Vector2d rdp(
                cos(-baseyaw - yaw) * dp.x() + sin(-baseyaw - yaw) * dp.y(),
                -sin(-baseyaw - yaw) * dp.x() + cos(-baseyaw - yaw) * dp.y()
            );

            pt.pose.position.x = rdp.x() + odom.pose.pose.position.x;
            pt.pose.position.y = rdp.y() + odom.pose.pose.position.y;
            pt.pose.position.z = ptz[k] + odom.pose.pose.position.z;
            path_msg.poses.push_back(pt);
        }

        waypointSegments.push_back(path_msg);
    }
};

int main(int argc,char** argv)
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<WayPointGenerator>());
    rclcpp::shutdown();
    return 0;
}