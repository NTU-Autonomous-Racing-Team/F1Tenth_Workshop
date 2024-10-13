// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_msgs:msg/MyMessage.idl
// generated code does not contain a copyright notice

#ifndef MY_MSGS__MSG__DETAIL__MY_MESSAGE__STRUCT_H_
#define MY_MSGS__MSG__DETAIL__MY_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'some_vector'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/MyMessage in the package my_msgs.
typedef struct my_msgs__msg__MyMessage
{
  rosidl_runtime_c__String name;
  int32_t some_integer;
  rosidl_runtime_c__int32__Sequence some_vector;
} my_msgs__msg__MyMessage;

// Struct for a sequence of my_msgs__msg__MyMessage.
typedef struct my_msgs__msg__MyMessage__Sequence
{
  my_msgs__msg__MyMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_msgs__msg__MyMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MSGS__MSG__DETAIL__MY_MESSAGE__STRUCT_H_
