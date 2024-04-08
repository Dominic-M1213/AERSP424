cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Homework_2) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 23) # Specify C++ version.

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include
			  ${CMAKE_SOURCE_DIR}/include/GL 
			  ${CMAKE_SOURCE_DIR}/include/GLFW)

add_definitions(-DGLEW_STATIC) # static linking for glew only
set(GL_STATIC_LIBRARIES "${CMAKE_SOURCE_DIR}/lib/glew32sd.lib;${CMAKE_SOURCE_DIR}/lib/glfw3.lib")

add_executable(Homework_2
                          
src/main.cpp
src/Q1.h
src/Q1.cpp
src/Sensor.cpp
src/Sensor.h
src/SensorFactory.h
src/AerospaceControlSystem.h
src/Accelerometer.h
src/PressureSensor.h
src/PidoSensor.h
src/Q2.h
src/Q2.cpp
src/Robot.cpp
src/Robot.h
src/Q3.h
src/Q3.cpp
src/ATC.h
src/ATC.cpp
src/Pilot.h
src/Pilot.cpp
src/Q4.h
src/Q4.cpp
)

target_link_libraries(Homework_2
    ${OPENGL_gl_LIBRARY} ${GL_STATIC_LIBRARIES}
)