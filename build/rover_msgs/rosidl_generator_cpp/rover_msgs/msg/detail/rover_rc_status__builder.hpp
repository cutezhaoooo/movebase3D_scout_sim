// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rover_msgs:msg/RoverRCStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__BUILDER_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rover_msgs/msg/detail/rover_rc_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rover_msgs
{

namespace msg
{

namespace builder
{

class Init_RoverRCStatus_ch10
{
public:
  explicit Init_RoverRCStatus_ch10(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  ::rover_msgs::msg::RoverRCStatus ch10(::rover_msgs::msg::RoverRCStatus::_ch10_type arg)
  {
    msg_.ch10 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch9
{
public:
  explicit Init_RoverRCStatus_ch9(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch10 ch9(::rover_msgs::msg::RoverRCStatus::_ch9_type arg)
  {
    msg_.ch9 = std::move(arg);
    return Init_RoverRCStatus_ch10(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch8
{
public:
  explicit Init_RoverRCStatus_ch8(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch9 ch8(::rover_msgs::msg::RoverRCStatus::_ch8_type arg)
  {
    msg_.ch8 = std::move(arg);
    return Init_RoverRCStatus_ch9(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch7
{
public:
  explicit Init_RoverRCStatus_ch7(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch8 ch7(::rover_msgs::msg::RoverRCStatus::_ch7_type arg)
  {
    msg_.ch7 = std::move(arg);
    return Init_RoverRCStatus_ch8(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch6
{
public:
  explicit Init_RoverRCStatus_ch6(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch7 ch6(::rover_msgs::msg::RoverRCStatus::_ch6_type arg)
  {
    msg_.ch6 = std::move(arg);
    return Init_RoverRCStatus_ch7(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch5
{
public:
  explicit Init_RoverRCStatus_ch5(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch6 ch5(::rover_msgs::msg::RoverRCStatus::_ch5_type arg)
  {
    msg_.ch5 = std::move(arg);
    return Init_RoverRCStatus_ch6(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch4
{
public:
  explicit Init_RoverRCStatus_ch4(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch5 ch4(::rover_msgs::msg::RoverRCStatus::_ch4_type arg)
  {
    msg_.ch4 = std::move(arg);
    return Init_RoverRCStatus_ch5(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch3
{
public:
  explicit Init_RoverRCStatus_ch3(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch4 ch3(::rover_msgs::msg::RoverRCStatus::_ch3_type arg)
  {
    msg_.ch3 = std::move(arg);
    return Init_RoverRCStatus_ch4(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch2
{
public:
  explicit Init_RoverRCStatus_ch2(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch3 ch2(::rover_msgs::msg::RoverRCStatus::_ch2_type arg)
  {
    msg_.ch2 = std::move(arg);
    return Init_RoverRCStatus_ch3(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_ch1
{
public:
  explicit Init_RoverRCStatus_ch1(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch2 ch1(::rover_msgs::msg::RoverRCStatus::_ch1_type arg)
  {
    msg_.ch1 = std::move(arg);
    return Init_RoverRCStatus_ch2(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_connect
{
public:
  explicit Init_RoverRCStatus_connect(::rover_msgs::msg::RoverRCStatus & msg)
  : msg_(msg)
  {}
  Init_RoverRCStatus_ch1 connect(::rover_msgs::msg::RoverRCStatus::_connect_type arg)
  {
    msg_.connect = std::move(arg);
    return Init_RoverRCStatus_ch1(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

class Init_RoverRCStatus_header
{
public:
  Init_RoverRCStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoverRCStatus_connect header(::rover_msgs::msg::RoverRCStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RoverRCStatus_connect(msg_);
  }

private:
  ::rover_msgs::msg::RoverRCStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rover_msgs::msg::RoverRCStatus>()
{
  return rover_msgs::msg::builder::Init_RoverRCStatus_header();
}

}  // namespace rover_msgs

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__BUILDER_HPP_
