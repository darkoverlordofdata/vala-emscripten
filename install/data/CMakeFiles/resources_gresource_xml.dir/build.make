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

# Utility rule file for resources_gresource_xml.

# Include the progress variables for this target.
include data/CMakeFiles/resources_gresource_xml.dir/progress.make

data/CMakeFiles/resources_gresource_xml: data/resources.gresource.xml.c


data/resources.gresource.xml.c: ../data/resources.gresource.xml
data/resources.gresource.xml.c: ../data/assets/fonts/TitanOne-Regular.ttf
data/resources.gresource.xml.c: ../data/assets/fonts/OpenDyslexic-Bold.otf
data/resources.gresource.xml.c: ../data/assets/images/background.png
data/resources.gresource.xml.c: ../data/assets/images/bang.png
data/resources.gresource.xml.c: ../data/assets/images/bullet.png
data/resources.gresource.xml.c: ../data/assets/images/enemy1.png
data/resources.gresource.xml.c: ../data/assets/images/enemy2.png
data/resources.gresource.xml.c: ../data/assets/images/enemy3.png
data/resources.gresource.xml.c: ../data/assets/images/explosion.png
data/resources.gresource.xml.c: ../data/assets/images/spaceshipspr.png
data/resources.gresource.xml.c: ../data/assets/images/star.png
data/resources.gresource.xml.c: ../data/assets/sounds/asplode.wav
data/resources.gresource.xml.c: ../data/assets/sounds/pew.wav
data/resources.gresource.xml.c: ../data/assets/sounds/smallasplode.wav
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bruce/Git/vala-emscripten/install/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating resources.gresource.xml.c"
	cd /home/bruce/Git/vala-emscripten/install/data && glib-compile-resources --sourcedir=/home/bruce/Git/vala-emscripten/data --generate-source --target=/home/bruce/Git/vala-emscripten/install/data/resources.gresource.xml.c /home/bruce/Git/vala-emscripten/data/resources.gresource.xml
	cd /home/bruce/Git/vala-emscripten/install/data && glib-compile-resources --sourcedir=/home/bruce/Git/vala-emscripten/data --generate-header --target=/home/bruce/Git/vala-emscripten/install/data/resources.gresource.xml.h /home/bruce/Git/vala-emscripten/data/resources.gresource.xml

resources_gresource_xml: data/CMakeFiles/resources_gresource_xml
resources_gresource_xml: data/resources.gresource.xml.c
resources_gresource_xml: data/CMakeFiles/resources_gresource_xml.dir/build.make

.PHONY : resources_gresource_xml

# Rule to build all files generated by this target.
data/CMakeFiles/resources_gresource_xml.dir/build: resources_gresource_xml

.PHONY : data/CMakeFiles/resources_gresource_xml.dir/build

data/CMakeFiles/resources_gresource_xml.dir/clean:
	cd /home/bruce/Git/vala-emscripten/install/data && $(CMAKE_COMMAND) -P CMakeFiles/resources_gresource_xml.dir/cmake_clean.cmake
.PHONY : data/CMakeFiles/resources_gresource_xml.dir/clean

data/CMakeFiles/resources_gresource_xml.dir/depend:
	cd /home/bruce/Git/vala-emscripten/install && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruce/Git/vala-emscripten /home/bruce/Git/vala-emscripten/data /home/bruce/Git/vala-emscripten/install /home/bruce/Git/vala-emscripten/install/data /home/bruce/Git/vala-emscripten/install/data/CMakeFiles/resources_gresource_xml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : data/CMakeFiles/resources_gresource_xml.dir/depend

