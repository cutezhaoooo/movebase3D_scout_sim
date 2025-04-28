# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rviz_waypoint_generator_plungins_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rviz_waypoint_generator_plungins_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rviz_waypoint_generator_plungins_FOUND FALSE)
  elseif(NOT rviz_waypoint_generator_plungins_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rviz_waypoint_generator_plungins_FOUND FALSE)
  endif()
  return()
endif()
set(_rviz_waypoint_generator_plungins_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rviz_waypoint_generator_plungins_FIND_QUIETLY)
  message(STATUS "Found rviz_waypoint_generator_plungins: 0.0.0 (${rviz_waypoint_generator_plungins_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rviz_waypoint_generator_plungins' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${rviz_waypoint_generator_plungins_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rviz_waypoint_generator_plungins_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rviz_waypoint_generator_plungins_DIR}/${_extra}")
endforeach()
