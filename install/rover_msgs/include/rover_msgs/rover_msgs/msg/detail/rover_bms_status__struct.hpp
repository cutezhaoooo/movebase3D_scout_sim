// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rover_msgs:msg/RoverBmsStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__STRUCT_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rover_msgs__msg__RoverBmsStatus __attribute__((deprecated))
#else
# define DEPRECATED__rover_msgs__msg__RoverBmsStatus __declspec(deprecated)
#endif

namespace rover_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoverBmsStatus_
{
  using Type = RoverBmsStatus_<ContainerAllocator>;

  explicit RoverBmsStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percentage = 0;
      this->voltage = 0.0;
      this->current = 0.0;
      this->temperature = 0.0;
    }
  }

  explicit RoverBmsStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percentage = 0;
      this->voltage = 0.0;
      this->current = 0.0;
      this->temperature = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _percentage_type =
    uint8_t;
  _percentage_type percentage;
  using _voltage_type =
    double;
  _voltage_type voltage;
  using _current_type =
    double;
  _current_type current;
  using _temperature_type =
    double;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__percentage(
    const uint8_t & _arg)
  {
    this->percentage = _arg;
    return *this;
  }
  Type & set__voltage(
    const double & _arg)
  {
    this->voltage = _arg;
    return *this;
  }
  Type & set__current(
    const double & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__temperature(
    const double & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rover_msgs::msg::RoverBmsStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rover_msgs::msg::RoverBmsStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rover_msgs::msg::RoverBmsStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rover_msgs::msg::RoverBmsStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rover_msgs__msg__RoverBmsStatus
    std::shared_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rover_msgs__msg__RoverBmsStatus
    std::shared_ptr<rover_msgs::msg::RoverBmsStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoverBmsStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->percentage != other.percentage) {
      return false;
    }
    if (this->voltage != other.voltage) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoverBmsStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoverBmsStatus_

// alias to use template instance with default allocator
using RoverBmsStatus =
  rover_msgs::msg::RoverBmsStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rover_msgs

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__STRUCT_HPP_
