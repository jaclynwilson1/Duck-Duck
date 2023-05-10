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

option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
                        Tests in tests/*.cpp will still be enabled." ON)

                        # Include stuff. No change needed.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(ConfigSafeGuards)
include(Colors)
include(CTest)
include(Doctest)
include(Documentation)
include(LTO)
include(Misc)
include(Warnings)

# Check for LTO support.
find_lto(CXX)

SET(MY_SHADER_PATH ${CMAKE_SOURCE_DIR}/shaders/)
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/shaders/shader.cpp.in ${CMAKE_SOURCE_DIR}/shaders/shader.cpp)	


include_directories(${CMAKE_SOURCE_DIR}/source
					${CMAKE_SOURCE_DIR}/include
					${CMAKE_SOURCE_DIR}/shaders)

include_directories(${CMAKE_SOURCE_DIR}/source
                    ${CMAKE_SOURCE_DIR}/source/include)          

add_executable(DuckDuck
        source/main.cpp
        source/Duck.cpp
        source/Hunter.cpp
        source/Bullet.cpp
        source/Map.cpp
        include/Angel.h
        include/common.h
        include/Duck.h
        include/Hunter.h
        include/Bullet.h
        include/Map.h
        include/mat.h
        include/vec.h
        include/lodepng.cpp
        include/lodepng.h
        shaders/shader.cpp
        shaders/fshader_Duck.glsl
        shaders/vshader_Duck.glsl
        shaders/fshader_Map.glsl
        shaders/vshader_Map.glsl
        shaders/fshader.glsl
        shaders/vshader.glsl)


message("Debug BUILD")
option(ENABLE_WARNINGS_SETTINGS "Allow target_set_warnings to add flags and defines.
                        Set this to OFF if you want to provide your own warning parameters." ON)
option(ENABLE_LTO "Enable link time optomization" ON)
option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
                        Tests in tests/*.cpp will still be enabled." ON)
#find_package(doctest)
set(TESTFILES tests/main.cpp tests/tests.cpp)
target_link_libraries(${LIBRARY_NAME} doctest)
add_subdirectory(tests)

#add_subdirectory(tests)

#target_compile_features(tests PRIVATE cxx_std_17)
#target_link_libraries(tests PRIVATE doctest::doctest)