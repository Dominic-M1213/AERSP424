cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Homework_1) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 14) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Note_2_12 ${CMAKE_SOURCE_DIR}/main.cpp 
Pilot.cpp Pilot.h 
Plane.cpp Plane.h
makePlane.cpp makePlane.h
FlightMap.cpp FlightMap.h)