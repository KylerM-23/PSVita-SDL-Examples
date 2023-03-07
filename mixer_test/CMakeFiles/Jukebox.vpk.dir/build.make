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

# Utility rule file for Jukebox.vpk.

# Include the progress variables for this target.
include mixer_test/CMakeFiles/Jukebox.vpk.dir/progress.make

mixer_test/CMakeFiles/Jukebox.vpk: mixer_test/Jukebox.vpk.out
	cd /home/kyler/samples/mixer_test && /usr/bin/cmake -E copy /home/kyler/samples/mixer_test/Jukebox.vpk.out Jukebox.vpk

mixer_test/Jukebox.vpk.out: mixer_test/Jukebox.vpk_param.sfo
mixer_test/Jukebox.vpk.out: mixer_test/Jukebox.self
mixer_test/Jukebox.vpk.out: mixer_test/sce_sys/icon0.png
mixer_test/Jukebox.vpk.out: mixer_test/sce_sys/livearea/contents/bg.png
mixer_test/Jukebox.vpk.out: mixer_test/sce_sys/livearea/contents/startup.png
mixer_test/Jukebox.vpk.out: mixer_test/sce_sys/livearea/contents/template.xml
mixer_test/Jukebox.vpk.out: mixer_test/music/L_Estro_Armonico.mp3
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building vpk Jukebox.vpk"
	cd /home/kyler/samples/mixer_test && /usr/local/vitasdk/bin/vita-pack-vpk -a /home/kyler/samples/mixer_test/sce_sys/icon0.png=sce_sys/icon0.png -a /home/kyler/samples/mixer_test/sce_sys/livearea/contents/bg.png=sce_sys/livearea/contents/bg.png -a /home/kyler/samples/mixer_test/sce_sys/livearea/contents/startup.png=sce_sys/livearea/contents/startup.png -a /home/kyler/samples/mixer_test/sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml -a /home/kyler/samples/mixer_test/music/L_Estro_Armonico.mp3=music/L_Estro_Armonico.mp3 -s /home/kyler/samples/mixer_test/Jukebox.vpk_param.sfo -b /home/kyler/samples/mixer_test/Jukebox.self /home/kyler/samples/mixer_test/Jukebox.vpk.out

mixer_test/Jukebox.vpk_param.sfo: mixer_test/Jukebox.self
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kyler/samples/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating param.sfo for Jukebox.vpk"
	cd /home/kyler/samples/mixer_test && /usr/local/vitasdk/bin/vita-mksfoex -s APP_VER=01.00 -s TITLE_ID=VSDK10022 "Mixer Test" /home/kyler/samples/mixer_test/Jukebox.vpk_param.sfo

Jukebox.vpk: mixer_test/CMakeFiles/Jukebox.vpk
Jukebox.vpk: mixer_test/Jukebox.vpk.out
Jukebox.vpk: mixer_test/Jukebox.vpk_param.sfo
Jukebox.vpk: mixer_test/CMakeFiles/Jukebox.vpk.dir/build.make

.PHONY : Jukebox.vpk

# Rule to build all files generated by this target.
mixer_test/CMakeFiles/Jukebox.vpk.dir/build: Jukebox.vpk

.PHONY : mixer_test/CMakeFiles/Jukebox.vpk.dir/build

mixer_test/CMakeFiles/Jukebox.vpk.dir/clean:
	cd /home/kyler/samples/mixer_test && $(CMAKE_COMMAND) -P CMakeFiles/Jukebox.vpk.dir/cmake_clean.cmake
.PHONY : mixer_test/CMakeFiles/Jukebox.vpk.dir/clean

mixer_test/CMakeFiles/Jukebox.vpk.dir/depend:
	cd /home/kyler/samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kyler/samples /home/kyler/samples/mixer_test /home/kyler/samples /home/kyler/samples/mixer_test /home/kyler/samples/mixer_test/CMakeFiles/Jukebox.vpk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : mixer_test/CMakeFiles/Jukebox.vpk.dir/depend

