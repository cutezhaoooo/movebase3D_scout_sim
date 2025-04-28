// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rover_msgs:msg/RoverGoalStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__STRUCT_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rover_msgs__msg__RoverGoalStatus __attribute__((deprecated))
#else
# define DEPRECATED__rover_msgs__msg__RoverGoalStatus __declspec(deprecated)
#endif

namespace rover_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoverGoalStatus_
{
  using Type = RoverGoalStatus_<ContainerAllocator>;

  explicit RoverGoalStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->orientation_x = 0.0;
      this->orientation_y = 0.0;
      this->orientation_z = 0.0;
      this->orientation_w = 0.0;
      this->status = 0;
      this->goal_id = 0;
      this->text = "";
    }
  }

  explicit RoverGoalStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : text(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->orientation_x = 0.0;
      this->orientation_y = 0.0;
      this->orientation_z = 0.0;
      this->orientation_w = 0.0;
      this->status = 0;
      this->goal_id = 0;
      this->text = "";
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _orientation_x_type =
    double;
  _orientation_x_type orientation_x;
  using _orientation_y_type =
    double;
  _orientation_y_type orientation_y;
  using _orientation_z_type =
    double;
  _orientation_z_type orientation_z;
  using _orientation_w_type =
    double;
  _orientation_w_type orientation_w;
  using _status_type =
    uint8_t;
  _status_type status;
  using _goal_id_type =
    uint8_t;
  _goal_id_type goal_id;
  using _text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _text_type text;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__orientation_x(
    const double & _arg)
  {
    this->orientation_x = _arg;
    return *this;
  }
  Type & set__orientation_y(
    const double & _arg)
  {
    this->orientation_y = _arg;
    return *this;
  }
  Type & set__orientation_z(
    const double & _arg)
  {
    this->orientation_z = _arg;
    return *this;
  }
  Type & set__orientation_w(
    const double & _arg)
  {
    this->orientation_w = _arg;
    return *this;
  }
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__goal_id(
    const uint8_t & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->text = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t PENDING =
    0u;
  static constexpr uint8_t ACTIVE =
    1u;
  static constexpr uint8_t PREEMPTED =
    2u;
  static constexpr uint8_t SUCCEEDED =
    3u;
  static constexpr uint8_t ABORTED =
    4u;
  static constexpr uint8_t REJECTED =
    5u;
  static constexpr uint8_t PREEMPTING =
    6u;
  static constexpr uint8_t RECALLING =
    7u;
  static constexpr uint8_t RECALLED =
    8u;
  static constexpr uint8_t LOST =
    9u;

  // pointer types
  using RawPtr =
    rover_msgs::msg::RoverGoalStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rover_msgs::msg::RoverGoalStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rover_msgs::msg::RoverGoalStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rover_msgs::msg::RoverGoalStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rover_msgs__msg__RoverGoalStatus
    std::shared_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rover_msgs__msg__RoverGoalStatus
    std::shared_ptr<rover_msgs::msg::RoverGoalStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoverGoalStatus_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->orientation_x != other.orientation_x) {
      return false;
    }
    if (this->orientation_y != other.orientation_y) {
      return false;
    }
    if (this->orientation_z != other.orientation_z) {
      return false;
    }
    if (this->orientation_w != other.orientation_w) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->text != other.text) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoverGoalStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoverGoalStatus_

// alias to use template instance with default allocator
using RoverGoalStatus =
  rover_msgs::msg::RoverGoalStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::PENDING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::ACTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::PREEMPTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::SUCCEEDED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::ABORTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::REJECTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::PREEMPTING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::RECALLING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::RECALLED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RoverGoalStatus_<ContainerAllocator>::LOST;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace rover_msgs

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__STRUCT_HPP_
