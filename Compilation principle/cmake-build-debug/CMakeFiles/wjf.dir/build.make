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
CMAKE_SOURCE_DIR = "E:\Love me\Compilation principle"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Love me\Compilation principle\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/wjf.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/wjf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wjf.dir/flags.make

CMakeFiles/wjf.dir/wjf.cpp.obj: CMakeFiles/wjf.dir/flags.make
CMakeFiles/wjf.dir/wjf.cpp.obj: ../wjf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Love me\Compilation principle\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wjf.dir/wjf.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\wjf.dir\wjf.cpp.obj -c "E:\Love me\Compilation principle\wjf.cpp"

CMakeFiles/wjf.dir/wjf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wjf.dir/wjf.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Love me\Compilation principle\wjf.cpp" > CMakeFiles\wjf.dir\wjf.cpp.i

CMakeFiles/wjf.dir/wjf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wjf.dir/wjf.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Love me\Compilation principle\wjf.cpp" -o CMakeFiles\wjf.dir\wjf.cpp.s

# Object files for target wjf
wjf_OBJECTS = \
"CMakeFiles/wjf.dir/wjf.cpp.obj"

# External object files for target wjf
wjf_EXTERNAL_OBJECTS =

wjf.exe: CMakeFiles/wjf.dir/wjf.cpp.obj
wjf.exe: CMakeFiles/wjf.dir/build.make
wjf.exe: CMakeFiles/wjf.dir/linklibs.rsp
wjf.exe: CMakeFiles/wjf.dir/objects1.rsp
wjf.exe: CMakeFiles/wjf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Love me\Compilation principle\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wjf.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\wjf.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wjf.dir/build: wjf.exe
.PHONY : CMakeFiles/wjf.dir/build

CMakeFiles/wjf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\wjf.dir\cmake_clean.cmake
.PHONY : CMakeFiles/wjf.dir/clean

CMakeFiles/wjf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Love me\Compilation principle" "E:\Love me\Compilation principle" "E:\Love me\Compilation principle\cmake-build-debug" "E:\Love me\Compilation principle\cmake-build-debug" "E:\Love me\Compilation principle\cmake-build-debug\CMakeFiles\wjf.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/wjf.dir/depend

