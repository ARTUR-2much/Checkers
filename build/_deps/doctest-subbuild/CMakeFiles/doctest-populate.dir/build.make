# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\PROJECT\checkers\build\_deps\doctest-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\PROJECT\checkers\build\_deps\doctest-subbuild

# Utility rule file for doctest-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/doctest-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/doctest-populate.dir/progress.make

CMakeFiles/doctest-populate: CMakeFiles/doctest-populate-complete

CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-install
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-mkdir
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-download
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-patch
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-configure
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-build
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-install
CMakeFiles/doctest-populate-complete: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'doctest-populate'"
	C:\mingw64\bin\cmake.exe -E make_directory C:/PROJECT/checkers/build/_deps/doctest-subbuild/CMakeFiles
	C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/CMakeFiles/doctest-populate-complete
	C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-done

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update:
.PHONY : doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-build: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'doctest-populate'"
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E echo_append
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-build

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-configure: doctest-populate-prefix/tmp/doctest-populate-cfgcmd.txt
doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-configure: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'doctest-populate'"
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E echo_append
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-configure

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-download: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-gitinfo.txt
doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-download: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'doctest-populate'"
	cd /d C:\PROJECT\checkers\build\_deps && C:\mingw64\bin\cmake.exe -P C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/tmp/doctest-populate-gitclone.cmake
	cd /d C:\PROJECT\checkers\build\_deps && C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-download

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-install: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'doctest-populate'"
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E echo_append
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-install

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'doctest-populate'"
	C:\mingw64\bin\cmake.exe -Dcfgdir= -P C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/tmp/doctest-populate-mkdirs.cmake
	C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-mkdir

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-patch: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'doctest-populate'"
	C:\mingw64\bin\cmake.exe -E echo_append
	C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-patch

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update:
.PHONY : doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-test: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'doctest-populate'"
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E echo_append
	cd /d C:\PROJECT\checkers\build\_deps\doctest-build && C:\mingw64\bin\cmake.exe -E touch C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-test

doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'doctest-populate'"
	cd /d C:\PROJECT\checkers\build\_deps\doctest-src && C:\mingw64\bin\cmake.exe -P C:/PROJECT/checkers/build/_deps/doctest-subbuild/doctest-populate-prefix/tmp/doctest-populate-gitupdate.cmake

doctest-populate: CMakeFiles/doctest-populate
doctest-populate: CMakeFiles/doctest-populate-complete
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-build
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-configure
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-download
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-install
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-mkdir
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-patch
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-test
doctest-populate: doctest-populate-prefix/src/doctest-populate-stamp/doctest-populate-update
doctest-populate: CMakeFiles/doctest-populate.dir/build.make
.PHONY : doctest-populate

# Rule to build all files generated by this target.
CMakeFiles/doctest-populate.dir/build: doctest-populate
.PHONY : CMakeFiles/doctest-populate.dir/build

CMakeFiles/doctest-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\doctest-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/doctest-populate.dir/clean

CMakeFiles/doctest-populate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\PROJECT\checkers\build\_deps\doctest-subbuild C:\PROJECT\checkers\build\_deps\doctest-subbuild C:\PROJECT\checkers\build\_deps\doctest-subbuild C:\PROJECT\checkers\build\_deps\doctest-subbuild C:\PROJECT\checkers\build\_deps\doctest-subbuild\CMakeFiles\doctest-populate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/doctest-populate.dir/depend

