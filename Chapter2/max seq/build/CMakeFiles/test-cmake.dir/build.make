# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\15581\Desktop\max seq"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\15581\Desktop\max seq\build"

# Include any dependencies generated for this target.
include CMakeFiles/test-cmake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test-cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-cmake.dir/flags.make

CMakeFiles/test-cmake.dir/Src/main.cpp.obj: CMakeFiles/test-cmake.dir/flags.make
CMakeFiles/test-cmake.dir/Src/main.cpp.obj: CMakeFiles/test-cmake.dir/includes_CXX.rsp
CMakeFiles/test-cmake.dir/Src/main.cpp.obj: ../Src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\15581\Desktop\max seq\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test-cmake.dir/Src/main.cpp.obj"
	cd /d C:\Users\15581\Desktop\MAXSEQ~1\build && C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test-cmake.dir\Src\main.cpp.obj -c "C:\Users\15581\Desktop\max seq\Src\main.cpp"

CMakeFiles/test-cmake.dir/Src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-cmake.dir/Src/main.cpp.i"
	cd /d C:\Users\15581\Desktop\MAXSEQ~1\build && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\15581\Desktop\max seq\Src\main.cpp" > CMakeFiles\test-cmake.dir\Src\main.cpp.i

CMakeFiles/test-cmake.dir/Src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-cmake.dir/Src/main.cpp.s"
	cd /d C:\Users\15581\Desktop\MAXSEQ~1\build && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\15581\Desktop\max seq\Src\main.cpp" -o CMakeFiles\test-cmake.dir\Src\main.cpp.s

# Object files for target test-cmake
test__cmake_OBJECTS = \
"CMakeFiles/test-cmake.dir/Src/main.cpp.obj"

# External object files for target test-cmake
test__cmake_EXTERNAL_OBJECTS =

bin/test-cmake.exe: CMakeFiles/test-cmake.dir/Src/main.cpp.obj
bin/test-cmake.exe: CMakeFiles/test-cmake.dir/build.make
bin/test-cmake.exe: CMakeFiles/test-cmake.dir/linklibs.rsp
bin/test-cmake.exe: CMakeFiles/test-cmake.dir/objects1.rsp
bin/test-cmake.exe: CMakeFiles/test-cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\15581\Desktop\max seq\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\test-cmake.exe"
	cd /d C:\Users\15581\Desktop\MAXSEQ~1\build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-cmake.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test-cmake.dir/build: bin/test-cmake.exe

.PHONY : CMakeFiles/test-cmake.dir/build

CMakeFiles/test-cmake.dir/clean:
	cd /d C:\Users\15581\Desktop\MAXSEQ~1\build && $(CMAKE_COMMAND) -P CMakeFiles\test-cmake.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test-cmake.dir/clean

CMakeFiles/test-cmake.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\15581\Desktop\max seq" "C:\Users\15581\Desktop\max seq" "C:\Users\15581\Desktop\max seq\build" "C:\Users\15581\Desktop\max seq\build" "C:\Users\15581\Desktop\max seq\build\CMakeFiles\test-cmake.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test-cmake.dir/depend

