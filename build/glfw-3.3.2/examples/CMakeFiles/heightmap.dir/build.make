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
include glfw-3.3.2/examples/CMakeFiles/heightmap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glfw-3.3.2/examples/CMakeFiles/heightmap.dir/compiler_depend.make

# Include the progress variables for this target.
include glfw-3.3.2/examples/CMakeFiles/heightmap.dir/progress.make

# Include the compile flags for this target's objects.
include glfw-3.3.2/examples/CMakeFiles/heightmap.dir/flags.make

glfw-3.3.2/examples/heightmap.app/Contents/Resources/glfw.icns: /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content glfw-3.3.2/examples/heightmap.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/examples/glfw.icns glfw-3.3.2/examples/heightmap.app/Contents/Resources/glfw.icns

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/flags.make
glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o: /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/examples/heightmap.c
glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o -MF CMakeFiles/heightmap.dir/heightmap.c.o.d -o CMakeFiles/heightmap.dir/heightmap.c.o -c /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/examples/heightmap.c

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heightmap.dir/heightmap.c.i"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/examples/heightmap.c > CMakeFiles/heightmap.dir/heightmap.c.i

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heightmap.dir/heightmap.c.s"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/examples/heightmap.c -o CMakeFiles/heightmap.dir/heightmap.c.s

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/flags.make
glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o: /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/deps/glad_gl.c
glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o -MF CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o.d -o CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o -c /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/deps/glad_gl.c

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heightmap.dir/__/deps/glad_gl.c.i"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/deps/glad_gl.c > CMakeFiles/heightmap.dir/__/deps/glad_gl.c.i

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heightmap.dir/__/deps/glad_gl.c.s"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/deps/glad_gl.c -o CMakeFiles/heightmap.dir/__/deps/glad_gl.c.s

# Object files for target heightmap
heightmap_OBJECTS = \
"CMakeFiles/heightmap.dir/heightmap.c.o" \
"CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o"

# External object files for target heightmap
heightmap_EXTERNAL_OBJECTS =

glfw-3.3.2/examples/heightmap.app/Contents/MacOS/heightmap: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/heightmap.c.o
glfw-3.3.2/examples/heightmap.app/Contents/MacOS/heightmap: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o
glfw-3.3.2/examples/heightmap.app/Contents/MacOS/heightmap: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/build.make
glfw-3.3.2/examples/heightmap.app/Contents/MacOS/heightmap: glfw-3.3.2/src/libglfw3.a
glfw-3.3.2/examples/heightmap.app/Contents/MacOS/heightmap: glfw-3.3.2/examples/CMakeFiles/heightmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable heightmap.app/Contents/MacOS/heightmap"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heightmap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw-3.3.2/examples/CMakeFiles/heightmap.dir/build: glfw-3.3.2/examples/heightmap.app/Contents/MacOS/heightmap
glfw-3.3.2/examples/CMakeFiles/heightmap.dir/build: glfw-3.3.2/examples/heightmap.app/Contents/Resources/glfw.icns
.PHONY : glfw-3.3.2/examples/CMakeFiles/heightmap.dir/build

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/clean:
	cd /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples && $(CMAKE_COMMAND) -P CMakeFiles/heightmap.dir/cmake_clean.cmake
.PHONY : glfw-3.3.2/examples/CMakeFiles/heightmap.dir/clean

glfw-3.3.2/examples/CMakeFiles/heightmap.dir/depend:
	cd /Users/jaclyn/Desktop/Duck-Duck/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaclyn/Desktop/Duck-Duck /Users/jaclyn/Desktop/Duck-Duck/glfw-3.3.2/examples /Users/jaclyn/Desktop/Duck-Duck/build /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples /Users/jaclyn/Desktop/Duck-Duck/build/glfw-3.3.2/examples/CMakeFiles/heightmap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw-3.3.2/examples/CMakeFiles/heightmap.dir/depend

