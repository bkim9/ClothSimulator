# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Applications/CMake.app/Contents/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CMake.app/Contents/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/CMakeFiles /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Cloth

# Build rule for target.
Cloth: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Cloth
.PHONY : Cloth

# fast build rule for target.
Cloth/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/build
.PHONY : Cloth/fast

src/Camera.o: src/Camera.cpp.o
.PHONY : src/Camera.o

# target to build an object file
src/Camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Camera.cpp.o
.PHONY : src/Camera.cpp.o

src/Camera.i: src/Camera.cpp.i
.PHONY : src/Camera.i

# target to preprocess a source file
src/Camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Camera.cpp.i
.PHONY : src/Camera.cpp.i

src/Camera.s: src/Camera.cpp.s
.PHONY : src/Camera.s

# target to generate assembly for a file
src/Camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Camera.cpp.s
.PHONY : src/Camera.cpp.s

src/Cloth.o: src/Cloth.cpp.o
.PHONY : src/Cloth.o

# target to build an object file
src/Cloth.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Cloth.cpp.o
.PHONY : src/Cloth.cpp.o

src/Cloth.i: src/Cloth.cpp.i
.PHONY : src/Cloth.i

# target to preprocess a source file
src/Cloth.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Cloth.cpp.i
.PHONY : src/Cloth.cpp.i

src/Cloth.s: src/Cloth.cpp.s
.PHONY : src/Cloth.s

# target to generate assembly for a file
src/Cloth.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Cloth.cpp.s
.PHONY : src/Cloth.cpp.s

src/Particle.o: src/Particle.cpp.o
.PHONY : src/Particle.o

# target to build an object file
src/Particle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Particle.cpp.o
.PHONY : src/Particle.cpp.o

src/Particle.i: src/Particle.cpp.i
.PHONY : src/Particle.i

# target to preprocess a source file
src/Particle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Particle.cpp.i
.PHONY : src/Particle.cpp.i

src/Particle.s: src/Particle.cpp.s
.PHONY : src/Particle.s

# target to generate assembly for a file
src/Particle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Particle.cpp.s
.PHONY : src/Particle.cpp.s

src/Shader.o: src/Shader.cpp.o
.PHONY : src/Shader.o

# target to build an object file
src/Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Shader.cpp.o
.PHONY : src/Shader.cpp.o

src/Shader.i: src/Shader.cpp.i
.PHONY : src/Shader.i

# target to preprocess a source file
src/Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Shader.cpp.i
.PHONY : src/Shader.cpp.i

src/Shader.s: src/Shader.cpp.s
.PHONY : src/Shader.s

# target to generate assembly for a file
src/Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Shader.cpp.s
.PHONY : src/Shader.cpp.s

src/Spring.o: src/Spring.cpp.o
.PHONY : src/Spring.o

# target to build an object file
src/Spring.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Spring.cpp.o
.PHONY : src/Spring.cpp.o

src/Spring.i: src/Spring.cpp.i
.PHONY : src/Spring.i

# target to preprocess a source file
src/Spring.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Spring.cpp.i
.PHONY : src/Spring.cpp.i

src/Spring.s: src/Spring.cpp.s
.PHONY : src/Spring.s

# target to generate assembly for a file
src/Spring.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Spring.cpp.s
.PHONY : src/Spring.cpp.s

src/Triangle.o: src/Triangle.cpp.o
.PHONY : src/Triangle.o

# target to build an object file
src/Triangle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Triangle.cpp.o
.PHONY : src/Triangle.cpp.o

src/Triangle.i: src/Triangle.cpp.i
.PHONY : src/Triangle.i

# target to preprocess a source file
src/Triangle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Triangle.cpp.i
.PHONY : src/Triangle.cpp.i

src/Triangle.s: src/Triangle.cpp.s
.PHONY : src/Triangle.s

# target to generate assembly for a file
src/Triangle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Triangle.cpp.s
.PHONY : src/Triangle.cpp.s

src/Window.o: src/Window.cpp.o
.PHONY : src/Window.o

# target to build an object file
src/Window.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Window.cpp.o
.PHONY : src/Window.cpp.o

src/Window.i: src/Window.cpp.i
.PHONY : src/Window.i

# target to preprocess a source file
src/Window.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Window.cpp.i
.PHONY : src/Window.cpp.i

src/Window.s: src/Window.cpp.s
.PHONY : src/Window.s

# target to generate assembly for a file
src/Window.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Cloth.dir/build.make CMakeFiles/Cloth.dir/src/Window.cpp.s
.PHONY : src/Window.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Cloth"
	@echo "... src/Camera.o"
	@echo "... src/Camera.i"
	@echo "... src/Camera.s"
	@echo "... src/Cloth.o"
	@echo "... src/Cloth.i"
	@echo "... src/Cloth.s"
	@echo "... src/Particle.o"
	@echo "... src/Particle.i"
	@echo "... src/Particle.s"
	@echo "... src/Shader.o"
	@echo "... src/Shader.i"
	@echo "... src/Shader.s"
	@echo "... src/Spring.o"
	@echo "... src/Spring.i"
	@echo "... src/Spring.s"
	@echo "... src/Triangle.o"
	@echo "... src/Triangle.i"
	@echo "... src/Triangle.s"
	@echo "... src/Window.o"
	@echo "... src/Window.i"
	@echo "... src/Window.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

