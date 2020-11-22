cmake_minimum_required(VERSION 3.0.0)
project(Duck!Duck!)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Compile and Link GLFW
add_subdirectory(glfw-3.3.2)
link_libraries(glfw)
include_directories(${glfw_INCLUDE_DIRS})
include_directories("${CMAKE_SOURCE_DIR}/glfw-3.3.2/deps")

add_library(glad "${CMAKE_SOURCE_DIR}/glfw-3.3.2/deps/glad/gl.h"
                "${CMAKE_SOURCE_DIR}/glfw-3.3.2/deps/glad_gl.c")

link_libraries(glad)

include_directories(${CMAKE_SOURCE_DIR}/source
                    ${CMAKE_SOURCE_DIR}/source/common)          

add_executable(DuckDuck
        source/main.cpp)