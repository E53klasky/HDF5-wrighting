# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adios/Programs/HDF5-test/HDF5-wrighting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adios/Programs/HDF5-test/HDF5-wrighting/build

# Include any dependencies generated for this target.
include CMakeFiles/phdf5_example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/phdf5_example.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/phdf5_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/phdf5_example.dir/flags.make

CMakeFiles/phdf5_example.dir/main.cpp.o: CMakeFiles/phdf5_example.dir/flags.make
CMakeFiles/phdf5_example.dir/main.cpp.o: /home/adios/Programs/HDF5-test/HDF5-wrighting/main.cpp
CMakeFiles/phdf5_example.dir/main.cpp.o: CMakeFiles/phdf5_example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adios/Programs/HDF5-test/HDF5-wrighting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/phdf5_example.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/phdf5_example.dir/main.cpp.o -MF CMakeFiles/phdf5_example.dir/main.cpp.o.d -o CMakeFiles/phdf5_example.dir/main.cpp.o -c /home/adios/Programs/HDF5-test/HDF5-wrighting/main.cpp

CMakeFiles/phdf5_example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/phdf5_example.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adios/Programs/HDF5-test/HDF5-wrighting/main.cpp > CMakeFiles/phdf5_example.dir/main.cpp.i

CMakeFiles/phdf5_example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/phdf5_example.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adios/Programs/HDF5-test/HDF5-wrighting/main.cpp -o CMakeFiles/phdf5_example.dir/main.cpp.s

# Object files for target phdf5_example
phdf5_example_OBJECTS = \
"CMakeFiles/phdf5_example.dir/main.cpp.o"

# External object files for target phdf5_example
phdf5_example_EXTERNAL_OBJECTS =

phdf5_example: CMakeFiles/phdf5_example.dir/main.cpp.o
phdf5_example: CMakeFiles/phdf5_example.dir/build.make
phdf5_example: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
phdf5_example: /usr/lib/x86_64-linux-gnu/hdf5/openmpi/libhdf5.so
phdf5_example: /usr/lib/x86_64-linux-gnu/libcrypto.so
phdf5_example: /usr/lib/x86_64-linux-gnu/libcurl.so
phdf5_example: /usr/lib/x86_64-linux-gnu/libsz.so
phdf5_example: /usr/lib/x86_64-linux-gnu/libz.so
phdf5_example: /usr/lib/x86_64-linux-gnu/libdl.a
phdf5_example: /usr/lib/x86_64-linux-gnu/libm.so
phdf5_example: CMakeFiles/phdf5_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adios/Programs/HDF5-test/HDF5-wrighting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable phdf5_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phdf5_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/phdf5_example.dir/build: phdf5_example
.PHONY : CMakeFiles/phdf5_example.dir/build

CMakeFiles/phdf5_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/phdf5_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/phdf5_example.dir/clean

CMakeFiles/phdf5_example.dir/depend:
	cd /home/adios/Programs/HDF5-test/HDF5-wrighting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adios/Programs/HDF5-test/HDF5-wrighting /home/adios/Programs/HDF5-test/HDF5-wrighting /home/adios/Programs/HDF5-test/HDF5-wrighting/build /home/adios/Programs/HDF5-test/HDF5-wrighting/build /home/adios/Programs/HDF5-test/HDF5-wrighting/build/CMakeFiles/phdf5_example.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/phdf5_example.dir/depend

