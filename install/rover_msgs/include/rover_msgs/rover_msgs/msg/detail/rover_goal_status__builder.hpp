// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rover_msgs:msg/RoverGoalStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__BUILDER_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rover_msgs/msg/detail/rover_goal_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rover_msgs
{

namespace msg
{

namespace builder
{

class Init_RoverGoalStatus_text
{
public:
  explicit Init_RoverGoalStatus_text(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  ::rover_msgs::msg::RoverGoalStatus text(::rover_msgs::msg::RoverGoalStatus::_text_type arg)
  {
    msg_.text = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_goal_id
{
public:
  explicit Init_RoverGoalStatus_goal_id(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_text goal_id(::rover_msgs::msg::RoverGoalStatus::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RoverGoalStatus_text(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_status
{
public:
  explicit Init_RoverGoalStatus_status(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_goal_id status(::rover_msgs::msg::RoverGoalStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RoverGoalStatus_goal_id(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_orientation_w
{
public:
  explicit Init_RoverGoalStatus_orientation_w(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_status orientation_w(::rover_msgs::msg::RoverGoalStatus::_orientation_w_type arg)
  {
    msg_.orientation_w = std::move(arg);
    return Init_RoverGoalStatus_status(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_orientation_z
{
public:
  explicit Init_RoverGoalStatus_orientation_z(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_orientation_w orientation_z(::rover_msgs::msg::RoverGoalStatus::_orientation_z_type arg)
  {
    msg_.orientation_z = std::move(arg);
    return Init_RoverGoalStatus_orientation_w(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_orientation_y
{
public:
  explicit Init_RoverGoalStatus_orientation_y(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_orientation_z orientation_y(::rover_msgs::msg::RoverGoalStatus::_orientation_y_type arg)
  {
    msg_.orientation_y = std::move(arg);
    return Init_RoverGoalStatus_orientation_z(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_orientation_x
{
public:
  explicit Init_RoverGoalStatus_orientation_x(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_orientation_y orientation_x(::rover_msgs::msg::RoverGoalStatus::_orientation_x_type arg)
  {
    msg_.orientation_x = std::move(arg);
    return Init_RoverGoalStatus_orientation_y(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_z
{
public:
  explicit Init_RoverGoalStatus_z(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_orientation_x z(::rover_msgs::msg::RoverGoalStatus::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_RoverGoalStatus_orientation_x(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_y
{
public:
  explicit Init_RoverGoalStatus_y(::rover_msgs::msg::RoverGoalStatus & msg)
  : msg_(msg)
  {}
  Init_RoverGoalStatus_z y(::rover_msgs::msg::RoverGoalStatus::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RoverGoalStatus_z(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

class Init_RoverGoalStatus_x
{
public:
  Init_RoverGoalStatus_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoverGoalStatus_y x(::rover_msgs::msg::RoverGoalStatus::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RoverGoalStatus_y(msg_);
  }

private:
  ::rover_msgs::msg::RoverGoalStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rover_msgs::msg::RoverGoalStatus>()
{
  return rover_msgs::msg::builder::Init_RoverGoalStatus_x();
}

}  // namespace rover_msgs

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__BUILDER_HPP_
