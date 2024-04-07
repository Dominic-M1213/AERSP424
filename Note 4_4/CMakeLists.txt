cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Note_4_4) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 23) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Note_4_4 ${CMAKE_SOURCE_DIR}/main.cpp)
