# pragma once

#include "string"
#include "memory"
#include "rclcpp/rclcpp.hpp"
#include "rviz_common/panel.hpp"  // rviz包
#include <QPushButton>
#include <QTableWidget>
#include <QCheckBox>
#include "visualization_msgs/msg/marker.hpp"
#include "geometry_msgs/msg/pose_array.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/string.hpp"
#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "rover_msgs/msg/rover_goal_status.hpp"  // ROS2相较与ros需要中间文件夹msg
#include "pluginlib/class_list_macros.hpp"

namespace rviz_multi_goals_manager_plugins
{
    class MultiNaviGoalsPanel : public rviz_common::Panel
    {
        Q_OBJECT
    public:
        explicit MultiNaviGoalsPanel(QWidget *parent = 0);

    public Q_SLOTS:

        void setMaxNumGoal(const QString &maxNumGoal);

        void writePose(geometry_msgs::msg::Pose pose);
        void markPose(const geometry_msgs::msg::PoseStamped &pose);
        void deleteMark();

    protected Q_SLOTS:

        void changeEvent(); // update max number of goal
        void initPoseTable();    // initialize the pose table

        void updatePoseTable(); // update the pose table
        void startNavi();       // start navigate for the first pose
        // void cancelNavi();

        void goalCntCB(const geometry_msgs::msg::PoseStamped &pose); // goal count sub callback function

        void statusGlobalPoseCB(const rover_msgs::msg::RoverGoalStatus &poseStatus);
        void statusLocalPoseCB(const rover_msgs::msg::RoverGoalStatus &poseStatus);

        void checkCycle();

        void completeNavi(); // after the first pose, continue to navigate the rest of poses
        void cycleNavi();

        bool checkGoal(std::vector<action_msgs::msg::GoalStatus> status_list); // check whether arrived the goal
        bool checkGoalStatus(rover_msgs::msg::RoverGoalStatus globalStatus, rover_msgs::msg::RoverGoalStatus localStatus);

        void startSpin(); // spin for sub
    protected:
        QLineEdit *output_maxNumGoal_editor_;
        QPushButton *output_maxNumGoal_button_, *output_reset_button_, *output_startNavi_button_, *output_cancel_button_;
        QTableWidget *poseArray_table_;
        QCheckBox *cycle_checkbox_;

        QString output_maxNumGoal_;

        // The ROS node handle.
        rclcpp::Node::SharedPtr node_;
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr goal_pub_;
        rclcpp::Publisher<action_msgs::msg::GoalInfo>::SharedPtr cancel_pub_;
        rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
        
        rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_sub_;
        rclcpp::Subscription<rover_msgs::msg::RoverGoalStatus>::SharedPtr global_goal_status_sub_;
        rclcpp::Subscription<rover_msgs::msg::RoverGoalStatus>::SharedPtr local_goal_status_sub_;
            
        int maxNumGoal_;
        int curGoalIdx_ = 0, cycleCnt_ = 0;
        bool permit_ = false, cycle_ = false, arrived_ = false;
        geometry_msgs::msg::PoseArray pose_array_;

        action_msgs::msg::GoalInfo cur_goalid_;
        int cur_goal_id;
        rover_msgs::msg::RoverGoalStatus globalGoalStatus, localGoalStatus;
    };
}

PLUGINLIB_EXPORT_CLASS(
    rviz_multi_goals_manager_plugins::MultiNaviGoalsPanel, 
    rviz_common::Panel
  )
