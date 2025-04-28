// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rover_msgs:msg/RoverRCStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__STRUCT_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__STRUCT_HPP_

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
# define DEPRECATED__rover_msgs__msg__RoverRCStatus __attribute__((deprecated))
#else
# define DEPRECATED__rover_msgs__msg__RoverRCStatus __declspec(deprecated)
#endif

namespace rover_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoverRCStatus_
{
  using Type = RoverRCStatus_<ContainerAllocator>;

  explicit RoverRCStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connect = false;
      this->ch1 = 0;
      this->ch2 = 0;
      this->ch3 = 0;
      this->ch4 = 0;
      this->ch5 = 0;
      this->ch6 = 0;
      this->ch7 = 0;
      this->ch8 = 0;
      this->ch9 = 0;
      this->ch10 = 0;
    }
  }

  explicit RoverRCStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connect = false;
      this->ch1 = 0;
      this->ch2 = 0;
      this->ch3 = 0;
      this->ch4 = 0;
      this->ch5 = 0;
      this->ch6 = 0;
      this->ch7 = 0;
      this->ch8 = 0;
      this->ch9 = 0;
      this->ch10 = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _connect_type =
    bool;
  _connect_type connect;
  using _ch1_type =
    int8_t;
  _ch1_type ch1;
  using _ch2_type =
    int8_t;
  _ch2_type ch2;
  using _ch3_type =
    int8_t;
  _ch3_type ch3;
  using _ch4_type =
    int8_t;
  _ch4_type ch4;
  using _ch5_type =
    int8_t;
  _ch5_type ch5;
  using _ch6_type =
    int8_t;
  _ch6_type ch6;
  using _ch7_type =
    int8_t;
  _ch7_type ch7;
  using _ch8_type =
    int8_t;
  _ch8_type ch8;
  using _ch9_type =
    int8_t;
  _ch9_type ch9;
  using _ch10_type =
    int8_t;
  _ch10_type ch10;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__connect(
    const bool & _arg)
  {
    this->connect = _arg;
    return *this;
  }
  Type & set__ch1(
    const int8_t & _arg)
  {
    this->ch1 = _arg;
    return *this;
  }
  Type & set__ch2(
    const int8_t & _arg)
  {
    this->ch2 = _arg;
    return *this;
  }
  Type & set__ch3(
    const int8_t & _arg)
  {
    this->ch3 = _arg;
    return *this;
  }
  Type & set__ch4(
    const int8_t & _arg)
  {
    this->ch4 = _arg;
    return *this;
  }
  Type & set__ch5(
    const int8_t & _arg)
  {
    this->ch5 = _arg;
    return *this;
  }
  Type & set__ch6(
    const int8_t & _arg)
  {
    this->ch6 = _arg;
    return *this;
  }
  Type & set__ch7(
    const int8_t & _arg)
  {
    this->ch7 = _arg;
    return *this;
  }
  Type & set__ch8(
    const int8_t & _arg)
  {
    this->ch8 = _arg;
    return *this;
  }
  Type & set__ch9(
    const int8_t & _arg)
  {
    this->ch9 = _arg;
    return *this;
  }
  Type & set__ch10(
    const int8_t & _arg)
  {
    this->ch10 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rover_msgs::msg::RoverRCStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rover_msgs::msg::RoverRCStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rover_msgs::msg::RoverRCStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rover_msgs::msg::RoverRCStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rover_msgs__msg__RoverRCStatus
    std::shared_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rover_msgs__msg__RoverRCStatus
    std::shared_ptr<rover_msgs::msg::RoverRCStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoverRCStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->connect != other.connect) {
      return false;
    }
    if (this->ch1 != other.ch1) {
      return false;
    }
    if (this->ch2 != other.ch2) {
      return false;
    }
    if (this->ch3 != other.ch3) {
      return false;
    }
    if (this->ch4 != other.ch4) {
      return false;
    }
    if (this->ch5 != other.ch5) {
      return false;
    }
    if (this->ch6 != other.ch6) {
      return false;
    }
    if (this->ch7 != other.ch7) {
      return false;
    }
    if (this->ch8 != other.ch8) {
      return false;
    }
    if (this->ch9 != other.ch9) {
      return false;
    }
    if (this->ch10 != other.ch10) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoverRCStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoverRCStatus_

// alias to use template instance with default allocator
using RoverRCStatus =
  rover_msgs::msg::RoverRCStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rover_msgs

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__STRUCT_HPP_
