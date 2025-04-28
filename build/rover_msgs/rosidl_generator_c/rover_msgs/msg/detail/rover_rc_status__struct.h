// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rover_msgs:msg/RoverRCStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__STRUCT_H_
#define ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/RoverRCStatus in the package rover_msgs.
typedef struct rover_msgs__msg__RoverRCStatus
{
  std_msgs__msg__Header header;
  bool connect;
  int8_t ch1;
  int8_t ch2;
  int8_t ch3;
  int8_t ch4;
  int8_t ch5;
  int8_t ch6;
  int8_t ch7;
  int8_t ch8;
  int8_t ch9;
  int8_t ch10;
} rover_msgs__msg__RoverRCStatus;

// Struct for a sequence of rover_msgs__msg__RoverRCStatus.
typedef struct rover_msgs__msg__RoverRCStatus__Sequence
{
  rover_msgs__msg__RoverRCStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rover_msgs__msg__RoverRCStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_RC_STATUS__STRUCT_H_
