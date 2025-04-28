// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rover_msgs:msg/RoverBmsStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__BUILDER_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rover_msgs/msg/detail/rover_bms_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rover_msgs
{

namespace msg
{

namespace builder
{

class Init_RoverBmsStatus_temperature
{
public:
  explicit Init_RoverBmsStatus_temperature(::rover_msgs::msg::RoverBmsStatus & msg)
  : msg_(msg)
  {}
  ::rover_msgs::msg::RoverBmsStatus temperature(::rover_msgs::msg::RoverBmsStatus::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rover_msgs::msg::RoverBmsStatus msg_;
};

class Init_RoverBmsStatus_current
{
public:
  explicit Init_RoverBmsStatus_current(::rover_msgs::msg::RoverBmsStatus & msg)
  : msg_(msg)
  {}
  Init_RoverBmsStatus_temperature current(::rover_msgs::msg::RoverBmsStatus::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_RoverBmsStatus_temperature(msg_);
  }

private:
  ::rover_msgs::msg::RoverBmsStatus msg_;
};

class Init_RoverBmsStatus_voltage
{
public:
  explicit Init_RoverBmsStatus_voltage(::rover_msgs::msg::RoverBmsStatus & msg)
  : msg_(msg)
  {}
  Init_RoverBmsStatus_current voltage(::rover_msgs::msg::RoverBmsStatus::_voltage_type arg)
  {
    msg_.voltage = std::move(arg);
    return Init_RoverBmsStatus_current(msg_);
  }

private:
  ::rover_msgs::msg::RoverBmsStatus msg_;
};

class Init_RoverBmsStatus_percentage
{
public:
  explicit Init_RoverBmsStatus_percentage(::rover_msgs::msg::RoverBmsStatus & msg)
  : msg_(msg)
  {}
  Init_RoverBmsStatus_voltage percentage(::rover_msgs::msg::RoverBmsStatus::_percentage_type arg)
  {
    msg_.percentage = std::move(arg);
    return Init_RoverBmsStatus_voltage(msg_);
  }

private:
  ::rover_msgs::msg::RoverBmsStatus msg_;
};

class Init_RoverBmsStatus_header
{
public:
  Init_RoverBmsStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoverBmsStatus_percentage header(::rover_msgs::msg::RoverBmsStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RoverBmsStatus_percentage(msg_);
  }

private:
  ::rover_msgs::msg::RoverBmsStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rover_msgs::msg::RoverBmsStatus>()
{
  return rover_msgs::msg::builder::Init_RoverBmsStatus_header();
}

}  // namespace rover_msgs

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__BUILDER_HPP_
