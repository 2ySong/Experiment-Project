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
CMAKE_SOURCE_DIR = "E:\Love me\c++\day05-array"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Love me\c++\day05-array\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/tyt.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/tyt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tyt.dir/flags.make

CMakeFiles/tyt.dir/tyt.cpp.obj: CMakeFiles/tyt.dir/flags.make
CMakeFiles/tyt.dir/tyt.cpp.obj: ../tyt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Love me\c++\day05-array\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tyt.dir/tyt.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tyt.dir\tyt.cpp.obj -c "E:\Love me\c++\day05-array\tyt.cpp"

CMakeFiles/tyt.dir/tyt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tyt.dir/tyt.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Love me\c++\day05-array\tyt.cpp" > CMakeFiles\tyt.dir\tyt.cpp.i

CMakeFiles/tyt.dir/tyt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tyt.dir/tyt.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Love me\c++\day05-array\tyt.cpp" -o CMakeFiles\tyt.dir\tyt.cpp.s

# Object files for target tyt
tyt_OBJECTS = \
"CMakeFiles/tyt.dir/tyt.cpp.obj"

# External object files for target tyt
tyt_EXTERNAL_OBJECTS =

tyt.exe: CMakeFiles/tyt.dir/tyt.cpp.obj
tyt.exe: CMakeFiles/tyt.dir/build.make
tyt.exe: CMakeFiles/tyt.dir/linklibs.rsp
tyt.exe: CMakeFiles/tyt.dir/objects1.rsp
tyt.exe: CMakeFiles/tyt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Love me\c++\day05-array\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tyt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tyt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tyt.dir/build: tyt.exe
.PHONY : CMakeFiles/tyt.dir/build

CMakeFiles/tyt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tyt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tyt.dir/clean

CMakeFiles/tyt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Love me\c++\day05-array" "E:\Love me\c++\day05-array" "E:\Love me\c++\day05-array\cmake-build-debug" "E:\Love me\c++\day05-array\cmake-build-debug" "E:\Love me\c++\day05-array\cmake-build-debug\CMakeFiles\tyt.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tyt.dir/depend
