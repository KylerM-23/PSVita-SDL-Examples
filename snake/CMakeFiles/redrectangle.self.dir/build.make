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

# Utility rule file for redrectangle.self.

# Include the progress variables for this target.
include sdl2/snake/CMakeFiles/redrectangle.self.dir/progress.make

sdl2/snake/CMakeFiles/redrectangle.self: sdl2/snake/redrectangle.self.out
	cd /home/kyler/samples/sdl2/snake && /usr/bin/cmake -E copy /home/kyler/samples/sdl2/snake/redrectangle.self.out redrectangle.self

sdl2/snake/redrectangle.self.out: sdl2/snake/redrectangle.velf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Creating SELF redrectangle.self"
	cd /home/kyler/samples/sdl2/snake && /usr/local/vitasdk/bin/vita-make-fself -c -s /home/kyler/samples/sdl2/snake/redrectangle.velf /home/kyler/samples/sdl2/snake/redrectangle.self.out

sdl2/snake/redrectangle.velf:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating redrectangle.velf"
	cd /home/kyler/samples/sdl2/snake && /usr/bin/cmake -E touch_nocreate /home/kyler/samples/sdl2/snake/redrectangle.velf

redrectangle.self: sdl2/snake/CMakeFiles/redrectangle.self
redrectangle.self: sdl2/snake/redrectangle.self.out
redrectangle.self: sdl2/snake/redrectangle.velf
redrectangle.self: sdl2/snake/CMakeFiles/redrectangle.self.dir/build.make

.PHONY : redrectangle.self

# Rule to build all files generated by this target.
sdl2/snake/CMakeFiles/redrectangle.self.dir/build: redrectangle.self

.PHONY : sdl2/snake/CMakeFiles/redrectangle.self.dir/build

sdl2/snake/CMakeFiles/redrectangle.self.dir/clean:
	cd /home/kyler/samples/sdl2/snake && $(CMAKE_COMMAND) -P CMakeFiles/redrectangle.self.dir/cmake_clean.cmake
.PHONY : sdl2/snake/CMakeFiles/redrectangle.self.dir/clean

sdl2/snake/CMakeFiles/redrectangle.self.dir/depend:
	cd /home/kyler/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kyler/samples /home/kyler/samples/sdl2/snake /home/kyler/samples /home/kyler/samples/sdl2/snake /home/kyler/samples/sdl2/snake/CMakeFiles/redrectangle.self.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sdl2/snake/CMakeFiles/redrectangle.self.dir/depend
