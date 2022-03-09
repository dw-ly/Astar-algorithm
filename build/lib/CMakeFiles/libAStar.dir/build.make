# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/Document/Astar-algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/Document/Astar-algorithm/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/libAStar.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/libAStar.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/libAStar.dir/flags.make

lib/CMakeFiles/libAStar.dir/A*.cpp.o: lib/CMakeFiles/libAStar.dir/flags.make
lib/CMakeFiles/libAStar.dir/A*.cpp.o: ../lib/A*.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/Document/Astar-algorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/libAStar.dir/A*.cpp.o"
	cd /usr/Document/Astar-algorithm/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o "CMakeFiles/libAStar.dir/A*.cpp.o" -c "/usr/Document/Astar-algorithm/lib/A*.cpp"

lib/CMakeFiles/libAStar.dir/A*.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libAStar.dir/A*.cpp.i"
	cd /usr/Document/Astar-algorithm/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/usr/Document/Astar-algorithm/lib/A*.cpp" > "CMakeFiles/libAStar.dir/A*.cpp.i"

lib/CMakeFiles/libAStar.dir/A*.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libAStar.dir/A*.cpp.s"
	cd /usr/Document/Astar-algorithm/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/usr/Document/Astar-algorithm/lib/A*.cpp" -o "CMakeFiles/libAStar.dir/A*.cpp.s"

lib/CMakeFiles/libAStar.dir/gridMap.cpp.o: lib/CMakeFiles/libAStar.dir/flags.make
lib/CMakeFiles/libAStar.dir/gridMap.cpp.o: ../lib/gridMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/Document/Astar-algorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/libAStar.dir/gridMap.cpp.o"
	cd /usr/Document/Astar-algorithm/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libAStar.dir/gridMap.cpp.o -c /usr/Document/Astar-algorithm/lib/gridMap.cpp

lib/CMakeFiles/libAStar.dir/gridMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libAStar.dir/gridMap.cpp.i"
	cd /usr/Document/Astar-algorithm/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/Document/Astar-algorithm/lib/gridMap.cpp > CMakeFiles/libAStar.dir/gridMap.cpp.i

lib/CMakeFiles/libAStar.dir/gridMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libAStar.dir/gridMap.cpp.s"
	cd /usr/Document/Astar-algorithm/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/Document/Astar-algorithm/lib/gridMap.cpp -o CMakeFiles/libAStar.dir/gridMap.cpp.s

# Object files for target libAStar
libAStar_OBJECTS = \
"CMakeFiles/libAStar.dir/A*.cpp.o" \
"CMakeFiles/libAStar.dir/gridMap.cpp.o"

# External object files for target libAStar
libAStar_EXTERNAL_OBJECTS =

lib/libAStar.a: lib/CMakeFiles/libAStar.dir/A*.cpp.o
lib/libAStar.a: lib/CMakeFiles/libAStar.dir/gridMap.cpp.o
lib/libAStar.a: lib/CMakeFiles/libAStar.dir/build.make
lib/libAStar.a: lib/CMakeFiles/libAStar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/Document/Astar-algorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libAStar.a"
	cd /usr/Document/Astar-algorithm/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/libAStar.dir/cmake_clean_target.cmake
	cd /usr/Document/Astar-algorithm/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libAStar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/libAStar.dir/build: lib/libAStar.a

.PHONY : lib/CMakeFiles/libAStar.dir/build

lib/CMakeFiles/libAStar.dir/clean:
	cd /usr/Document/Astar-algorithm/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/libAStar.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/libAStar.dir/clean

lib/CMakeFiles/libAStar.dir/depend:
	cd /usr/Document/Astar-algorithm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/Document/Astar-algorithm /usr/Document/Astar-algorithm/lib /usr/Document/Astar-algorithm/build /usr/Document/Astar-algorithm/build/lib /usr/Document/Astar-algorithm/build/lib/CMakeFiles/libAStar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/libAStar.dir/depend

