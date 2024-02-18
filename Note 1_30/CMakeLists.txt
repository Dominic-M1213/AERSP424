cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Note_1_30) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 14) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Note_1_30 ${CMAKE_SOURCE_DIR}/main.cpp)
