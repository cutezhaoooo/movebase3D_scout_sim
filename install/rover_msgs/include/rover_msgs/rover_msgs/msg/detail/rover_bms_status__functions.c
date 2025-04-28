// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rover_msgs:msg/RoverBmsStatus.idl
// generated code does not contain a copyright notice
#include "rover_msgs/msg/detail/rover_bms_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
rover_msgs__msg__RoverBmsStatus__init(rover_msgs__msg__RoverBmsStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rover_msgs__msg__RoverBmsStatus__fini(msg);
    return false;
  }
  // percentage
  // voltage
  // current
  // temperature
  return true;
}

void
rover_msgs__msg__RoverBmsStatus__fini(rover_msgs__msg__RoverBmsStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // percentage
  // voltage
  // current
  // temperature
}

bool
rover_msgs__msg__RoverBmsStatus__are_equal(const rover_msgs__msg__RoverBmsStatus * lhs, const rover_msgs__msg__RoverBmsStatus * rhs)
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
  // percentage
  if (lhs->percentage != rhs->percentage) {
    return false;
  }
  // voltage
  if (lhs->voltage != rhs->voltage) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  return true;
}

bool
rover_msgs__msg__RoverBmsStatus__copy(
  const rover_msgs__msg__RoverBmsStatus * input,
  rover_msgs__msg__RoverBmsStatus * output)
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
  // percentage
  output->percentage = input->percentage;
  // voltage
  output->voltage = input->voltage;
  // current
  output->current = input->current;
  // temperature
  output->temperature = input->temperature;
  return true;
}

rover_msgs__msg__RoverBmsStatus *
rover_msgs__msg__RoverBmsStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverBmsStatus * msg = (rover_msgs__msg__RoverBmsStatus *)allocator.allocate(sizeof(rover_msgs__msg__RoverBmsStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rover_msgs__msg__RoverBmsStatus));
  bool success = rover_msgs__msg__RoverBmsStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rover_msgs__msg__RoverBmsStatus__destroy(rover_msgs__msg__RoverBmsStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rover_msgs__msg__RoverBmsStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rover_msgs__msg__RoverBmsStatus__Sequence__init(rover_msgs__msg__RoverBmsStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverBmsStatus * data = NULL;

  if (size) {
    data = (rover_msgs__msg__RoverBmsStatus *)allocator.zero_allocate(size, sizeof(rover_msgs__msg__RoverBmsStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rover_msgs__msg__RoverBmsStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rover_msgs__msg__RoverBmsStatus__fini(&data[i - 1]);
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
rover_msgs__msg__RoverBmsStatus__Sequence__fini(rover_msgs__msg__RoverBmsStatus__Sequence * array)
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
      rover_msgs__msg__RoverBmsStatus__fini(&array->data[i]);
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

rover_msgs__msg__RoverBmsStatus__Sequence *
rover_msgs__msg__RoverBmsStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rover_msgs__msg__RoverBmsStatus__Sequence * array = (rover_msgs__msg__RoverBmsStatus__Sequence *)allocator.allocate(sizeof(rover_msgs__msg__RoverBmsStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rover_msgs__msg__RoverBmsStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rover_msgs__msg__RoverBmsStatus__Sequence__destroy(rover_msgs__msg__RoverBmsStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rover_msgs__msg__RoverBmsStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rover_msgs__msg__RoverBmsStatus__Sequence__are_equal(const rover_msgs__msg__RoverBmsStatus__Sequence * lhs, const rover_msgs__msg__RoverBmsStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rover_msgs__msg__RoverBmsStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rover_msgs__msg__RoverBmsStatus__Sequence__copy(
  const rover_msgs__msg__RoverBmsStatus__Sequence * input,
  rover_msgs__msg__RoverBmsStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rover_msgs__msg__RoverBmsStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rover_msgs__msg__RoverBmsStatus * data =
      (rover_msgs__msg__RoverBmsStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rover_msgs__msg__RoverBmsStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rover_msgs__msg__RoverBmsStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rover_msgs__msg__RoverBmsStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
