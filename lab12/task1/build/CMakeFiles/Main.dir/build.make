# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/build"

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/src/main.c.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/main.c.o: /mnt/c/Users/advor/Desktop/Рабочий\ стол/Проекты/Лабораторные\ работы/C-Programming/lab12/task1/src/main.c
CMakeFiles/Main.dir/src/main.c.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Main.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Main.dir/src/main.c.o -MF CMakeFiles/Main.dir/src/main.c.o.d -o CMakeFiles/Main.dir/src/main.c.o -c "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/src/main.c"

CMakeFiles/Main.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Main.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/src/main.c" > CMakeFiles/Main.dir/src/main.c.i

CMakeFiles/Main.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Main.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/src/main.c" -o CMakeFiles/Main.dir/src/main.c.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/src/main.c.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main: CMakeFiles/Main.dir/src/main.c.o
Main: CMakeFiles/Main.dir/build.make
Main: background/libMY_LIB.so
Main: pipes/libMY_LIB2.so
Main: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: Main
.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1" "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1" "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/build" "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/build" "/mnt/c/Users/advor/Desktop/Рабочий стол/Проекты/Лабораторные работы/C-Programming/lab12/task1/build/CMakeFiles/Main.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Main.dir/depend

