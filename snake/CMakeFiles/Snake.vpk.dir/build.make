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

# Utility rule file for Snake.vpk.

# Include the progress variables for this target.
include snake/CMakeFiles/Snake.vpk.dir/progress.make

snake/CMakeFiles/Snake.vpk: snake/Snake.vpk.out
	cd /home/kyler/samples/snake && /usr/bin/cmake -E copy /home/kyler/samples/snake/Snake.vpk.out Snake.vpk

snake/Snake.vpk.out: snake/Snake.vpk_param.sfo
snake/Snake.vpk.out: snake/Snake.self
snake/Snake.vpk.out: snake/sce_sys/icon0.png
snake/Snake.vpk.out: snake/sce_sys/livearea/contents/bg.png
snake/Snake.vpk.out: snake/sce_sys/livearea/contents/startup.png
snake/Snake.vpk.out: snake/sce_sys/livearea/contents/template.xml
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building vpk Snake.vpk"
	cd /home/kyler/samples/snake && /usr/local/vitasdk/bin/vita-pack-vpk -a /home/kyler/samples/snake/sce_sys/icon0.png=sce_sys/icon0.png -a /home/kyler/samples/snake/sce_sys/livearea/contents/bg.png=sce_sys/livearea/contents/bg.png -a /home/kyler/samples/snake/sce_sys/livearea/contents/startup.png=sce_sys/livearea/contents/startup.png -a /home/kyler/samples/snake/sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml -s /home/kyler/samples/snake/Snake.vpk_param.sfo -b /home/kyler/samples/snake/Snake.self /home/kyler/samples/snake/Snake.vpk.out

snake/Snake.vpk_param.sfo: snake/Snake.self
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating param.sfo for Snake.vpk"
	cd /home/kyler/samples/snake && /usr/local/vitasdk/bin/vita-mksfoex -s APP_VER=01.00 -s TITLE_ID=VSDK00017 Snake /home/kyler/samples/snake/Snake.vpk_param.sfo

Snake.vpk: snake/CMakeFiles/Snake.vpk
Snake.vpk: snake/Snake.vpk.out
Snake.vpk: snake/Snake.vpk_param.sfo
Snake.vpk: snake/CMakeFiles/Snake.vpk.dir/build.make

.PHONY : Snake.vpk

# Rule to build all files generated by this target.
snake/CMakeFiles/Snake.vpk.dir/build: Snake.vpk

.PHONY : snake/CMakeFiles/Snake.vpk.dir/build

snake/CMakeFiles/Snake.vpk.dir/clean:
	cd /home/kyler/samples/snake && $(CMAKE_COMMAND) -P CMakeFiles/Snake.vpk.dir/cmake_clean.cmake
.PHONY : snake/CMakeFiles/Snake.vpk.dir/clean

snake/CMakeFiles/Snake.vpk.dir/depend:
	cd /home/kyler/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kyler/samples /home/kyler/samples/snake /home/kyler/samples /home/kyler/samples/snake /home/kyler/samples/snake/CMakeFiles/Snake.vpk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : snake/CMakeFiles/Snake.vpk.dir/depend
