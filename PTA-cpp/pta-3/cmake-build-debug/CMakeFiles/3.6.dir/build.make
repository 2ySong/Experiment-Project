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
CMAKE_SOURCE_DIR = "E:\Love me\PTA-cpp\pta-3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Love me\PTA-cpp\pta-3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/3.6.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/3.6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3.6.dir/flags.make

CMakeFiles/3.6.dir/3.6.cpp.obj: CMakeFiles/3.6.dir/flags.make
CMakeFiles/3.6.dir/3.6.cpp.obj: ../3.6.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Love me\PTA-cpp\pta-3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3.6.dir/3.6.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\3.6.dir\3.6.cpp.obj -c "E:\Love me\PTA-cpp\pta-3\3.6.cpp"

CMakeFiles/3.6.dir/3.6.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3.6.dir/3.6.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Love me\PTA-cpp\pta-3\3.6.cpp" > CMakeFiles\3.6.dir\3.6.cpp.i

CMakeFiles/3.6.dir/3.6.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3.6.dir/3.6.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Love me\PTA-cpp\pta-3\3.6.cpp" -o CMakeFiles\3.6.dir\3.6.cpp.s

# Object files for target 3.6
3_6_OBJECTS = \
"CMakeFiles/3.6.dir/3.6.cpp.obj"

# External object files for target 3.6
3_6_EXTERNAL_OBJECTS =

3.6.exe: CMakeFiles/3.6.dir/3.6.cpp.obj
3.6.exe: CMakeFiles/3.6.dir/build.make
3.6.exe: CMakeFiles/3.6.dir/linklibs.rsp
3.6.exe: CMakeFiles/3.6.dir/objects1.rsp
3.6.exe: CMakeFiles/3.6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Love me\PTA-cpp\pta-3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3.6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3.6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3.6.dir/build: 3.6.exe
.PHONY : CMakeFiles/3.6.dir/build

CMakeFiles/3.6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3.6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3.6.dir/clean

CMakeFiles/3.6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Love me\PTA-cpp\pta-3" "E:\Love me\PTA-cpp\pta-3" "E:\Love me\PTA-cpp\pta-3\cmake-build-debug" "E:\Love me\PTA-cpp\pta-3\cmake-build-debug" "E:\Love me\PTA-cpp\pta-3\cmake-build-debug\CMakeFiles\3.6.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/3.6.dir/depend

