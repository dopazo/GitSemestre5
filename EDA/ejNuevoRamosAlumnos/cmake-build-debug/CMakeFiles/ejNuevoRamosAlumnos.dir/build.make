# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ejNuevoRamosAlumnos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ejNuevoRamosAlumnos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ejNuevoRamosAlumnos.dir/flags.make

CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj: CMakeFiles/ejNuevoRamosAlumnos.dir/flags.make
CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ejNuevoRamosAlumnos.dir\main.c.obj   -c C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\main.c

CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\main.c > CMakeFiles\ejNuevoRamosAlumnos.dir\main.c.i

CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\main.c -o CMakeFiles\ejNuevoRamosAlumnos.dir\main.c.s

CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.requires:

.PHONY : CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.requires

CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.provides: CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\ejNuevoRamosAlumnos.dir\build.make CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.provides

CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.provides.build: CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj


# Object files for target ejNuevoRamosAlumnos
ejNuevoRamosAlumnos_OBJECTS = \
"CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj"

# External object files for target ejNuevoRamosAlumnos
ejNuevoRamosAlumnos_EXTERNAL_OBJECTS =

ejNuevoRamosAlumnos.exe: CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj
ejNuevoRamosAlumnos.exe: CMakeFiles/ejNuevoRamosAlumnos.dir/build.make
ejNuevoRamosAlumnos.exe: CMakeFiles/ejNuevoRamosAlumnos.dir/linklibs.rsp
ejNuevoRamosAlumnos.exe: CMakeFiles/ejNuevoRamosAlumnos.dir/objects1.rsp
ejNuevoRamosAlumnos.exe: CMakeFiles/ejNuevoRamosAlumnos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ejNuevoRamosAlumnos.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ejNuevoRamosAlumnos.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ejNuevoRamosAlumnos.dir/build: ejNuevoRamosAlumnos.exe

.PHONY : CMakeFiles/ejNuevoRamosAlumnos.dir/build

CMakeFiles/ejNuevoRamosAlumnos.dir/requires: CMakeFiles/ejNuevoRamosAlumnos.dir/main.c.obj.requires

.PHONY : CMakeFiles/ejNuevoRamosAlumnos.dir/requires

CMakeFiles/ejNuevoRamosAlumnos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ejNuevoRamosAlumnos.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ejNuevoRamosAlumnos.dir/clean

CMakeFiles/ejNuevoRamosAlumnos.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\cmake-build-debug C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\cmake-build-debug C:\Users\dopaz\CLionProjects\ejNuevoRamosAlumnos\cmake-build-debug\CMakeFiles\ejNuevoRamosAlumnos.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ejNuevoRamosAlumnos.dir/depend

