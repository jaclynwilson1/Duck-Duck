# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaclyn/Desktop/Duck-Duck

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaclyn/Desktop/Duck-Duck/build

# Include any dependencies generated for this target.
include CMakeFiles/DuckDuck.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DuckDuck.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DuckDuck.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DuckDuck.dir/flags.make

CMakeFiles/DuckDuck.dir/source/main.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/source/main.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/source/main.cpp
CMakeFiles/DuckDuck.dir/source/main.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DuckDuck.dir/source/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/source/main.cpp.o -MF CMakeFiles/DuckDuck.dir/source/main.cpp.o.d -o CMakeFiles/DuckDuck.dir/source/main.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/source/main.cpp

CMakeFiles/DuckDuck.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/source/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/source/main.cpp > CMakeFiles/DuckDuck.dir/source/main.cpp.i

CMakeFiles/DuckDuck.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/source/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/source/main.cpp -o CMakeFiles/DuckDuck.dir/source/main.cpp.s

CMakeFiles/DuckDuck.dir/source/Duck.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/source/Duck.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/source/Duck.cpp
CMakeFiles/DuckDuck.dir/source/Duck.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DuckDuck.dir/source/Duck.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/source/Duck.cpp.o -MF CMakeFiles/DuckDuck.dir/source/Duck.cpp.o.d -o CMakeFiles/DuckDuck.dir/source/Duck.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/source/Duck.cpp

CMakeFiles/DuckDuck.dir/source/Duck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/source/Duck.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/source/Duck.cpp > CMakeFiles/DuckDuck.dir/source/Duck.cpp.i

CMakeFiles/DuckDuck.dir/source/Duck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/source/Duck.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/source/Duck.cpp -o CMakeFiles/DuckDuck.dir/source/Duck.cpp.s

CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/source/Hunter.cpp
CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o -MF CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o.d -o CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/source/Hunter.cpp

CMakeFiles/DuckDuck.dir/source/Hunter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/source/Hunter.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/source/Hunter.cpp > CMakeFiles/DuckDuck.dir/source/Hunter.cpp.i

CMakeFiles/DuckDuck.dir/source/Hunter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/source/Hunter.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/source/Hunter.cpp -o CMakeFiles/DuckDuck.dir/source/Hunter.cpp.s

CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/source/Bullet.cpp
CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o -MF CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o.d -o CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/source/Bullet.cpp

CMakeFiles/DuckDuck.dir/source/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/source/Bullet.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/source/Bullet.cpp > CMakeFiles/DuckDuck.dir/source/Bullet.cpp.i

CMakeFiles/DuckDuck.dir/source/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/source/Bullet.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/source/Bullet.cpp -o CMakeFiles/DuckDuck.dir/source/Bullet.cpp.s

CMakeFiles/DuckDuck.dir/source/Map.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/source/Map.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/source/Map.cpp
CMakeFiles/DuckDuck.dir/source/Map.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DuckDuck.dir/source/Map.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/source/Map.cpp.o -MF CMakeFiles/DuckDuck.dir/source/Map.cpp.o.d -o CMakeFiles/DuckDuck.dir/source/Map.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/source/Map.cpp

CMakeFiles/DuckDuck.dir/source/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/source/Map.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/source/Map.cpp > CMakeFiles/DuckDuck.dir/source/Map.cpp.i

CMakeFiles/DuckDuck.dir/source/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/source/Map.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/source/Map.cpp -o CMakeFiles/DuckDuck.dir/source/Map.cpp.s

CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/include/lodepng.cpp
CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o -MF CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o.d -o CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/include/lodepng.cpp

CMakeFiles/DuckDuck.dir/include/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/include/lodepng.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/include/lodepng.cpp > CMakeFiles/DuckDuck.dir/include/lodepng.cpp.i

CMakeFiles/DuckDuck.dir/include/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/include/lodepng.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/include/lodepng.cpp -o CMakeFiles/DuckDuck.dir/include/lodepng.cpp.s

CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/shaders/shader.cpp
CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o -MF CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o.d -o CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/shaders/shader.cpp

CMakeFiles/DuckDuck.dir/shaders/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/shaders/shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/shaders/shader.cpp > CMakeFiles/DuckDuck.dir/shaders/shader.cpp.i

CMakeFiles/DuckDuck.dir/shaders/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/shaders/shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/shaders/shader.cpp -o CMakeFiles/DuckDuck.dir/shaders/shader.cpp.s

CMakeFiles/DuckDuck.dir/tests/tests.cpp.o: CMakeFiles/DuckDuck.dir/flags.make
CMakeFiles/DuckDuck.dir/tests/tests.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp
CMakeFiles/DuckDuck.dir/tests/tests.cpp.o: CMakeFiles/DuckDuck.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/DuckDuck.dir/tests/tests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DuckDuck.dir/tests/tests.cpp.o -MF CMakeFiles/DuckDuck.dir/tests/tests.cpp.o.d -o CMakeFiles/DuckDuck.dir/tests/tests.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp

CMakeFiles/DuckDuck.dir/tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DuckDuck.dir/tests/tests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp > CMakeFiles/DuckDuck.dir/tests/tests.cpp.i

CMakeFiles/DuckDuck.dir/tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DuckDuck.dir/tests/tests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp -o CMakeFiles/DuckDuck.dir/tests/tests.cpp.s

# Object files for target DuckDuck
DuckDuck_OBJECTS = \
"CMakeFiles/DuckDuck.dir/source/main.cpp.o" \
"CMakeFiles/DuckDuck.dir/source/Duck.cpp.o" \
"CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o" \
"CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o" \
"CMakeFiles/DuckDuck.dir/source/Map.cpp.o" \
"CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o" \
"CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o" \
"CMakeFiles/DuckDuck.dir/tests/tests.cpp.o"

# External object files for target DuckDuck
DuckDuck_EXTERNAL_OBJECTS =

DuckDuck: CMakeFiles/DuckDuck.dir/source/main.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/source/Duck.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/source/Hunter.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/source/Bullet.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/source/Map.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/include/lodepng.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/shaders/shader.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/tests/tests.cpp.o
DuckDuck: CMakeFiles/DuckDuck.dir/build.make
DuckDuck: glfw-3.3.2/src/libglfw3.a
DuckDuck: libglad.a
DuckDuck: glfw-3.3.2/src/libglfw3.a
DuckDuck: CMakeFiles/DuckDuck.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable DuckDuck"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DuckDuck.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DuckDuck.dir/build: DuckDuck
.PHONY : CMakeFiles/DuckDuck.dir/build

CMakeFiles/DuckDuck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DuckDuck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DuckDuck.dir/clean

CMakeFiles/DuckDuck.dir/depend:
	cd /Users/jaclyn/Desktop/Duck-Duck/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaclyn/Desktop/Duck-Duck /Users/jaclyn/Desktop/Duck-Duck /Users/jaclyn/Desktop/Duck-Duck/build /Users/jaclyn/Desktop/Duck-Duck/build /Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles/DuckDuck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DuckDuck.dir/depend

