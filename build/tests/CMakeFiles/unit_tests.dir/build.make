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
include tests/CMakeFiles/unit_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/unit_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/unit_tests.dir/flags.make

tests/CMakeFiles/unit_tests.dir/tests.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/tests.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp
tests/CMakeFiles/unit_tests.dir/tests.cpp.o: tests/CMakeFiles/unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/unit_tests.dir/tests.cpp.o"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/unit_tests.dir/tests.cpp.o -MF CMakeFiles/unit_tests.dir/tests.cpp.o.d -o CMakeFiles/unit_tests.dir/tests.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp

tests/CMakeFiles/unit_tests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/tests.cpp.i"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp > CMakeFiles/unit_tests.dir/tests.cpp.i

tests/CMakeFiles/unit_tests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/tests.cpp.s"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/tests/tests.cpp -o CMakeFiles/unit_tests.dir/tests.cpp.s

tests/CMakeFiles/unit_tests.dir/main.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/main.cpp.o: /Users/jaclyn/Desktop/Duck-Duck/tests/main.cpp
tests/CMakeFiles/unit_tests.dir/main.cpp.o: tests/CMakeFiles/unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/unit_tests.dir/main.cpp.o"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/unit_tests.dir/main.cpp.o -MF CMakeFiles/unit_tests.dir/main.cpp.o.d -o CMakeFiles/unit_tests.dir/main.cpp.o -c /Users/jaclyn/Desktop/Duck-Duck/tests/main.cpp

tests/CMakeFiles/unit_tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/main.cpp.i"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaclyn/Desktop/Duck-Duck/tests/main.cpp > CMakeFiles/unit_tests.dir/main.cpp.i

tests/CMakeFiles/unit_tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/main.cpp.s"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaclyn/Desktop/Duck-Duck/tests/main.cpp -o CMakeFiles/unit_tests.dir/main.cpp.s

# Object files for target unit_tests
unit_tests_OBJECTS = \
"CMakeFiles/unit_tests.dir/tests.cpp.o" \
"CMakeFiles/unit_tests.dir/main.cpp.o"

# External object files for target unit_tests
unit_tests_EXTERNAL_OBJECTS =

unit_tests: tests/CMakeFiles/unit_tests.dir/tests.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/main.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/build.make
unit_tests: glfw-3.3.2/src/libglfw3.a
unit_tests: libglad.a
unit_tests: glfw-3.3.2/src/libglfw3.a
unit_tests: tests/CMakeFiles/unit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaclyn/Desktop/Duck-Duck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../unit_tests"
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/unit_tests.dir/build: unit_tests
.PHONY : tests/CMakeFiles/unit_tests.dir/build

tests/CMakeFiles/unit_tests.dir/clean:
	cd /Users/jaclyn/Desktop/Duck-Duck/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/unit_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/unit_tests.dir/clean

tests/CMakeFiles/unit_tests.dir/depend:
	cd /Users/jaclyn/Desktop/Duck-Duck/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaclyn/Desktop/Duck-Duck /Users/jaclyn/Desktop/Duck-Duck/tests /Users/jaclyn/Desktop/Duck-Duck/build /Users/jaclyn/Desktop/Duck-Duck/build/tests /Users/jaclyn/Desktop/Duck-Duck/build/tests/CMakeFiles/unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/unit_tests.dir/depend

