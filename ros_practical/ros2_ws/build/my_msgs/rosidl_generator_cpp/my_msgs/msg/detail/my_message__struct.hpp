// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_msgs:msg/MyMessage.idl
// generated code does not contain a copyright notice

#ifndef MY_MSGS__MSG__DETAIL__MY_MESSAGE__STRUCT_HPP_
#define MY_MSGS__MSG__DETAIL__MY_MESSAGE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__my_msgs__msg__MyMessage __attribute__((deprecated))
#else
# define DEPRECATED__my_msgs__msg__MyMessage __declspec(deprecated)
#endif

namespace my_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyMessage_
{
  using Type = MyMessage_<ContainerAllocator>;

  explicit MyMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->some_integer = 0l;
    }
  }

  explicit MyMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->some_integer = 0l;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _some_integer_type =
    int32_t;
  _some_integer_type some_integer;
  using _some_vector_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _some_vector_type some_vector;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__some_integer(
    const int32_t & _arg)
  {
    this->some_integer = _arg;
    return *this;
  }
  Type & set__some_vector(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->some_vector = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_msgs::msg::MyMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_msgs::msg::MyMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_msgs::msg::MyMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_msgs::msg::MyMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_msgs::msg::MyMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_msgs::msg::MyMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_msgs::msg::MyMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_msgs::msg::MyMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_msgs::msg::MyMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_msgs::msg::MyMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_msgs__msg__MyMessage
    std::shared_ptr<my_msgs::msg::MyMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_msgs__msg__MyMessage
    std::shared_ptr<my_msgs::msg::MyMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyMessage_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->some_integer != other.some_integer) {
      return false;
    }
    if (this->some_vector != other.some_vector) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyMessage_

// alias to use template instance with default allocator
using MyMessage =
  my_msgs::msg::MyMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_msgs

#endif  // MY_MSGS__MSG__DETAIL__MY_MESSAGE__STRUCT_HPP_
