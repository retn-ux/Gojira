# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/retn/projects/cpp-prj/Gojira

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/retn/projects/cpp-prj/Gojira

# Include any dependencies generated for this target.
include Gojira/fileformat/CMakeFiles/fileformat.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Gojira/fileformat/CMakeFiles/fileformat.dir/compiler_depend.make

# Include the progress variables for this target.
include Gojira/fileformat/CMakeFiles/fileformat.dir/progress.make

# Include the compile flags for this target's objects.
include Gojira/fileformat/CMakeFiles/fileformat.dir/flags.make

Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o: Gojira/fileformat/CMakeFiles/fileformat.dir/flags.make
Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o: Gojira/fileformat/elf/ELFFile.cpp
Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o: Gojira/fileformat/CMakeFiles/fileformat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/retn/projects/cpp-prj/Gojira/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o -MF CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o.d -o CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o -c /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/elf/ELFFile.cpp

Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fileformat.dir/elf/ELFFile.cpp.i"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/elf/ELFFile.cpp > CMakeFiles/fileformat.dir/elf/ELFFile.cpp.i

Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fileformat.dir/elf/ELFFile.cpp.s"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/elf/ELFFile.cpp -o CMakeFiles/fileformat.dir/elf/ELFFile.cpp.s

Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.o: Gojira/fileformat/CMakeFiles/fileformat.dir/flags.make
Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.o: Gojira/fileformat/pe/PEFile.cpp
Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.o: Gojira/fileformat/CMakeFiles/fileformat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/retn/projects/cpp-prj/Gojira/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.o"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.o -MF CMakeFiles/fileformat.dir/pe/PEFile.cpp.o.d -o CMakeFiles/fileformat.dir/pe/PEFile.cpp.o -c /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/pe/PEFile.cpp

Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fileformat.dir/pe/PEFile.cpp.i"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/pe/PEFile.cpp > CMakeFiles/fileformat.dir/pe/PEFile.cpp.i

Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fileformat.dir/pe/PEFile.cpp.s"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/pe/PEFile.cpp -o CMakeFiles/fileformat.dir/pe/PEFile.cpp.s

Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o: Gojira/fileformat/CMakeFiles/fileformat.dir/flags.make
Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o: Gojira/fileformat/mp3/MP3File.cpp
Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o: Gojira/fileformat/CMakeFiles/fileformat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/retn/projects/cpp-prj/Gojira/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o -MF CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o.d -o CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o -c /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/mp3/MP3File.cpp

Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fileformat.dir/mp3/MP3File.cpp.i"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/mp3/MP3File.cpp > CMakeFiles/fileformat.dir/mp3/MP3File.cpp.i

Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fileformat.dir/mp3/MP3File.cpp.s"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/mp3/MP3File.cpp -o CMakeFiles/fileformat.dir/mp3/MP3File.cpp.s

# Object files for target fileformat
fileformat_OBJECTS = \
"CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o" \
"CMakeFiles/fileformat.dir/pe/PEFile.cpp.o" \
"CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o"

# External object files for target fileformat
fileformat_EXTERNAL_OBJECTS =

Gojira/fileformat/libfileformat.a: Gojira/fileformat/CMakeFiles/fileformat.dir/elf/ELFFile.cpp.o
Gojira/fileformat/libfileformat.a: Gojira/fileformat/CMakeFiles/fileformat.dir/pe/PEFile.cpp.o
Gojira/fileformat/libfileformat.a: Gojira/fileformat/CMakeFiles/fileformat.dir/mp3/MP3File.cpp.o
Gojira/fileformat/libfileformat.a: Gojira/fileformat/CMakeFiles/fileformat.dir/build.make
Gojira/fileformat/libfileformat.a: Gojira/fileformat/CMakeFiles/fileformat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/retn/projects/cpp-prj/Gojira/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libfileformat.a"
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && $(CMAKE_COMMAND) -P CMakeFiles/fileformat.dir/cmake_clean_target.cmake
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fileformat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Gojira/fileformat/CMakeFiles/fileformat.dir/build: Gojira/fileformat/libfileformat.a
.PHONY : Gojira/fileformat/CMakeFiles/fileformat.dir/build

Gojira/fileformat/CMakeFiles/fileformat.dir/clean:
	cd /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat && $(CMAKE_COMMAND) -P CMakeFiles/fileformat.dir/cmake_clean.cmake
.PHONY : Gojira/fileformat/CMakeFiles/fileformat.dir/clean

Gojira/fileformat/CMakeFiles/fileformat.dir/depend:
	cd /home/retn/projects/cpp-prj/Gojira && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/retn/projects/cpp-prj/Gojira /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat /home/retn/projects/cpp-prj/Gojira /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat /home/retn/projects/cpp-prj/Gojira/Gojira/fileformat/CMakeFiles/fileformat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Gojira/fileformat/CMakeFiles/fileformat.dir/depend

