// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_msgs:msg/MyMessage.idl
// generated code does not contain a copyright notice
#include "my_msgs/msg/detail/my_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `some_vector`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
my_msgs__msg__MyMessage__init(my_msgs__msg__MyMessage * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    my_msgs__msg__MyMessage__fini(msg);
    return false;
  }
  // some_integer
  // some_vector
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->some_vector, 0)) {
    my_msgs__msg__MyMessage__fini(msg);
    return false;
  }
  return true;
}

void
my_msgs__msg__MyMessage__fini(my_msgs__msg__MyMessage * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // some_integer
  // some_vector
  rosidl_runtime_c__int32__Sequence__fini(&msg->some_vector);
}

bool
my_msgs__msg__MyMessage__are_equal(const my_msgs__msg__MyMessage * lhs, const my_msgs__msg__MyMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // some_integer
  if (lhs->some_integer != rhs->some_integer) {
    return false;
  }
  // some_vector
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->some_vector), &(rhs->some_vector)))
  {
    return false;
  }
  return true;
}

bool
my_msgs__msg__MyMessage__copy(
  const my_msgs__msg__MyMessage * input,
  my_msgs__msg__MyMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // some_integer
  output->some_integer = input->some_integer;
  // some_vector
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->some_vector), &(output->some_vector)))
  {
    return false;
  }
  return true;
}

my_msgs__msg__MyMessage *
my_msgs__msg__MyMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msgs__msg__MyMessage * msg = (my_msgs__msg__MyMessage *)allocator.allocate(sizeof(my_msgs__msg__MyMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_msgs__msg__MyMessage));
  bool success = my_msgs__msg__MyMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_msgs__msg__MyMessage__destroy(my_msgs__msg__MyMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_msgs__msg__MyMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_msgs__msg__MyMessage__Sequence__init(my_msgs__msg__MyMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msgs__msg__MyMessage * data = NULL;

  if (size) {
    data = (my_msgs__msg__MyMessage *)allocator.zero_allocate(size, sizeof(my_msgs__msg__MyMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_msgs__msg__MyMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_msgs__msg__MyMessage__fini(&data[i - 1]);
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
my_msgs__msg__MyMessage__Sequence__fini(my_msgs__msg__MyMessage__Sequence * array)
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
      my_msgs__msg__MyMessage__fini(&array->data[i]);
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

my_msgs__msg__MyMessage__Sequence *
my_msgs__msg__MyMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msgs__msg__MyMessage__Sequence * array = (my_msgs__msg__MyMessage__Sequence *)allocator.allocate(sizeof(my_msgs__msg__MyMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_msgs__msg__MyMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_msgs__msg__MyMessage__Sequence__destroy(my_msgs__msg__MyMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_msgs__msg__MyMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_msgs__msg__MyMessage__Sequence__are_equal(const my_msgs__msg__MyMessage__Sequence * lhs, const my_msgs__msg__MyMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_msgs__msg__MyMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_msgs__msg__MyMessage__Sequence__copy(
  const my_msgs__msg__MyMessage__Sequence * input,
  my_msgs__msg__MyMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_msgs__msg__MyMessage);
    my_msgs__msg__MyMessage * data =
      (my_msgs__msg__MyMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_msgs__msg__MyMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          my_msgs__msg__MyMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_msgs__msg__MyMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
