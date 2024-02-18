cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(HelloWorld) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 14) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR})
add_executable(${HelloWorld} ${CMAKE_SOURCE_DIR}/main.cpp
${CMAKE_SOURCE_DIR}/helloworld.h ${CMAKE_SOURCE_DIR}/helloworld.cpp)
