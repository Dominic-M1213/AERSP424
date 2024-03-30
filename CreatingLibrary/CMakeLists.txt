cmake_minimum_required(VERSION 3.2)
project(static_lib_example)
set(CMAKE_CXX_STANDARD 20)

add_library(static_lib_example STATIC code.cpp) # add your source code (.cpp)
target_include_directories(
${CMAKE_PROJECT_NAME} PUBLIC
${CMAKE_SOURCE_DIR}) # will look for your header file in a specific directory,
# which is CMAKE_SOURCE_DIR (the directory where CMakeLists.txt is in) in this case