cmake_minimum_required(VERSION 3.9.0)
project(docker_test)

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(docker_test main.cpp)
target_link_libraries(docker_test ${OpenCV_LIBS})