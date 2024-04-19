// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from camera_app_msgs:srv/Capture.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__BUILDER_HPP_
#define CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "camera_app_msgs/srv/detail/capture__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace camera_app_msgs
{

namespace srv
{

namespace builder
{

class Init_Capture_Request_rec
{
public:
  explicit Init_Capture_Request_rec(::camera_app_msgs::srv::Capture_Request & msg)
  : msg_(msg)
  {}
  ::camera_app_msgs::srv::Capture_Request rec(::camera_app_msgs::srv::Capture_Request::_rec_type arg)
  {
    msg_.rec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::camera_app_msgs::srv::Capture_Request msg_;
};

class Init_Capture_Request_cam
{
public:
  Init_Capture_Request_cam()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Capture_Request_rec cam(::camera_app_msgs::srv::Capture_Request::_cam_type arg)
  {
    msg_.cam = std::move(arg);
    return Init_Capture_Request_rec(msg_);
  }

private:
  ::camera_app_msgs::srv::Capture_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera_app_msgs::srv::Capture_Request>()
{
  return camera_app_msgs::srv::builder::Init_Capture_Request_cam();
}

}  // namespace camera_app_msgs


namespace camera_app_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera_app_msgs::srv::Capture_Response>()
{
  return ::camera_app_msgs::srv::Capture_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace camera_app_msgs

#endif  // CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__BUILDER_HPP_
