// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rover_msgs:msg/RoverRCStatus.idl
// generated code does not contain a copyright notice
#include "rover_msgs/msg/detail/rover_rc_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
rover_msgs__msg__RoverRCStatus__init(rover_msgs__msg__RoverRCStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rover_msgs__msg__RoverRCStatus__fini(msg);
    return false;
  }
  // connect
  // ch1
  // ch2
  // ch3
  // ch4
  // ch5
  // ch6
  // ch7
  // ch8
  // ch9
  // ch10
  return true;
}

void
rover_msgs__msg__RoverRCStatus__fini(rover_msgs__msg__RoverRCStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // connect
  // ch1
  // ch2
  // ch3
  // ch4
  // ch5
  // ch6
  // ch7
  // ch8
  // ch9
  // ch10
}

bool
rover_msgs__msg__RoverRCStatus__are_equal(const rover_msgs__msg__RoverRCStatus * lhs, const rover_msgs__msg__RoverRCStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // connect
  if (lhs->connect != rhs->connect) {
    return false;
  }
  // ch1
  if (lhs->ch1 != rhs->ch1) {
    return false;
  }
  // ch2
  if (lhs->ch2 != rhs->ch2) {
    return false;
  }
  // ch3
  if (lhs->ch3 != rhs->ch3) {
    return false;
  }
  // ch4
  if (lhs->ch4 != rhs->ch4) {
    return false;
  }
  // ch5
  if (lhs->ch5 != rhs->ch5) {
    return false;
  }
  // ch6
  if (lhs->ch6 != rhs->ch6) {
    return false;
  }
  // ch7
  if (lhs->ch7 != rhs->ch7) {
    return false;
  }
  // ch8
  if (lhs->ch8 != rhs->ch8) {
    return false;
  }
  // ch9
  if (lhs->ch9 != rhs->ch9) {
    return false;
  }
  // ch10
  if (lhs->ch10 != rhs->ch10) {
    return false;
  }
  return true;
}

bool
rover_msgs__msg__RoverRCStatus__copy(
  const rover_msgs__msg__RoverRCStatus * input,
  rover_msgs__msg__RoverRCStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // connect
  output->connect = input->connect;
  // ch1
  output->ch1 = input->ch1;
  // ch2
  output->ch2 = input->ch2;
  // ch3
  output->ch3 = input->ch3;
  // ch4
  output->ch4 = input->ch4;
  // ch5
  output->ch5 = input->ch5;
  // ch6
  output->ch6 = input->ch6;
  // ch7
  output->ch7 = input->ch7;
  // ch8
  output->ch8 = input->ch8;
  // ch9
  output->ch9 = input->ch9;
  // ch10
  output->ch10 = input->ch10;
  return true;
}

rover_msgs__msg__RoverRCStatus *
rover_msgs__msg__RoverRCStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverRCStatus * msg = (rover_msgs__msg__RoverRCStatus *)allocator.allocate(sizeof(rover_msgs__msg__RoverRCStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rover_msgs__msg__RoverRCStatus));
  bool success = rover_msgs__msg__RoverRCStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rover_msgs__msg__RoverRCStatus__destroy(rover_msgs__msg__RoverRCStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rover_msgs__msg__RoverRCStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rover_msgs__msg__RoverRCStatus__Sequence__init(rover_msgs__msg__RoverRCStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverRCStatus * data = NULL;

  if (size) {
    data = (rover_msgs__msg__RoverRCStatus *)allocator.zero_allocate(size, sizeof(rover_msgs__msg__RoverRCStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rover_msgs__msg__RoverRCStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rover_msgs__msg__RoverRCStatus__fini(&data[i - 1]);
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
rover_msgs__msg__RoverRCStatus__Sequence__fini(rover_msgs__msg__RoverRCStatus__Sequence * array)
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
      rover_msgs__msg__RoverRCStatus__fini(&array->data[i]);
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

rover_msgs__msg__RoverRCStatus__Sequence *
rover_msgs__msg__RoverRCStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverRCStatus__Sequence * array = (rover_msgs__msg__RoverRCStatus__Sequence *)allocator.allocate(sizeof(rover_msgs__msg__RoverRCStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rover_msgs__msg__RoverRCStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rover_msgs__msg__RoverRCStatus__Sequence__destroy(rover_msgs__msg__RoverRCStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rover_msgs__msg__RoverRCStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rover_msgs__msg__RoverRCStatus__Sequence__are_equal(const rover_msgs__msg__RoverRCStatus__Sequence * lhs, const rover_msgs__msg__RoverRCStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rover_msgs__msg__RoverRCStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rover_msgs__msg__RoverRCStatus__Sequence__copy(
  const rover_msgs__msg__RoverRCStatus__Sequence * input,
  rover_msgs__msg__RoverRCStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rover_msgs__msg__RoverRCStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rover_msgs__msg__RoverRCStatus * data =
      (rover_msgs__msg__RoverRCStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rover_msgs__msg__RoverRCStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rover_msgs__msg__RoverRCStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rover_msgs__msg__RoverRCStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
