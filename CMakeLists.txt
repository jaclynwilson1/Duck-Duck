cmake_minimum_required(VERSION 3.0.0)
project(Duck!Duck!)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Compile and Link GLFW
add_subdirectory(glfw-3.3.2)

include_directories(${glfw_INCLUDE_DIRS})
include_directories("${CMAKE_SOURCE_DIR}/glfw-3.3.2/deps")
link_libraries(glfw)
add_library(glad "${CMAKE_SOURCE_DIR}/glfw-3.3.2/deps/glad/gl.h"
                "${CMAKE_SOURCE_DIR}/glfw-3.3.2/deps/glad_gl.c" )

link_libraries(glad)

SET(MY_SHADER_PATH ${CMAKE_SOURCE_DIR}/shaders/)
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/shaders/shader.cpp.in ${CMAKE_SOURCE_DIR}/shaders/shader.cpp)	


include_directories(${CMAKE_SOURCE_DIR}/source
					${CMAKE_SOURCE_DIR}/source/common
					${CMAKE_SOURCE_DIR}/shaders)

include_directories(${CMAKE_SOURCE_DIR}/source
                    ${CMAKE_SOURCE_DIR}/source/common)          

add_executable(DuckDuck
        source/main.cpp
        source/Duck.cpp
        source/Hunter.cpp
        source/Bullet.cpp
        source/Map.cpp
        source/common/Angel.h
        source/common/common.h
        source/common/Duck.h
        source/common/Hunter.h
        source/common/Bullet.h
        source/common/Map.h
        source/common/mat.h
        source/common/vec.h
        source/common/lodepng.cpp
        source/common/lodepng.h
        shaders/shader.cpp
        shaders/fshader_Duck.glsl
        shaders/vshader_Duck.glsl
        shaders/fshader_Map.glsl
        shaders/vshader_Map.glsl
        shaders/fshader.glsl
        shaders/vshader.glsl
        tests/tests.cpp)

#add_subdirectory(tests)

#target_compile_features(tests PRIVATE cxx_std_17)
#target_link_libraries(tests PRIVATE doctest::doctest)