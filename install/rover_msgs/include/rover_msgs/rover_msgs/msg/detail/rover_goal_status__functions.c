// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rover_msgs:msg/RoverGoalStatus.idl
// generated code does not contain a copyright notice
#include "rover_msgs/msg/detail/rover_goal_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `text`
#include "rosidl_runtime_c/string_functions.h"

bool
rover_msgs__msg__RoverGoalStatus__init(rover_msgs__msg__RoverGoalStatus * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // orientation_x
  // orientation_y
  // orientation_z
  // orientation_w
  // status
  // goal_id
  // text
  if (!rosidl_runtime_c__String__init(&msg->text)) {
    rover_msgs__msg__RoverGoalStatus__fini(msg);
    return false;
  }
  return true;
}

void
rover_msgs__msg__RoverGoalStatus__fini(rover_msgs__msg__RoverGoalStatus * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // orientation_x
  // orientation_y
  // orientation_z
  // orientation_w
  // status
  // goal_id
  // text
  rosidl_runtime_c__String__fini(&msg->text);
}

bool
rover_msgs__msg__RoverGoalStatus__are_equal(const rover_msgs__msg__RoverGoalStatus * lhs, const rover_msgs__msg__RoverGoalStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // orientation_x
  if (lhs->orientation_x != rhs->orientation_x) {
    return false;
  }
  // orientation_y
  if (lhs->orientation_y != rhs->orientation_y) {
    return false;
  }
  // orientation_z
  if (lhs->orientation_z != rhs->orientation_z) {
    return false;
  }
  // orientation_w
  if (lhs->orientation_w != rhs->orientation_w) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // goal_id
  if (lhs->goal_id != rhs->goal_id) {
    return false;
  }
  // text
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->text), &(rhs->text)))
  {
    return false;
  }
  return true;
}

bool
rover_msgs__msg__RoverGoalStatus__copy(
  const rover_msgs__msg__RoverGoalStatus * input,
  rover_msgs__msg__RoverGoalStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // orientation_x
  output->orientation_x = input->orientation_x;
  // orientation_y
  output->orientation_y = input->orientation_y;
  // orientation_z
  output->orientation_z = input->orientation_z;
  // orientation_w
  output->orientation_w = input->orientation_w;
  // status
  output->status = input->status;
  // goal_id
  output->goal_id = input->goal_id;
  // text
  if (!rosidl_runtime_c__String__copy(
      &(input->text), &(output->text)))
  {
    return false;
  }
  return true;
}

rover_msgs__msg__RoverGoalStatus *
rover_msgs__msg__RoverGoalStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverGoalStatus * msg = (rover_msgs__msg__RoverGoalStatus *)allocator.allocate(sizeof(rover_msgs__msg__RoverGoalStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rover_msgs__msg__RoverGoalStatus));
  bool success = rover_msgs__msg__RoverGoalStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rover_msgs__msg__RoverGoalStatus__destroy(rover_msgs__msg__RoverGoalStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rover_msgs__msg__RoverGoalStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rover_msgs__msg__RoverGoalStatus__Sequence__init(rover_msgs__msg__RoverGoalStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverGoalStatus * data = NULL;

  if (size) {
    data = (rover_msgs__msg__RoverGoalStatus *)allocator.zero_allocate(size, sizeof(rover_msgs__msg__RoverGoalStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rover_msgs__msg__RoverGoalStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rover_msgs__msg__RoverGoalStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rover_msgs__msg__RoverGoalStatus__Sequence__fini(rover_msgs__msg__RoverGoalStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rover_msgs__msg__RoverGoalStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rover_msgs__msg__RoverGoalStatus__Sequence *
rover_msgs__msg__RoverGoalStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverGoalStatus__Sequence * array = (rover_msgs__msg__RoverGoalStatus__Sequence *)allocator.allocate(sizeof(rover_msgs__msg__RoverGoalStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rover_msgs__msg__RoverGoalStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rover_msgs__msg__RoverGoalStatus__Sequence__destroy(rover_msgs__msg__RoverGoalStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rover_msgs__msg__RoverGoalStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rover_msgs__msg__RoverGoalStatus__Sequence__are_equal(const rover_msgs__msg__RoverGoalStatus__Sequence * lhs, const rover_msgs__msg__RoverGoalStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rover_msgs__msg__RoverGoalStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rover_msgs__msg__RoverGoalStatus__Sequence__copy(
  const rover_msgs__msg__RoverGoalStatus__Sequence * input,
  rover_msgs__msg__RoverGoalStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rover_msgs__msg__RoverGoalStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rover_msgs__msg__RoverGoalStatus * data =
      (rover_msgs__msg__RoverGoalStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rover_msgs__msg__RoverGoalStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rover_msgs__msg__RoverGoalStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rover_msgs__msg__RoverGoalStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
