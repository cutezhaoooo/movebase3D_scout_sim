// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rover_msgs:msg/RoverGoalStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__TRAITS_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rover_msgs/msg/detail/rover_goal_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rover_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RoverGoalStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: orientation_x
  {
    out << "orientation_x: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_x, out);
    out << ", ";
  }

  // member: orientation_y
  {
    out << "orientation_y: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_y, out);
    out << ", ";
  }

  // member: orientation_z
  {
    out << "orientation_z: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_z, out);
    out << ", ";
  }

  // member: orientation_w
  {
    out << "orientation_w: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_w, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: goal_id
  {
    out << "goal_id: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: text
  {
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RoverGoalStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: orientation_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_x: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_x, out);
    out << "\n";
  }

  // member: orientation_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_y: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_y, out);
    out << "\n";
  }

  // member: orientation_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_z: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_z, out);
    out << "\n";
  }

  // member: orientation_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_w: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_w, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_id, out);
    out << "\n";
  }

  // member: text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RoverGoalStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rover_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rover_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rover_msgs::msg::RoverGoalStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  rover_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rover_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rover_msgs::msg::RoverGoalStatus & msg)
{
  return rover_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rover_msgs::msg::RoverGoalStatus>()
{
  return "rover_msgs::msg::RoverGoalStatus";
}

template<>
inline const char * name<rover_msgs::msg::RoverGoalStatus>()
{
  return "rover_msgs/msg/RoverGoalStatus";
}

template<>
struct has_fixed_size<rover_msgs::msg::RoverGoalStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rover_msgs::msg::RoverGoalStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rover_msgs::msg::RoverGoalStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__TRAITS_HPP_
