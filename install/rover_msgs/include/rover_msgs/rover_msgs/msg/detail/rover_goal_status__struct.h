// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rover_msgs:msg/RoverGoalStatus.idl
// generated code does not contain a copyright notice

#ifndef ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__STRUCT_H_
#define ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PENDING'.
enum
{
  rover_msgs__msg__RoverGoalStatus__PENDING = 0
};

/// Constant 'ACTIVE'.
enum
{
  rover_msgs__msg__RoverGoalStatus__ACTIVE = 1
};

/// Constant 'PREEMPTED'.
enum
{
  rover_msgs__msg__RoverGoalStatus__PREEMPTED = 2
};

/// Constant 'SUCCEEDED'.
enum
{
  rover_msgs__msg__RoverGoalStatus__SUCCEEDED = 3
};

/// Constant 'ABORTED'.
enum
{
  rover_msgs__msg__RoverGoalStatus__ABORTED = 4
};

/// Constant 'REJECTED'.
enum
{
  rover_msgs__msg__RoverGoalStatus__REJECTED = 5
};

/// Constant 'PREEMPTING'.
enum
{
  rover_msgs__msg__RoverGoalStatus__PREEMPTING = 6
};

/// Constant 'RECALLING'.
enum
{
  rover_msgs__msg__RoverGoalStatus__RECALLING = 7
};

/// Constant 'RECALLED'.
enum
{
  rover_msgs__msg__RoverGoalStatus__RECALLED = 8
};

/// Constant 'LOST'.
enum
{
  rover_msgs__msg__RoverGoalStatus__LOST = 9
};

// Include directives for member types
// Member 'text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RoverGoalStatus in the package rover_msgs.
typedef struct rover_msgs__msg__RoverGoalStatus
{
  double x;
  double y;
  double z;
  double orientation_x;
  double orientation_y;
  double orientation_z;
  double orientation_w;
  uint8_t status;
  uint8_t goal_id;
  rosidl_runtime_c__String text;
} rover_msgs__msg__RoverGoalStatus;

// Struct for a sequence of rover_msgs__msg__RoverGoalStatus.
typedef struct rover_msgs__msg__RoverGoalStatus__Sequence
{
  rover_msgs__msg__RoverGoalStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rover_msgs__msg__RoverGoalStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROVER_MSGS__MSG__DETAIL__ROVER_GOAL_STATUS__STRUCT_H_
