// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from camera_app_msgs:srv/Capture.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__TRAITS_HPP_
#define CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "camera_app_msgs/srv/detail/capture__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace camera_app_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Capture_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cam
  {
    out << "cam: ";
    rosidl_generator_traits::value_to_yaml(msg.cam, out);
    out << ", ";
  }

  // member: rec
  {
    out << "rec: ";
    rosidl_generator_traits::value_to_yaml(msg.rec, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Capture_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cam
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cam: ";
    rosidl_generator_traits::value_to_yaml(msg.cam, out);
    out << "\n";
  }

  // member: rec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rec: ";
    rosidl_generator_traits::value_to_yaml(msg.rec, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Capture_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace camera_app_msgs

namespace rosidl_generator_traits
{

[[deprecated("use camera_app_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const camera_app_msgs::srv::Capture_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  camera_app_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use camera_app_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const camera_app_msgs::srv::Capture_Request & msg)
{
  return camera_app_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<camera_app_msgs::srv::Capture_Request>()
{
  return "camera_app_msgs::srv::Capture_Request";
}

template<>
inline const char * name<camera_app_msgs::srv::Capture_Request>()
{
  return "camera_app_msgs/srv/Capture_Request";
}

template<>
struct has_fixed_size<camera_app_msgs::srv::Capture_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<camera_app_msgs::srv::Capture_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<camera_app_msgs::srv::Capture_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace camera_app_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Capture_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Capture_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Capture_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace camera_app_msgs

namespace rosidl_generator_traits
{

[[deprecated("use camera_app_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const camera_app_msgs::srv::Capture_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  camera_app_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use camera_app_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const camera_app_msgs::srv::Capture_Response & msg)
{
  return camera_app_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<camera_app_msgs::srv::Capture_Response>()
{
  return "camera_app_msgs::srv::Capture_Response";
}

template<>
inline const char * name<camera_app_msgs::srv::Capture_Response>()
{
  return "camera_app_msgs/srv/Capture_Response";
}

template<>
struct has_fixed_size<camera_app_msgs::srv::Capture_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<camera_app_msgs::srv::Capture_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<camera_app_msgs::srv::Capture_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<camera_app_msgs::srv::Capture>()
{
  return "camera_app_msgs::srv::Capture";
}

template<>
inline const char * name<camera_app_msgs::srv::Capture>()
{
  return "camera_app_msgs/srv/Capture";
}

template<>
struct has_fixed_size<camera_app_msgs::srv::Capture>
  : std::integral_constant<
    bool,
    has_fixed_size<camera_app_msgs::srv::Capture_Request>::value &&
    has_fixed_size<camera_app_msgs::srv::Capture_Response>::value
  >
{
};

template<>
struct has_bounded_size<camera_app_msgs::srv::Capture>
  : std::integral_constant<
    bool,
    has_bounded_size<camera_app_msgs::srv::Capture_Request>::value &&
    has_bounded_size<camera_app_msgs::srv::Capture_Response>::value
  >
{
};

template<>
struct is_service<camera_app_msgs::srv::Capture>
  : std::true_type
{
};

template<>
struct is_service_request<camera_app_msgs::srv::Capture_Request>
  : std::true_type
{
};

template<>
struct is_service_response<camera_app_msgs::srv::Capture_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__TRAITS_HPP_
