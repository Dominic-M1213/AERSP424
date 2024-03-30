cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Note_3_12) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 14) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Note_3_12 ${CMAKE_SOURCE_DIR}/main.cpp participation_3_12.cpp)
