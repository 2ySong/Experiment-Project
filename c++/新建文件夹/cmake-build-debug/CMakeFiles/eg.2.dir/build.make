# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Love me\c++\C++ STL"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Love me\c++\C++ STL\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/eg.2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/eg.2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eg.2.dir/flags.make

CMakeFiles/eg.2.dir/eg.2.cpp.obj: CMakeFiles/eg.2.dir/flags.make
CMakeFiles/eg.2.dir/eg.2.cpp.obj: ../eg.2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Love me\c++\C++ STL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eg.2.dir/eg.2.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\eg.2.dir\eg.2.cpp.obj -c "E:\Love me\c++\C++ STL\eg.2.cpp"

CMakeFiles/eg.2.dir/eg.2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eg.2.dir/eg.2.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Love me\c++\C++ STL\eg.2.cpp" > CMakeFiles\eg.2.dir\eg.2.cpp.i

CMakeFiles/eg.2.dir/eg.2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eg.2.dir/eg.2.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Love me\c++\C++ STL\eg.2.cpp" -o CMakeFiles\eg.2.dir\eg.2.cpp.s

# Object files for target eg.2
eg_2_OBJECTS = \
"CMakeFiles/eg.2.dir/eg.2.cpp.obj"

# External object files for target eg.2
eg_2_EXTERNAL_OBJECTS =

eg.2.exe: CMakeFiles/eg.2.dir/eg.2.cpp.obj
eg.2.exe: CMakeFiles/eg.2.dir/build.make
eg.2.exe: CMakeFiles/eg.2.dir/linklibs.rsp
eg.2.exe: CMakeFiles/eg.2.dir/objects1.rsp
eg.2.exe: CMakeFiles/eg.2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Love me\c++\C++ STL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable eg.2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\eg.2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eg.2.dir/build: eg.2.exe
.PHONY : CMakeFiles/eg.2.dir/build

CMakeFiles/eg.2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\eg.2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/eg.2.dir/clean

CMakeFiles/eg.2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Love me\c++\C++ STL" "E:\Love me\c++\C++ STL" "E:\Love me\c++\C++ STL\cmake-build-debug" "E:\Love me\c++\C++ STL\cmake-build-debug" "E:\Love me\c++\C++ STL\cmake-build-debug\CMakeFiles\eg.2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/eg.2.dir/depend

