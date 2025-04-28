// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rover_msgs:msg/RoverBmsStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__STRUCT_H_
#define ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__STRUCT_H_

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

/// Struct defined in msg/RoverBmsStatus in the package rover_msgs.
typedef struct rover_msgs__msg__RoverBmsStatus
{
  std_msgs__msg__Header header;
  uint8_t percentage;
  double voltage;
  double current;
  double temperature;
} rover_msgs__msg__RoverBmsStatus;

// Struct for a sequence of rover_msgs__msg__RoverBmsStatus.
typedef struct rover_msgs__msg__RoverBmsStatus__Sequence
{
  rover_msgs__msg__RoverBmsStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rover_msgs__msg__RoverBmsStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_BMS_STATUS__STRUCT_H_
