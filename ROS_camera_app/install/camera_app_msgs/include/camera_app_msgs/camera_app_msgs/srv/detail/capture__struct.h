// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from camera_app_msgs:srv/Capture.idl
// generated code does not contain a copyright notice

#ifndef CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__STRUCT_H_
#define CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Capture in the package camera_app_msgs.
typedef struct camera_app_msgs__srv__Capture_Request
{
  int32_t cam;
  int32_t rec;
} camera_app_msgs__srv__Capture_Request;

// Struct for a sequence of camera_app_msgs__srv__Capture_Request.
typedef struct camera_app_msgs__srv__Capture_Request__Sequence
{
  camera_app_msgs__srv__Capture_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera_app_msgs__srv__Capture_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Capture in the package camera_app_msgs.
typedef struct camera_app_msgs__srv__Capture_Response
{
  uint8_t structure_needs_at_least_one_member;
} camera_app_msgs__srv__Capture_Response;

// Struct for a sequence of camera_app_msgs__srv__Capture_Response.
typedef struct camera_app_msgs__srv__Capture_Response__Sequence
{
  camera_app_msgs__srv__Capture_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera_app_msgs__srv__Capture_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMERA_APP_MSGS__SRV__DETAIL__CAPTURE__STRUCT_H_
