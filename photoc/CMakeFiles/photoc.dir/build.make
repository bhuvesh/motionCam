# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/bhuvesh/pclub/photoc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bhuvesh/pclub/photoc

# Include any dependencies generated for this target.
include CMakeFiles/photoc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/photoc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/photoc.dir/flags.make

CMakeFiles/photoc.dir/photoc.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/photoc.cpp.o: photoc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/photoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/photoc.cpp.o -c /home/bhuvesh/pclub/photoc/photoc.cpp

CMakeFiles/photoc.dir/photoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/photoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/photoc.cpp > CMakeFiles/photoc.dir/photoc.cpp.i

CMakeFiles/photoc.dir/photoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/photoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/photoc.cpp -o CMakeFiles/photoc.dir/photoc.cpp.s

CMakeFiles/photoc.dir/photoc.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/photoc.cpp.o.requires

CMakeFiles/photoc.dir/photoc.cpp.o.provides: CMakeFiles/photoc.dir/photoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/photoc.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/photoc.cpp.o.provides

CMakeFiles/photoc.dir/photoc.cpp.o.provides.build: CMakeFiles/photoc.dir/photoc.cpp.o

CMakeFiles/photoc.dir/bifi.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/bifi.cpp.o: bifi.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/bifi.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/bifi.cpp.o -c /home/bhuvesh/pclub/photoc/bifi.cpp

CMakeFiles/photoc.dir/bifi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/bifi.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/bifi.cpp > CMakeFiles/photoc.dir/bifi.cpp.i

CMakeFiles/photoc.dir/bifi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/bifi.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/bifi.cpp -o CMakeFiles/photoc.dir/bifi.cpp.s

CMakeFiles/photoc.dir/bifi.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/bifi.cpp.o.requires

CMakeFiles/photoc.dir/bifi.cpp.o.provides: CMakeFiles/photoc.dir/bifi.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/bifi.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/bifi.cpp.o.provides

CMakeFiles/photoc.dir/bifi.cpp.o.provides.build: CMakeFiles/photoc.dir/bifi.cpp.o

CMakeFiles/photoc.dir/blur.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/blur.cpp.o: blur.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/blur.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/blur.cpp.o -c /home/bhuvesh/pclub/photoc/blur.cpp

CMakeFiles/photoc.dir/blur.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/blur.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/blur.cpp > CMakeFiles/photoc.dir/blur.cpp.i

CMakeFiles/photoc.dir/blur.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/blur.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/blur.cpp -o CMakeFiles/photoc.dir/blur.cpp.s

CMakeFiles/photoc.dir/blur.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/blur.cpp.o.requires

CMakeFiles/photoc.dir/blur.cpp.o.provides: CMakeFiles/photoc.dir/blur.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/blur.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/blur.cpp.o.provides

CMakeFiles/photoc.dir/blur.cpp.o.provides.build: CMakeFiles/photoc.dir/blur.cpp.o

CMakeFiles/photoc.dir/canny.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/canny.cpp.o: canny.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/canny.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/canny.cpp.o -c /home/bhuvesh/pclub/photoc/canny.cpp

CMakeFiles/photoc.dir/canny.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/canny.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/canny.cpp > CMakeFiles/photoc.dir/canny.cpp.i

CMakeFiles/photoc.dir/canny.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/canny.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/canny.cpp -o CMakeFiles/photoc.dir/canny.cpp.s

CMakeFiles/photoc.dir/canny.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/canny.cpp.o.requires

CMakeFiles/photoc.dir/canny.cpp.o.provides: CMakeFiles/photoc.dir/canny.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/canny.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/canny.cpp.o.provides

CMakeFiles/photoc.dir/canny.cpp.o.provides.build: CMakeFiles/photoc.dir/canny.cpp.o

CMakeFiles/photoc.dir/grayscale.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/grayscale.cpp.o: grayscale.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/grayscale.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/grayscale.cpp.o -c /home/bhuvesh/pclub/photoc/grayscale.cpp

CMakeFiles/photoc.dir/grayscale.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/grayscale.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/grayscale.cpp > CMakeFiles/photoc.dir/grayscale.cpp.i

CMakeFiles/photoc.dir/grayscale.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/grayscale.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/grayscale.cpp -o CMakeFiles/photoc.dir/grayscale.cpp.s

CMakeFiles/photoc.dir/grayscale.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/grayscale.cpp.o.requires

CMakeFiles/photoc.dir/grayscale.cpp.o.provides: CMakeFiles/photoc.dir/grayscale.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/grayscale.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/grayscale.cpp.o.provides

CMakeFiles/photoc.dir/grayscale.cpp.o.provides.build: CMakeFiles/photoc.dir/grayscale.cpp.o

CMakeFiles/photoc.dir/laplace.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/laplace.cpp.o: laplace.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/laplace.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/laplace.cpp.o -c /home/bhuvesh/pclub/photoc/laplace.cpp

CMakeFiles/photoc.dir/laplace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/laplace.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/laplace.cpp > CMakeFiles/photoc.dir/laplace.cpp.i

CMakeFiles/photoc.dir/laplace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/laplace.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/laplace.cpp -o CMakeFiles/photoc.dir/laplace.cpp.s

CMakeFiles/photoc.dir/laplace.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/laplace.cpp.o.requires

CMakeFiles/photoc.dir/laplace.cpp.o.provides: CMakeFiles/photoc.dir/laplace.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/laplace.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/laplace.cpp.o.provides

CMakeFiles/photoc.dir/laplace.cpp.o.provides.build: CMakeFiles/photoc.dir/laplace.cpp.o

CMakeFiles/photoc.dir/negative.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/negative.cpp.o: negative.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/negative.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/negative.cpp.o -c /home/bhuvesh/pclub/photoc/negative.cpp

CMakeFiles/photoc.dir/negative.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/negative.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/negative.cpp > CMakeFiles/photoc.dir/negative.cpp.i

CMakeFiles/photoc.dir/negative.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/negative.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/negative.cpp -o CMakeFiles/photoc.dir/negative.cpp.s

CMakeFiles/photoc.dir/negative.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/negative.cpp.o.requires

CMakeFiles/photoc.dir/negative.cpp.o.provides: CMakeFiles/photoc.dir/negative.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/negative.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/negative.cpp.o.provides

CMakeFiles/photoc.dir/negative.cpp.o.provides.build: CMakeFiles/photoc.dir/negative.cpp.o

CMakeFiles/photoc.dir/poster.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/poster.cpp.o: poster.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/poster.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/poster.cpp.o -c /home/bhuvesh/pclub/photoc/poster.cpp

CMakeFiles/photoc.dir/poster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/poster.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/poster.cpp > CMakeFiles/photoc.dir/poster.cpp.i

CMakeFiles/photoc.dir/poster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/poster.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/poster.cpp -o CMakeFiles/photoc.dir/poster.cpp.s

CMakeFiles/photoc.dir/poster.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/poster.cpp.o.requires

CMakeFiles/photoc.dir/poster.cpp.o.provides: CMakeFiles/photoc.dir/poster.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/poster.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/poster.cpp.o.provides

CMakeFiles/photoc.dir/poster.cpp.o.provides.build: CMakeFiles/photoc.dir/poster.cpp.o

CMakeFiles/photoc.dir/sepia.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/sepia.cpp.o: sepia.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/sepia.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/sepia.cpp.o -c /home/bhuvesh/pclub/photoc/sepia.cpp

CMakeFiles/photoc.dir/sepia.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/sepia.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/sepia.cpp > CMakeFiles/photoc.dir/sepia.cpp.i

CMakeFiles/photoc.dir/sepia.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/sepia.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/sepia.cpp -o CMakeFiles/photoc.dir/sepia.cpp.s

CMakeFiles/photoc.dir/sepia.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/sepia.cpp.o.requires

CMakeFiles/photoc.dir/sepia.cpp.o.provides: CMakeFiles/photoc.dir/sepia.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/sepia.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/sepia.cpp.o.provides

CMakeFiles/photoc.dir/sepia.cpp.o.provides.build: CMakeFiles/photoc.dir/sepia.cpp.o

CMakeFiles/photoc.dir/stache.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/stache.cpp.o: stache.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/stache.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/stache.cpp.o -c /home/bhuvesh/pclub/photoc/stache.cpp

CMakeFiles/photoc.dir/stache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/stache.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/stache.cpp > CMakeFiles/photoc.dir/stache.cpp.i

CMakeFiles/photoc.dir/stache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/stache.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/stache.cpp -o CMakeFiles/photoc.dir/stache.cpp.s

CMakeFiles/photoc.dir/stache.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/stache.cpp.o.requires

CMakeFiles/photoc.dir/stache.cpp.o.provides: CMakeFiles/photoc.dir/stache.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/stache.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/stache.cpp.o.provides

CMakeFiles/photoc.dir/stache.cpp.o.provides.build: CMakeFiles/photoc.dir/stache.cpp.o

CMakeFiles/photoc.dir/motion.cpp.o: CMakeFiles/photoc.dir/flags.make
CMakeFiles/photoc.dir/motion.cpp.o: motion.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bhuvesh/pclub/photoc/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/photoc.dir/motion.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/photoc.dir/motion.cpp.o -c /home/bhuvesh/pclub/photoc/motion.cpp

CMakeFiles/photoc.dir/motion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/photoc.dir/motion.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bhuvesh/pclub/photoc/motion.cpp > CMakeFiles/photoc.dir/motion.cpp.i

CMakeFiles/photoc.dir/motion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/photoc.dir/motion.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bhuvesh/pclub/photoc/motion.cpp -o CMakeFiles/photoc.dir/motion.cpp.s

CMakeFiles/photoc.dir/motion.cpp.o.requires:
.PHONY : CMakeFiles/photoc.dir/motion.cpp.o.requires

CMakeFiles/photoc.dir/motion.cpp.o.provides: CMakeFiles/photoc.dir/motion.cpp.o.requires
	$(MAKE) -f CMakeFiles/photoc.dir/build.make CMakeFiles/photoc.dir/motion.cpp.o.provides.build
.PHONY : CMakeFiles/photoc.dir/motion.cpp.o.provides

CMakeFiles/photoc.dir/motion.cpp.o.provides.build: CMakeFiles/photoc.dir/motion.cpp.o

# Object files for target photoc
photoc_OBJECTS = \
"CMakeFiles/photoc.dir/photoc.cpp.o" \
"CMakeFiles/photoc.dir/bifi.cpp.o" \
"CMakeFiles/photoc.dir/blur.cpp.o" \
"CMakeFiles/photoc.dir/canny.cpp.o" \
"CMakeFiles/photoc.dir/grayscale.cpp.o" \
"CMakeFiles/photoc.dir/laplace.cpp.o" \
"CMakeFiles/photoc.dir/negative.cpp.o" \
"CMakeFiles/photoc.dir/poster.cpp.o" \
"CMakeFiles/photoc.dir/sepia.cpp.o" \
"CMakeFiles/photoc.dir/stache.cpp.o" \
"CMakeFiles/photoc.dir/motion.cpp.o"

# External object files for target photoc
photoc_EXTERNAL_OBJECTS =

photoc: CMakeFiles/photoc.dir/photoc.cpp.o
photoc: CMakeFiles/photoc.dir/bifi.cpp.o
photoc: CMakeFiles/photoc.dir/blur.cpp.o
photoc: CMakeFiles/photoc.dir/canny.cpp.o
photoc: CMakeFiles/photoc.dir/grayscale.cpp.o
photoc: CMakeFiles/photoc.dir/laplace.cpp.o
photoc: CMakeFiles/photoc.dir/negative.cpp.o
photoc: CMakeFiles/photoc.dir/poster.cpp.o
photoc: CMakeFiles/photoc.dir/sepia.cpp.o
photoc: CMakeFiles/photoc.dir/stache.cpp.o
photoc: CMakeFiles/photoc.dir/motion.cpp.o
photoc: CMakeFiles/photoc.dir/build.make
photoc: /usr/local/lib/libopencv_videostab.so.2.4.9
photoc: /usr/local/lib/libopencv_video.so.2.4.9
photoc: /usr/local/lib/libopencv_ts.a
photoc: /usr/local/lib/libopencv_superres.so.2.4.9
photoc: /usr/local/lib/libopencv_stitching.so.2.4.9
photoc: /usr/local/lib/libopencv_photo.so.2.4.9
photoc: /usr/local/lib/libopencv_ocl.so.2.4.9
photoc: /usr/local/lib/libopencv_objdetect.so.2.4.9
photoc: /usr/local/lib/libopencv_nonfree.so.2.4.9
photoc: /usr/local/lib/libopencv_ml.so.2.4.9
photoc: /usr/local/lib/libopencv_legacy.so.2.4.9
photoc: /usr/local/lib/libopencv_imgproc.so.2.4.9
photoc: /usr/local/lib/libopencv_highgui.so.2.4.9
photoc: /usr/local/lib/libopencv_gpu.so.2.4.9
photoc: /usr/local/lib/libopencv_flann.so.2.4.9
photoc: /usr/local/lib/libopencv_features2d.so.2.4.9
photoc: /usr/local/lib/libopencv_core.so.2.4.9
photoc: /usr/local/lib/libopencv_contrib.so.2.4.9
photoc: /usr/local/lib/libopencv_calib3d.so.2.4.9
photoc: /usr/lib/x86_64-linux-gnu/libGLU.so
photoc: /usr/lib/x86_64-linux-gnu/libGL.so
photoc: /usr/lib/x86_64-linux-gnu/libSM.so
photoc: /usr/lib/x86_64-linux-gnu/libICE.so
photoc: /usr/lib/x86_64-linux-gnu/libX11.so
photoc: /usr/lib/x86_64-linux-gnu/libXext.so
photoc: /usr/local/lib/libopencv_nonfree.so.2.4.9
photoc: /usr/local/lib/libopencv_ocl.so.2.4.9
photoc: /usr/local/lib/libopencv_gpu.so.2.4.9
photoc: /usr/local/lib/libopencv_photo.so.2.4.9
photoc: /usr/local/lib/libopencv_objdetect.so.2.4.9
photoc: /usr/local/lib/libopencv_legacy.so.2.4.9
photoc: /usr/local/lib/libopencv_video.so.2.4.9
photoc: /usr/local/lib/libopencv_ml.so.2.4.9
photoc: /usr/local/lib/libopencv_calib3d.so.2.4.9
photoc: /usr/local/lib/libopencv_features2d.so.2.4.9
photoc: /usr/local/lib/libopencv_highgui.so.2.4.9
photoc: /usr/local/lib/libopencv_imgproc.so.2.4.9
photoc: /usr/local/lib/libopencv_flann.so.2.4.9
photoc: /usr/local/lib/libopencv_core.so.2.4.9
photoc: CMakeFiles/photoc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable photoc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/photoc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/photoc.dir/build: photoc
.PHONY : CMakeFiles/photoc.dir/build

CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/photoc.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/bifi.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/blur.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/canny.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/grayscale.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/laplace.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/negative.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/poster.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/sepia.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/stache.cpp.o.requires
CMakeFiles/photoc.dir/requires: CMakeFiles/photoc.dir/motion.cpp.o.requires
.PHONY : CMakeFiles/photoc.dir/requires

CMakeFiles/photoc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/photoc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/photoc.dir/clean

CMakeFiles/photoc.dir/depend:
	cd /home/bhuvesh/pclub/photoc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bhuvesh/pclub/photoc /home/bhuvesh/pclub/photoc /home/bhuvesh/pclub/photoc /home/bhuvesh/pclub/photoc /home/bhuvesh/pclub/photoc/CMakeFiles/photoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/photoc.dir/depend

