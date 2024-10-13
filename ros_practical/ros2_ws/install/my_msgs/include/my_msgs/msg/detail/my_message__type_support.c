// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_msgs:msg/MyMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_msgs/msg/detail/my_message__rosidl_typesupport_introspection_c.h"
#include "my_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_msgs/msg/detail/my_message__functions.h"
#include "my_msgs/msg/detail/my_message__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `some_vector`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MyMessage__rosidl_typesupport_introspection_c__MyMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_msgs__msg__MyMessage__init(message_memory);
}

void MyMessage__rosidl_typesupport_introspection_c__MyMessage_fini_function(void * message_memory)
{
  my_msgs__msg__MyMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_member_array[3] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgs__msg__MyMessage, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "some_integer",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgs__msg__MyMessage, some_integer),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "some_vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgs__msg__MyMessage, some_vector),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_members = {
  "my_msgs__msg",  // message namespace
  "MyMessage",  // message name
  3,  // number of fields
  sizeof(my_msgs__msg__MyMessage),
  MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_member_array,  // message members
  MyMessage__rosidl_typesupport_introspection_c__MyMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MyMessage__rosidl_typesupport_introspection_c__MyMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_type_support_handle = {
  0,
  &MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_msgs, msg, MyMessage)() {
  if (!MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_type_support_handle.typesupport_identifier) {
    MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MyMessage__rosidl_typesupport_introspection_c__MyMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
