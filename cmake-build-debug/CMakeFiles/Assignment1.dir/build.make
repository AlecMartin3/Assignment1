# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/Alec/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Alec/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Alec/CLionProjects/Assignment1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment1.dir/flags.make

CMakeFiles/Assignment1.dir/main.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment1.dir/main.cpp.o"
	C:/cygwin64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/main.cpp.o -c /cygdrive/c/Users/Alec/CLionProjects/Assignment1/main.cpp

CMakeFiles/Assignment1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/main.cpp.i"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Alec/CLionProjects/Assignment1/main.cpp > CMakeFiles/Assignment1.dir/main.cpp.i

CMakeFiles/Assignment1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/main.cpp.s"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Alec/CLionProjects/Assignment1/main.cpp -o CMakeFiles/Assignment1.dir/main.cpp.s

CMakeFiles/Assignment1.dir/matrix.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/matrix.cpp.o: ../matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment1.dir/matrix.cpp.o"
	C:/cygwin64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/matrix.cpp.o -c /cygdrive/c/Users/Alec/CLionProjects/Assignment1/matrix.cpp

CMakeFiles/Assignment1.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/matrix.cpp.i"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Alec/CLionProjects/Assignment1/matrix.cpp > CMakeFiles/Assignment1.dir/matrix.cpp.i

CMakeFiles/Assignment1.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/matrix.cpp.s"
	C:/cygwin64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Alec/CLionProjects/Assignment1/matrix.cpp -o CMakeFiles/Assignment1.dir/matrix.cpp.s

# Object files for target Assignment1
Assignment1_OBJECTS = \
"CMakeFiles/Assignment1.dir/main.cpp.o" \
"CMakeFiles/Assignment1.dir/matrix.cpp.o"

# External object files for target Assignment1
Assignment1_EXTERNAL_OBJECTS =

Assignment1.exe: CMakeFiles/Assignment1.dir/main.cpp.o
Assignment1.exe: CMakeFiles/Assignment1.dir/matrix.cpp.o
Assignment1.exe: CMakeFiles/Assignment1.dir/build.make
Assignment1.exe: CMakeFiles/Assignment1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Assignment1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment1.dir/build: Assignment1.exe

.PHONY : CMakeFiles/Assignment1.dir/build

CMakeFiles/Assignment1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment1.dir/clean

CMakeFiles/Assignment1.dir/depend:
	cd /cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Alec/CLionProjects/Assignment1 /cygdrive/c/Users/Alec/CLionProjects/Assignment1 /cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug /cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug /cygdrive/c/Users/Alec/CLionProjects/Assignment1/cmake-build-debug/CMakeFiles/Assignment1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment1.dir/depend

