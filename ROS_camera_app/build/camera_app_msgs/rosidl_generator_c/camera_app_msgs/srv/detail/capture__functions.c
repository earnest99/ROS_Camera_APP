// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from camera_app_msgs:srv/Capture.idl
// generated code does not contain a copyright notice
#include "camera_app_msgs/srv/detail/capture__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
camera_app_msgs__srv__Capture_Request__init(camera_app_msgs__srv__Capture_Request * msg)
{
  if (!msg) {
    return false;
  }
  // cam
  // rec
  return true;
}

void
camera_app_msgs__srv__Capture_Request__fini(camera_app_msgs__srv__Capture_Request * msg)
{
  if (!msg) {
    return;
  }
  // cam
  // rec
}

bool
camera_app_msgs__srv__Capture_Request__are_equal(const camera_app_msgs__srv__Capture_Request * lhs, const camera_app_msgs__srv__Capture_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cam
  if (lhs->cam != rhs->cam) {
    return false;
  }
  // rec
  if (lhs->rec != rhs->rec) {
    return false;
  }
  return true;
}

bool
camera_app_msgs__srv__Capture_Request__copy(
  const camera_app_msgs__srv__Capture_Request * input,
  camera_app_msgs__srv__Capture_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // cam
  output->cam = input->cam;
  // rec
  output->rec = input->rec;
  return true;
}

camera_app_msgs__srv__Capture_Request *
camera_app_msgs__srv__Capture_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_app_msgs__srv__Capture_Request * msg = (camera_app_msgs__srv__Capture_Request *)allocator.allocate(sizeof(camera_app_msgs__srv__Capture_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(camera_app_msgs__srv__Capture_Request));
  bool success = camera_app_msgs__srv__Capture_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
camera_app_msgs__srv__Capture_Request__destroy(camera_app_msgs__srv__Capture_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    camera_app_msgs__srv__Capture_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
camera_app_msgs__srv__Capture_Request__Sequence__init(camera_app_msgs__srv__Capture_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_app_msgs__srv__Capture_Request * data = NULL;

  if (size) {
    data = (camera_app_msgs__srv__Capture_Request *)allocator.zero_allocate(size, sizeof(camera_app_msgs__srv__Capture_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = camera_app_msgs__srv__Capture_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        camera_app_msgs__srv__Capture_Request__fini(&data[i - 1]);
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
camera_app_msgs__srv__Capture_Request__Sequence__fini(camera_app_msgs__srv__Capture_Request__Sequence * array)
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
      camera_app_msgs__srv__Capture_Request__fini(&array->data[i]);
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

camera_app_msgs__srv__Capture_Request__Sequence *
camera_app_msgs__srv__Capture_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_app_msgs__srv__Capture_Request__Sequence * array = (camera_app_msgs__srv__Capture_Request__Sequence *)allocator.allocate(sizeof(camera_app_msgs__srv__Capture_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = camera_app_msgs__srv__Capture_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
camera_app_msgs__srv__Capture_Request__Sequence__destroy(camera_app_msgs__srv__Capture_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    camera_app_msgs__srv__Capture_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
camera_app_msgs__srv__Capture_Request__Sequence__are_equal(const camera_app_msgs__srv__Capture_Request__Sequence * lhs, const camera_app_msgs__srv__Capture_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!camera_app_msgs__srv__Capture_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
camera_app_msgs__srv__Capture_Request__Sequence__copy(
  const camera_app_msgs__srv__Capture_Request__Sequence * input,
  camera_app_msgs__srv__Capture_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(camera_app_msgs__srv__Capture_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    camera_app_msgs__srv__Capture_Request * data =
      (camera_app_msgs__srv__Capture_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!camera_app_msgs__srv__Capture_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          camera_app_msgs__srv__Capture_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!camera_app_msgs__srv__Capture_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
camera_app_msgs__srv__Capture_Response__init(camera_app_msgs__srv__Capture_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
camera_app_msgs__srv__Capture_Response__fini(camera_app_msgs__srv__Capture_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
camera_app_msgs__srv__Capture_Response__are_equal(const camera_app_msgs__srv__Capture_Response * lhs, const camera_app_msgs__srv__Capture_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
camera_app_msgs__srv__Capture_Response__copy(
  const camera_app_msgs__srv__Capture_Response * input,
  camera_app_msgs__srv__Capture_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

camera_app_msgs__srv__Capture_Response *
camera_app_msgs__srv__Capture_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_app_msgs__srv__Capture_Response * msg = (camera_app_msgs__srv__Capture_Response *)allocator.allocate(sizeof(camera_app_msgs__srv__Capture_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(camera_app_msgs__srv__Capture_Response));
  bool success = camera_app_msgs__srv__Capture_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
camera_app_msgs__srv__Capture_Response__destroy(camera_app_msgs__srv__Capture_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    camera_app_msgs__srv__Capture_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
camera_app_msgs__srv__Capture_Response__Sequence__init(camera_app_msgs__srv__Capture_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_app_msgs__srv__Capture_Response * data = NULL;

  if (size) {
    data = (camera_app_msgs__srv__Capture_Response *)allocator.zero_allocate(size, sizeof(camera_app_msgs__srv__Capture_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = camera_app_msgs__srv__Capture_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        camera_app_msgs__srv__Capture_Response__fini(&data[i - 1]);
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
camera_app_msgs__srv__Capture_Response__Sequence__fini(camera_app_msgs__srv__Capture_Response__Sequence * array)
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
      camera_app_msgs__srv__Capture_Response__fini(&array->data[i]);
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

camera_app_msgs__srv__Capture_Response__Sequence *
camera_app_msgs__srv__Capture_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera_app_msgs__srv__Capture_Response__Sequence * array = (camera_app_msgs__srv__Capture_Response__Sequence *)allocator.allocate(sizeof(camera_app_msgs__srv__Capture_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = camera_app_msgs__srv__Capture_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
camera_app_msgs__srv__Capture_Response__Sequence__destroy(camera_app_msgs__srv__Capture_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    camera_app_msgs__srv__Capture_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
camera_app_msgs__srv__Capture_Response__Sequence__are_equal(const camera_app_msgs__srv__Capture_Response__Sequence * lhs, const camera_app_msgs__srv__Capture_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!camera_app_msgs__srv__Capture_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
camera_app_msgs__srv__Capture_Response__Sequence__copy(
  const camera_app_msgs__srv__Capture_Response__Sequence * input,
  camera_app_msgs__srv__Capture_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(camera_app_msgs__srv__Capture_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    camera_app_msgs__srv__Capture_Response * data =
      (camera_app_msgs__srv__Capture_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!camera_app_msgs__srv__Capture_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          camera_app_msgs__srv__Capture_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!camera_app_msgs__srv__Capture_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
