// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_msgs:msg/MyMessage.idl
// generated code does not contain a copyright notice

#ifndef MY_MSGS__MSG__DETAIL__MY_MESSAGE__BUILDER_HPP_
#define MY_MSGS__MSG__DETAIL__MY_MESSAGE__BUILDER_HPP_

#include "my_msgs/msg/detail/my_message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace my_msgs
{

namespace msg
{

namespace builder
{

class Init_MyMessage_some_vector
{
public:
  explicit Init_MyMessage_some_vector(::my_msgs::msg::MyMessage & msg)
  : msg_(msg)
  {}
  ::my_msgs::msg::MyMessage some_vector(::my_msgs::msg::MyMessage::_some_vector_type arg)
  {
    msg_.some_vector = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_msgs::msg::MyMessage msg_;
};

class Init_MyMessage_some_integer
{
public:
  explicit Init_MyMessage_some_integer(::my_msgs::msg::MyMessage & msg)
  : msg_(msg)
  {}
  Init_MyMessage_some_vector some_integer(::my_msgs::msg::MyMessage::_some_integer_type arg)
  {
    msg_.some_integer = std::move(arg);
    return Init_MyMessage_some_vector(msg_);
  }

private:
  ::my_msgs::msg::MyMessage msg_;
};

class Init_MyMessage_name
{
public:
  Init_MyMessage_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyMessage_some_integer name(::my_msgs::msg::MyMessage::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_MyMessage_some_integer(msg_);
  }

private:
  ::my_msgs::msg::MyMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_msgs::msg::MyMessage>()
{
  return my_msgs::msg::builder::Init_MyMessage_name();
}

}  // namespace my_msgs

#endif  // MY_MSGS__MSG__DETAIL__MY_MESSAGE__BUILDER_HPP_
