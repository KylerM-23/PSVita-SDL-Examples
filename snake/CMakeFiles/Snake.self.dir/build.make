# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kyler/samples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kyler/samples

# Utility rule file for Snake.self.

# Include the progress variables for this target.
include snake/CMakeFiles/Snake.self.dir/progress.make

snake/CMakeFiles/Snake.self: snake/Snake.self.out
	cd /home/kyler/samples/snake && /usr/bin/cmake -E copy /home/kyler/samples/snake/Snake.self.out Snake.self

snake/Snake.self.out: snake/Snake.velf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Creating SELF Snake.self"
	cd /home/kyler/samples/snake && /usr/local/vitasdk/bin/vita-make-fself -c -s /home/kyler/samples/snake/Snake.velf /home/kyler/samples/snake/Snake.self.out

snake/Snake.velf:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating Snake.velf"
	cd /home/kyler/samples/snake && /usr/bin/cmake -E touch_nocreate /home/kyler/samples/snake/Snake.velf

Snake.self: snake/CMakeFiles/Snake.self
Snake.self: snake/Snake.self.out
Snake.self: snake/Snake.velf
Snake.self: snake/CMakeFiles/Snake.self.dir/build.make

.PHONY : Snake.self

# Rule to build all files generated by this target.
snake/CMakeFiles/Snake.self.dir/build: Snake.self

.PHONY : snake/CMakeFiles/Snake.self.dir/build

snake/CMakeFiles/Snake.self.dir/clean:
	cd /home/kyler/samples/snake && $(CMAKE_COMMAND) -P CMakeFiles/Snake.self.dir/cmake_clean.cmake
.PHONY : snake/CMakeFiles/Snake.self.dir/clean

snake/CMakeFiles/Snake.self.dir/depend:
	cd /home/kyler/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kyler/samples /home/kyler/samples/snake /home/kyler/samples /home/kyler/samples/snake /home/kyler/samples/snake/CMakeFiles/Snake.self.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : snake/CMakeFiles/Snake.self.dir/depend
