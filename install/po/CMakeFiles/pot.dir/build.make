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
CMAKE_SOURCE_DIR = /home/bruce/Git/vala-emscripten

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bruce/Git/vala-emscripten/install

# Utility rule file for pot.

# Include the progress variables for this target.
include po/CMakeFiles/pot.dir/progress.make

pot: po/CMakeFiles/pot.dir/build.make
	cd /home/bruce/Git/vala-emscripten/install/po && /usr/bin/xgettext -d vala-emscripten -o /home/bruce/Git/vala-emscripten/po/vala-emscripten.pot --keyword="_" --keyword="N_" --from-code=UTF-8 -LC# /home/bruce/Git/vala-emscripten/po/../src/Game.vala /home/bruce/Git/vala-emscripten/po/../src/systems/AnimationSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/RemoveSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/SpawnSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/DisplaySystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/InputSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/CollisionSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/PhysicsSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/ExpireSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/ScoreSystem.vala /home/bruce/Git/vala-emscripten/po/../src/Factory.vala /home/bruce/Git/vala-emscripten/po/../src/util/File.vala /home/bruce/Git/vala-emscripten/po/../src/util/String.vala /home/bruce/Git/vala-emscripten/po/../src/util/Cache.vala /home/bruce/Git/vala-emscripten/po/../src/vala-emscripten.vala /home/bruce/Git/vala-emscripten/po/../src/main.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/graphics/Sprite.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/graphics/Surface.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/files/FileHandle.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/Files.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/sdx.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/Font.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/Matcher.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/entitas.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/Group.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/World.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/Cache.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/Matcher.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/entitas.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/Group.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/World.vala /home/bruce/Git/vala-emscripten/po/../src/entitas/Cache.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/graphics/Sprite.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/graphics/Surface.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/files/FileHandle.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/Files.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/sdx.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/Font.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/files/FileHandle.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/graphics/Sprite.vala /home/bruce/Git/vala-emscripten/po/../src/sdx/graphics/Surface.vala /home/bruce/Git/vala-emscripten/po/../src/systems/AnimationSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/RemoveSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/SpawnSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/DisplaySystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/InputSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/CollisionSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/PhysicsSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/ExpireSystem.vala /home/bruce/Git/vala-emscripten/po/../src/systems/ScoreSystem.vala /home/bruce/Git/vala-emscripten/po/../src/util/File.vala /home/bruce/Git/vala-emscripten/po/../src/util/String.vala /home/bruce/Git/vala-emscripten/po/../src/util/Cache.vala
.PHONY : pot

# Rule to build all files generated by this target.
po/CMakeFiles/pot.dir/build: pot

.PHONY : po/CMakeFiles/pot.dir/build

po/CMakeFiles/pot.dir/clean:
	cd /home/bruce/Git/vala-emscripten/install/po && $(CMAKE_COMMAND) -P CMakeFiles/pot.dir/cmake_clean.cmake
.PHONY : po/CMakeFiles/pot.dir/clean

po/CMakeFiles/pot.dir/depend:
	cd /home/bruce/Git/vala-emscripten/install && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruce/Git/vala-emscripten /home/bruce/Git/vala-emscripten/po /home/bruce/Git/vala-emscripten/install /home/bruce/Git/vala-emscripten/install/po /home/bruce/Git/vala-emscripten/install/po/CMakeFiles/pot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : po/CMakeFiles/pot.dir/depend
