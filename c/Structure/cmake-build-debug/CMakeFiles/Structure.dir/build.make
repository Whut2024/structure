# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "D:\Developer\hobby\C\Clion\CLion 2023.3.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Developer\hobby\C\Clion\CLion 2023.3.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Codes\structure\c\Structure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Codes\structure\c\Structure\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Structure.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Structure.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Structure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Structure.dir/flags.make

CMakeFiles/Structure.dir/main.c.obj: CMakeFiles/Structure.dir/flags.make
CMakeFiles/Structure.dir/main.c.obj: D:/Codes/structure/c/Structure/main.c
CMakeFiles/Structure.dir/main.c.obj: CMakeFiles/Structure.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Codes\structure\c\Structure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Structure.dir/main.c.obj"
	D:\DEVELO~1\hobby\C\Clion\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Structure.dir/main.c.obj -MF CMakeFiles\Structure.dir\main.c.obj.d -o CMakeFiles\Structure.dir\main.c.obj -c D:\Codes\structure\c\Structure\main.c

CMakeFiles/Structure.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Structure.dir/main.c.i"
	D:\DEVELO~1\hobby\C\Clion\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Codes\structure\c\Structure\main.c > CMakeFiles\Structure.dir\main.c.i

CMakeFiles/Structure.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Structure.dir/main.c.s"
	D:\DEVELO~1\hobby\C\Clion\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Codes\structure\c\Structure\main.c -o CMakeFiles\Structure.dir\main.c.s

# Object files for target Structure
Structure_OBJECTS = \
"CMakeFiles/Structure.dir/main.c.obj"

# External object files for target Structure
Structure_EXTERNAL_OBJECTS =

Structure.exe: CMakeFiles/Structure.dir/main.c.obj
Structure.exe: CMakeFiles/Structure.dir/build.make
Structure.exe: CMakeFiles/Structure.dir/linkLibs.rsp
Structure.exe: CMakeFiles/Structure.dir/objects1.rsp
Structure.exe: CMakeFiles/Structure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Codes\structure\c\Structure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Structure.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Structure.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Structure.dir/build: Structure.exe
.PHONY : CMakeFiles/Structure.dir/build

CMakeFiles/Structure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Structure.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Structure.dir/clean

CMakeFiles/Structure.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Codes\structure\c\Structure D:\Codes\structure\c\Structure D:\Codes\structure\c\Structure\cmake-build-debug D:\Codes\structure\c\Structure\cmake-build-debug D:\Codes\structure\c\Structure\cmake-build-debug\CMakeFiles\Structure.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Structure.dir/depend
