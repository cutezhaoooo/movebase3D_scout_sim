// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rover_msgs:msg/RoverRCStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__TRAITS_HPP_
#define ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rover_msgs/msg/detail/rover_rc_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rover_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RoverRCStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: connect
  {
    out << "connect: ";
    rosidl_generator_traits::value_to_yaml(msg.connect, out);
    out << ", ";
  }

  // member: ch1
  {
    out << "ch1: ";
    rosidl_generator_traits::value_to_yaml(msg.ch1, out);
    out << ", ";
  }

  // member: ch2
  {
    out << "ch2: ";
    rosidl_generator_traits::value_to_yaml(msg.ch2, out);
    out << ", ";
  }

  // member: ch3
  {
    out << "ch3: ";
    rosidl_generator_traits::value_to_yaml(msg.ch3, out);
    out << ", ";
  }

  // member: ch4
  {
    out << "ch4: ";
    rosidl_generator_traits::value_to_yaml(msg.ch4, out);
    out << ", ";
  }

  // member: ch5
  {
    out << "ch5: ";
    rosidl_generator_traits::value_to_yaml(msg.ch5, out);
    out << ", ";
  }

  // member: ch6
  {
    out << "ch6: ";
    rosidl_generator_traits::value_to_yaml(msg.ch6, out);
    out << ", ";
  }

  // member: ch7
  {
    out << "ch7: ";
    rosidl_generator_traits::value_to_yaml(msg.ch7, out);
    out << ", ";
  }

  // member: ch8
  {
    out << "ch8: ";
    rosidl_generator_traits::value_to_yaml(msg.ch8, out);
    out << ", ";
  }

  // member: ch9
  {
    out << "ch9: ";
    rosidl_generator_traits::value_to_yaml(msg.ch9, out);
    out << ", ";
  }

  // member: ch10
  {
    out << "ch10: ";
    rosidl_generator_traits::value_to_yaml(msg.ch10, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RoverRCStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: connect
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connect: ";
    rosidl_generator_traits::value_to_yaml(msg.connect, out);
    out << "\n";
  }

  // member: ch1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch1: ";
    rosidl_generator_traits::value_to_yaml(msg.ch1, out);
    out << "\n";
  }

  // member: ch2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch2: ";
    rosidl_generator_traits::value_to_yaml(msg.ch2, out);
    out << "\n";
  }

  // member: ch3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch3: ";
    rosidl_generator_traits::value_to_yaml(msg.ch3, out);
    out << "\n";
  }

  // member: ch4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch4: ";
    rosidl_generator_traits::value_to_yaml(msg.ch4, out);
    out << "\n";
  }

  // member: ch5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch5: ";
    rosidl_generator_traits::value_to_yaml(msg.ch5, out);
    out << "\n";
  }

  // member: ch6
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch6: ";
    rosidl_generator_traits::value_to_yaml(msg.ch6, out);
    out << "\n";
  }

  // member: ch7
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch7: ";
    rosidl_generator_traits::value_to_yaml(msg.ch7, out);
    out << "\n";
  }

  // member: ch8
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch8: ";
    rosidl_generator_traits::value_to_yaml(msg.ch8, out);
    out << "\n";
  }

  // member: ch9
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch9: ";
    rosidl_generator_traits::value_to_yaml(msg.ch9, out);
    out << "\n";
  }

  // member: ch10
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ch10: ";
    rosidl_generator_traits::value_to_yaml(msg.ch10, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RoverRCStatus & msg, bool use_flow_style = false)
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
  const rover_msgs::msg::RoverRCStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  rover_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rover_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rover_msgs::msg::RoverRCStatus & msg)
{
  return rover_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rover_msgs::msg::RoverRCStatus>()
{
  return "rover_msgs::msg::RoverRCStatus";
}

template<>
inline const char * name<rover_msgs::msg::RoverRCStatus>()
{
  return "rover_msgs/msg/RoverRCStatus";
}

template<>
struct has_fixed_size<rover_msgs::msg::RoverRCStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<rover_msgs::msg::RoverRCStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<rover_msgs::msg::RoverRCStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__TRAITS_HPP_
