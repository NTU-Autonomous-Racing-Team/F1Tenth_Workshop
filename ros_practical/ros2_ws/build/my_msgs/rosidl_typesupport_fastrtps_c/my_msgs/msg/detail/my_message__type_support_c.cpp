// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_msgs:msg/MyMessage.idl
// generated code does not contain a copyright notice
#include "my_msgs/msg/detail/my_message__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_msgs/msg/detail/my_message__struct.h"
#include "my_msgs/msg/detail/my_message__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // some_vector
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // some_vector
#include "rosidl_runtime_c/string.h"  // name
#include "rosidl_runtime_c/string_functions.h"  // name

// forward declare type support functions


using _MyMessage__ros_msg_type = my_msgs__msg__MyMessage;

static bool _MyMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MyMessage__ros_msg_type * ros_message = static_cast<const _MyMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: some_integer
  {
    cdr << ros_message->some_integer;
  }

  // Field name: some_vector
  {
    size_t size = ros_message->some_vector.size;
    auto array_ptr = ros_message->some_vector.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _MyMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MyMessage__ros_msg_type * ros_message = static_cast<_MyMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: some_integer
  {
    cdr >> ros_message->some_integer;
  }

  // Field name: some_vector
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->some_vector.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->some_vector);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->some_vector, size)) {
      return "failed to create array for field 'some_vector'";
    }
    auto array_ptr = ros_message->some_vector.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_msgs
size_t get_serialized_size_my_msgs__msg__MyMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MyMessage__ros_msg_type * ros_message = static_cast<const _MyMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name some_integer
  {
    size_t item_size = sizeof(ros_message->some_integer);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name some_vector
  {
    size_t array_size = ros_message->some_vector.size;
    auto array_ptr = ros_message->some_vector.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MyMessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_msgs__msg__MyMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_msgs
size_t max_serialized_size_my_msgs__msg__MyMessage(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: some_integer
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: some_vector
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _MyMessage__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_my_msgs__msg__MyMessage(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MyMessage = {
  "my_msgs::msg",
  "MyMessage",
  _MyMessage__cdr_serialize,
  _MyMessage__cdr_deserialize,
  _MyMessage__get_serialized_size,
  _MyMessage__max_serialized_size
};

static rosidl_message_type_support_t _MyMessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MyMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_msgs, msg, MyMessage)() {
  return &_MyMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
