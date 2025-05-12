cmake_minimum_required(VERSION 3.8)
project(rviz_multi_goals_manager_plugins)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rviz_common REQUIRED)
find_package(std_msgs REQUIRED)
find_package(action_msgs REQUIRED)
find_package(rover_msgs REQUIRED)

# 包含目录配置
include_directories(
  include
  ${Qt5Widgets_INCLUDE_DIRS}
  ${rviz_common_INCLUDE_DIRS}
  ${pluginlib_INCLUDE_DIRS}
)

# 查找并包含Qt UI和资源文件（如果有）
qt5_wrap_cpp(MOC_FILES
  include/rviz_multi_goals_manager_plugins/multi_navi_goal_panel.hpp
)

# 构建共享库
add_library(${PROJECT_NAME} SHARED
  src/multi_navi_goal_panel.cpp
  ${MOC_FILES}
)

# 链接依赖库
target_link_libraries(${PROJECT_NAME} PRIVATE
  rviz_common::rviz_common
  Qt5::Widgets
  Qt5::Core
  Qt5::Gui
  ${rclcpp_LIBRARIES}
  pluginlib::pluginlib
  action_msgs::action_msgs__rosidl_typesupport_cpp
  geometry_msgs::geometry_msgs__rosidl_typesupport_cpp
  visualization_msgs::visualization_msgs__rosidl_typesupport_cpp
  rover_msgs::rover_msgs__rosidl_typesupport_cpp
)

# 安装规则
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/
  DESTINATION include
)

ament_export_dependencies(
  rclcpp
  visualization_msgs
  geometry_msgs
  nav_msgs
  action_msgs
  rover_msgs
)

# 插件注册关键配置
pluginlib_export_plugin_description_file(rviz_common plugin_description.xml)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
