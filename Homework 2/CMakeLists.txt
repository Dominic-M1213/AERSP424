cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Homework_2) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Homework_2 ${CMAKE_SOURCE_DIR}/
main.cpp
Q1.h	Q1.cpp
Sensor.cpp 			Sensor.h
SensorFactory.h		AerospaceControlSystem.h
Accelerometer.h		PressureSensor.h
Q2.h	Q2.cpp
Robot.cpp			Robot.h
Q3.h	Q3.cpp
ATC.h				ATC.cpp
Pilot.h				Pilot.cpp
Q4.h	Q4.cpp
)
