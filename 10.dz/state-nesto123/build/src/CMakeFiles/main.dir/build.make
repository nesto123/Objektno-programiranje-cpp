# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/fran/Documents/obj/dz/10.dz/state-nesto123

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fran/Documents/obj/dz/10.dz/state-nesto123/build

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/main.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Documents/obj/dz/10.dz/state-nesto123/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/main.dir/main.cpp.o"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/main.cpp

src/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/main.cpp > CMakeFiles/main.dir/main.cpp.i

src/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/main.cpp -o CMakeFiles/main.dir/main.cpp.s

src/CMakeFiles/main.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/main.dir/main.cpp.o.requires

src/CMakeFiles/main.dir/main.cpp.o.provides: src/CMakeFiles/main.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/main.cpp.o.provides

src/CMakeFiles/main.dir/main.cpp.o.provides.build: src/CMakeFiles/main.dir/main.cpp.o


src/CMakeFiles/main.dir/game.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Documents/obj/dz/10.dz/state-nesto123/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/main.dir/game.cpp.o"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/game.cpp.o -c /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/game.cpp

src/CMakeFiles/main.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/game.cpp.i"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/game.cpp > CMakeFiles/main.dir/game.cpp.i

src/CMakeFiles/main.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/game.cpp.s"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/game.cpp -o CMakeFiles/main.dir/game.cpp.s

src/CMakeFiles/main.dir/game.cpp.o.requires:

.PHONY : src/CMakeFiles/main.dir/game.cpp.o.requires

src/CMakeFiles/main.dir/game.cpp.o.provides: src/CMakeFiles/main.dir/game.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/game.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/game.cpp.o.provides

src/CMakeFiles/main.dir/game.cpp.o.provides.build: src/CMakeFiles/main.dir/game.cpp.o


src/CMakeFiles/main.dir/world.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/world.cpp.o: ../src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Documents/obj/dz/10.dz/state-nesto123/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/main.dir/world.cpp.o"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/world.cpp.o -c /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/world.cpp

src/CMakeFiles/main.dir/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/world.cpp.i"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/world.cpp > CMakeFiles/main.dir/world.cpp.i

src/CMakeFiles/main.dir/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/world.cpp.s"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/world.cpp -o CMakeFiles/main.dir/world.cpp.s

src/CMakeFiles/main.dir/world.cpp.o.requires:

.PHONY : src/CMakeFiles/main.dir/world.cpp.o.requires

src/CMakeFiles/main.dir/world.cpp.o.provides: src/CMakeFiles/main.dir/world.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/world.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/world.cpp.o.provides

src/CMakeFiles/main.dir/world.cpp.o.provides.build: src/CMakeFiles/main.dir/world.cpp.o


src/CMakeFiles/main.dir/snake.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/snake.cpp.o: ../src/snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Documents/obj/dz/10.dz/state-nesto123/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/main.dir/snake.cpp.o"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/snake.cpp.o -c /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/snake.cpp

src/CMakeFiles/main.dir/snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/snake.cpp.i"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/snake.cpp > CMakeFiles/main.dir/snake.cpp.i

src/CMakeFiles/main.dir/snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/snake.cpp.s"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/snake.cpp -o CMakeFiles/main.dir/snake.cpp.s

src/CMakeFiles/main.dir/snake.cpp.o.requires:

.PHONY : src/CMakeFiles/main.dir/snake.cpp.o.requires

src/CMakeFiles/main.dir/snake.cpp.o.provides: src/CMakeFiles/main.dir/snake.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/snake.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/snake.cpp.o.provides

src/CMakeFiles/main.dir/snake.cpp.o.provides.build: src/CMakeFiles/main.dir/snake.cpp.o


src/CMakeFiles/main.dir/playing_state.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/playing_state.cpp.o: ../src/playing_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Documents/obj/dz/10.dz/state-nesto123/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/main.dir/playing_state.cpp.o"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/playing_state.cpp.o -c /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/playing_state.cpp

src/CMakeFiles/main.dir/playing_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/playing_state.cpp.i"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/playing_state.cpp > CMakeFiles/main.dir/playing_state.cpp.i

src/CMakeFiles/main.dir/playing_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/playing_state.cpp.s"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/playing_state.cpp -o CMakeFiles/main.dir/playing_state.cpp.s

src/CMakeFiles/main.dir/playing_state.cpp.o.requires:

.PHONY : src/CMakeFiles/main.dir/playing_state.cpp.o.requires

src/CMakeFiles/main.dir/playing_state.cpp.o.provides: src/CMakeFiles/main.dir/playing_state.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/playing_state.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/playing_state.cpp.o.provides

src/CMakeFiles/main.dir/playing_state.cpp.o.provides.build: src/CMakeFiles/main.dir/playing_state.cpp.o


src/CMakeFiles/main.dir/aux_states.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/aux_states.cpp.o: ../src/aux_states.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fran/Documents/obj/dz/10.dz/state-nesto123/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/main.dir/aux_states.cpp.o"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/aux_states.cpp.o -c /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/aux_states.cpp

src/CMakeFiles/main.dir/aux_states.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/aux_states.cpp.i"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/aux_states.cpp > CMakeFiles/main.dir/aux_states.cpp.i

src/CMakeFiles/main.dir/aux_states.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/aux_states.cpp.s"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fran/Documents/obj/dz/10.dz/state-nesto123/src/aux_states.cpp -o CMakeFiles/main.dir/aux_states.cpp.s

src/CMakeFiles/main.dir/aux_states.cpp.o.requires:

.PHONY : src/CMakeFiles/main.dir/aux_states.cpp.o.requires

src/CMakeFiles/main.dir/aux_states.cpp.o.provides: src/CMakeFiles/main.dir/aux_states.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/aux_states.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/aux_states.cpp.o.provides

src/CMakeFiles/main.dir/aux_states.cpp.o.provides.build: src/CMakeFiles/main.dir/aux_states.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/game.cpp.o" \
"CMakeFiles/main.dir/world.cpp.o" \
"CMakeFiles/main.dir/snake.cpp.o" \
"CMakeFiles/main.dir/playing_state.cpp.o" \
"CMakeFiles/main.dir/aux_states.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

src/main: src/CMakeFiles/main.dir/main.cpp.o
src/main: src/CMakeFiles/main.dir/game.cpp.o
src/main: src/CMakeFiles/main.dir/world.cpp.o
src/main: src/CMakeFiles/main.dir/snake.cpp.o
src/main: src/CMakeFiles/main.dir/playing_state.cpp.o
src/main: src/CMakeFiles/main.dir/aux_states.cpp.o
src/main: src/CMakeFiles/main.dir/build.make
src/main: /usr/lib/x86_64-linux-gnu/libsfml-system.so
src/main: /usr/lib/x86_64-linux-gnu/libsfml-window.so
src/main: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
src/main: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
src/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fran/Documents/obj/dz/10.dz/state-nesto123/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable main"
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && /usr/bin/cmake -E copy /home/fran/Documents/obj/dz/10.dz/state-nesto123/doc/*.ttf /home/fran/Documents/obj/dz/10.dz/state-nesto123/doc/*.png /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: src/main

.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/main.cpp.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/game.cpp.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/world.cpp.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/snake.cpp.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/playing_state.cpp.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/aux_states.cpp.o.requires

.PHONY : src/CMakeFiles/main.dir/requires

src/CMakeFiles/main.dir/clean:
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /home/fran/Documents/obj/dz/10.dz/state-nesto123/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fran/Documents/obj/dz/10.dz/state-nesto123 /home/fran/Documents/obj/dz/10.dz/state-nesto123/src /home/fran/Documents/obj/dz/10.dz/state-nesto123/build /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src /home/fran/Documents/obj/dz/10.dz/state-nesto123/build/src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

