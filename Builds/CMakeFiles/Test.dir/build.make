# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /c/Ian/Work/SecuEyesDecoder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /c/Ian/Work/SecuEyesDecoder/Build

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/Main.c.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/Main.c.obj: /c/Ian/Work/SecuEyesDecoder/Main.c
CMakeFiles/Test.dir/Main.c.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/c/Ian/Work/SecuEyesDecoder/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Test.dir/Main.c.obj"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Test.dir/Main.c.obj -MF CMakeFiles/Test.dir/Main.c.obj.d -o CMakeFiles/Test.dir/Main.c.obj -c /c/Ian/Work/SecuEyesDecoder/Main.c

CMakeFiles/Test.dir/Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/Main.c.i"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /c/Ian/Work/SecuEyesDecoder/Main.c > CMakeFiles/Test.dir/Main.c.i

CMakeFiles/Test.dir/Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/Main.c.s"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /c/Ian/Work/SecuEyesDecoder/Main.c -o CMakeFiles/Test.dir/Main.c.s

CMakeFiles/Test.dir/Test/Main.c.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/Test/Main.c.obj: /c/Ian/Work/SecuEyesDecoder/Test/Main.c
CMakeFiles/Test.dir/Test/Main.c.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/c/Ian/Work/SecuEyesDecoder/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Test.dir/Test/Main.c.obj"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Test.dir/Test/Main.c.obj -MF CMakeFiles/Test.dir/Test/Main.c.obj.d -o CMakeFiles/Test.dir/Test/Main.c.obj -c /c/Ian/Work/SecuEyesDecoder/Test/Main.c

CMakeFiles/Test.dir/Test/Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/Test/Main.c.i"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /c/Ian/Work/SecuEyesDecoder/Test/Main.c > CMakeFiles/Test.dir/Test/Main.c.i

CMakeFiles/Test.dir/Test/Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/Test/Main.c.s"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /c/Ian/Work/SecuEyesDecoder/Test/Main.c -o CMakeFiles/Test.dir/Test/Main.c.s

CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj: /c/Ian/Work/SecuEyesDecoder/Test/Sources/Test_Base64.c
CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/c/Ian/Work/SecuEyesDecoder/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj -MF CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj.d -o CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj -c /c/Ian/Work/SecuEyesDecoder/Test/Sources/Test_Base64.c

CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.i"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /c/Ian/Work/SecuEyesDecoder/Test/Sources/Test_Base64.c > CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.i

CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.s"
	/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /c/Ian/Work/SecuEyesDecoder/Test/Sources/Test_Base64.c -o CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/Main.c.obj" \
"CMakeFiles/Test.dir/Test/Main.c.obj" \
"CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/Main.c.obj
Test: CMakeFiles/Test.dir/Test/Main.c.obj
Test: CMakeFiles/Test.dir/Test/Sources/Test_Base64.c.obj
Test: CMakeFiles/Test.dir/build.make
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/c/Ian/Work/SecuEyesDecoder/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test
.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /c/Ian/Work/SecuEyesDecoder/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /c/Ian/Work/SecuEyesDecoder /c/Ian/Work/SecuEyesDecoder /c/Ian/Work/SecuEyesDecoder/Build /c/Ian/Work/SecuEyesDecoder/Build /c/Ian/Work/SecuEyesDecoder/Build/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.dir/depend

