# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build

# Include any dependencies generated for this target.
include CMakeFiles/Cloth.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Cloth.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Cloth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cloth.dir/flags.make

CMakeFiles/Cloth.dir/src/Camera.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/Camera.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Camera.cpp
CMakeFiles/Cloth.dir/src/Camera.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cloth.dir/src/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/Camera.cpp.o -MF CMakeFiles/Cloth.dir/src/Camera.cpp.o.d -o CMakeFiles/Cloth.dir/src/Camera.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Camera.cpp

CMakeFiles/Cloth.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Camera.cpp > CMakeFiles/Cloth.dir/src/Camera.cpp.i

CMakeFiles/Cloth.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Camera.cpp -o CMakeFiles/Cloth.dir/src/Camera.cpp.s

CMakeFiles/Cloth.dir/src/Cloth.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/Cloth.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Cloth.cpp
CMakeFiles/Cloth.dir/src/Cloth.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Cloth.dir/src/Cloth.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/Cloth.cpp.o -MF CMakeFiles/Cloth.dir/src/Cloth.cpp.o.d -o CMakeFiles/Cloth.dir/src/Cloth.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Cloth.cpp

CMakeFiles/Cloth.dir/src/Cloth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/Cloth.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Cloth.cpp > CMakeFiles/Cloth.dir/src/Cloth.cpp.i

CMakeFiles/Cloth.dir/src/Cloth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/Cloth.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Cloth.cpp -o CMakeFiles/Cloth.dir/src/Cloth.cpp.s

CMakeFiles/Cloth.dir/src/Particle.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/Particle.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Particle.cpp
CMakeFiles/Cloth.dir/src/Particle.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Cloth.dir/src/Particle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/Particle.cpp.o -MF CMakeFiles/Cloth.dir/src/Particle.cpp.o.d -o CMakeFiles/Cloth.dir/src/Particle.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Particle.cpp

CMakeFiles/Cloth.dir/src/Particle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/Particle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Particle.cpp > CMakeFiles/Cloth.dir/src/Particle.cpp.i

CMakeFiles/Cloth.dir/src/Particle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/Particle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Particle.cpp -o CMakeFiles/Cloth.dir/src/Particle.cpp.s

CMakeFiles/Cloth.dir/src/Shader.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/Shader.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Shader.cpp
CMakeFiles/Cloth.dir/src/Shader.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Cloth.dir/src/Shader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/Shader.cpp.o -MF CMakeFiles/Cloth.dir/src/Shader.cpp.o.d -o CMakeFiles/Cloth.dir/src/Shader.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Shader.cpp

CMakeFiles/Cloth.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/Shader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Shader.cpp > CMakeFiles/Cloth.dir/src/Shader.cpp.i

CMakeFiles/Cloth.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/Shader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Shader.cpp -o CMakeFiles/Cloth.dir/src/Shader.cpp.s

CMakeFiles/Cloth.dir/src/Spring.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/Spring.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Spring.cpp
CMakeFiles/Cloth.dir/src/Spring.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Cloth.dir/src/Spring.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/Spring.cpp.o -MF CMakeFiles/Cloth.dir/src/Spring.cpp.o.d -o CMakeFiles/Cloth.dir/src/Spring.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Spring.cpp

CMakeFiles/Cloth.dir/src/Spring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/Spring.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Spring.cpp > CMakeFiles/Cloth.dir/src/Spring.cpp.i

CMakeFiles/Cloth.dir/src/Spring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/Spring.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Spring.cpp -o CMakeFiles/Cloth.dir/src/Spring.cpp.s

CMakeFiles/Cloth.dir/src/Triangle.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/Triangle.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Triangle.cpp
CMakeFiles/Cloth.dir/src/Triangle.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Cloth.dir/src/Triangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/Triangle.cpp.o -MF CMakeFiles/Cloth.dir/src/Triangle.cpp.o.d -o CMakeFiles/Cloth.dir/src/Triangle.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Triangle.cpp

CMakeFiles/Cloth.dir/src/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/Triangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Triangle.cpp > CMakeFiles/Cloth.dir/src/Triangle.cpp.i

CMakeFiles/Cloth.dir/src/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/Triangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Triangle.cpp -o CMakeFiles/Cloth.dir/src/Triangle.cpp.s

CMakeFiles/Cloth.dir/src/Window.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/Window.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Window.cpp
CMakeFiles/Cloth.dir/src/Window.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Cloth.dir/src/Window.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/Window.cpp.o -MF CMakeFiles/Cloth.dir/src/Window.cpp.o.d -o CMakeFiles/Cloth.dir/src/Window.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Window.cpp

CMakeFiles/Cloth.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/Window.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Window.cpp > CMakeFiles/Cloth.dir/src/Window.cpp.i

CMakeFiles/Cloth.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/Window.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/Window.cpp -o CMakeFiles/Cloth.dir/src/Window.cpp.s

CMakeFiles/Cloth.dir/src/main.cpp.o: CMakeFiles/Cloth.dir/flags.make
CMakeFiles/Cloth.dir/src/main.cpp.o: /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/main.cpp
CMakeFiles/Cloth.dir/src/main.cpp.o: CMakeFiles/Cloth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Cloth.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cloth.dir/src/main.cpp.o -MF CMakeFiles/Cloth.dir/src/main.cpp.o.d -o CMakeFiles/Cloth.dir/src/main.cpp.o -c /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/main.cpp

CMakeFiles/Cloth.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cloth.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/main.cpp > CMakeFiles/Cloth.dir/src/main.cpp.i

CMakeFiles/Cloth.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cloth.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/src/main.cpp -o CMakeFiles/Cloth.dir/src/main.cpp.s

# Object files for target Cloth
Cloth_OBJECTS = \
"CMakeFiles/Cloth.dir/src/Camera.cpp.o" \
"CMakeFiles/Cloth.dir/src/Cloth.cpp.o" \
"CMakeFiles/Cloth.dir/src/Particle.cpp.o" \
"CMakeFiles/Cloth.dir/src/Shader.cpp.o" \
"CMakeFiles/Cloth.dir/src/Spring.cpp.o" \
"CMakeFiles/Cloth.dir/src/Triangle.cpp.o" \
"CMakeFiles/Cloth.dir/src/Window.cpp.o" \
"CMakeFiles/Cloth.dir/src/main.cpp.o"

# External object files for target Cloth
Cloth_EXTERNAL_OBJECTS =

Cloth: CMakeFiles/Cloth.dir/src/Camera.cpp.o
Cloth: CMakeFiles/Cloth.dir/src/Cloth.cpp.o
Cloth: CMakeFiles/Cloth.dir/src/Particle.cpp.o
Cloth: CMakeFiles/Cloth.dir/src/Shader.cpp.o
Cloth: CMakeFiles/Cloth.dir/src/Spring.cpp.o
Cloth: CMakeFiles/Cloth.dir/src/Triangle.cpp.o
Cloth: CMakeFiles/Cloth.dir/src/Window.cpp.o
Cloth: CMakeFiles/Cloth.dir/src/main.cpp.o
Cloth: CMakeFiles/Cloth.dir/build.make
Cloth: /opt/homebrew/lib/libglfw.3.3.dylib
Cloth: CMakeFiles/Cloth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Cloth"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cloth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cloth.dir/build: Cloth
.PHONY : CMakeFiles/Cloth.dir/build

CMakeFiles/Cloth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cloth.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cloth.dir/clean

CMakeFiles/Cloth.dir/depend:
	cd /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build /Users/naryungkim/Documents/GitHub/CSE169/ClothSimulator/build/CMakeFiles/Cloth.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cloth.dir/depend

