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
CMAKE_SOURCE_DIR = /home/minh/BB8/Test/VisionTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/minh/BB8/Test/VisionTest

# Include any dependencies generated for this target.
include CMakeFiles/motionTrack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motionTrack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motionTrack.dir/flags.make

CMakeFiles/motionTrack.dir/motionTrack.cpp.o: CMakeFiles/motionTrack.dir/flags.make
CMakeFiles/motionTrack.dir/motionTrack.cpp.o: motionTrack.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/minh/BB8/Test/VisionTest/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/motionTrack.dir/motionTrack.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/motionTrack.dir/motionTrack.cpp.o -c /home/minh/BB8/Test/VisionTest/motionTrack.cpp

CMakeFiles/motionTrack.dir/motionTrack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motionTrack.dir/motionTrack.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/minh/BB8/Test/VisionTest/motionTrack.cpp > CMakeFiles/motionTrack.dir/motionTrack.cpp.i

CMakeFiles/motionTrack.dir/motionTrack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motionTrack.dir/motionTrack.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/minh/BB8/Test/VisionTest/motionTrack.cpp -o CMakeFiles/motionTrack.dir/motionTrack.cpp.s

CMakeFiles/motionTrack.dir/motionTrack.cpp.o.requires:
.PHONY : CMakeFiles/motionTrack.dir/motionTrack.cpp.o.requires

CMakeFiles/motionTrack.dir/motionTrack.cpp.o.provides: CMakeFiles/motionTrack.dir/motionTrack.cpp.o.requires
	$(MAKE) -f CMakeFiles/motionTrack.dir/build.make CMakeFiles/motionTrack.dir/motionTrack.cpp.o.provides.build
.PHONY : CMakeFiles/motionTrack.dir/motionTrack.cpp.o.provides

CMakeFiles/motionTrack.dir/motionTrack.cpp.o.provides.build: CMakeFiles/motionTrack.dir/motionTrack.cpp.o

# Object files for target motionTrack
motionTrack_OBJECTS = \
"CMakeFiles/motionTrack.dir/motionTrack.cpp.o"

# External object files for target motionTrack
motionTrack_EXTERNAL_OBJECTS =

motionTrack: CMakeFiles/motionTrack.dir/motionTrack.cpp.o
motionTrack: CMakeFiles/motionTrack.dir/build.make
motionTrack: /usr/local/lib/libopencv_videostab.so.3.0.0
motionTrack: /usr/local/lib/libopencv_videoio.so.3.0.0
motionTrack: /usr/local/lib/libopencv_video.so.3.0.0
motionTrack: /usr/local/lib/libopencv_superres.so.3.0.0
motionTrack: /usr/local/lib/libopencv_stitching.so.3.0.0
motionTrack: /usr/local/lib/libopencv_shape.so.3.0.0
motionTrack: /usr/local/lib/libopencv_photo.so.3.0.0
motionTrack: /usr/local/lib/libopencv_objdetect.so.3.0.0
motionTrack: /usr/local/lib/libopencv_ml.so.3.0.0
motionTrack: /usr/local/lib/libopencv_imgproc.so.3.0.0
motionTrack: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
motionTrack: /usr/local/lib/libopencv_highgui.so.3.0.0
motionTrack: /usr/local/lib/libopencv_hal.a
motionTrack: /usr/local/lib/libopencv_flann.so.3.0.0
motionTrack: /usr/local/lib/libopencv_features2d.so.3.0.0
motionTrack: /usr/local/lib/libopencv_core.so.3.0.0
motionTrack: /usr/local/lib/libopencv_calib3d.so.3.0.0
motionTrack: /usr/local/lib/libopencv_features2d.so.3.0.0
motionTrack: /usr/local/lib/libopencv_ml.so.3.0.0
motionTrack: /usr/local/lib/libopencv_highgui.so.3.0.0
motionTrack: /usr/local/lib/libopencv_videoio.so.3.0.0
motionTrack: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
motionTrack: /usr/local/lib/libopencv_flann.so.3.0.0
motionTrack: /usr/local/lib/libopencv_video.so.3.0.0
motionTrack: /usr/local/lib/libopencv_imgproc.so.3.0.0
motionTrack: /usr/local/lib/libopencv_core.so.3.0.0
motionTrack: /usr/local/lib/libopencv_hal.a
motionTrack: /usr/lib/x86_64-linux-gnu/libGLU.so
motionTrack: /usr/lib/x86_64-linux-gnu/libGL.so
motionTrack: /usr/lib/x86_64-linux-gnu/libSM.so
motionTrack: /usr/lib/x86_64-linux-gnu/libICE.so
motionTrack: /usr/lib/x86_64-linux-gnu/libX11.so
motionTrack: /usr/lib/x86_64-linux-gnu/libXext.so
motionTrack: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
motionTrack: CMakeFiles/motionTrack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable motionTrack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motionTrack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motionTrack.dir/build: motionTrack
.PHONY : CMakeFiles/motionTrack.dir/build

CMakeFiles/motionTrack.dir/requires: CMakeFiles/motionTrack.dir/motionTrack.cpp.o.requires
.PHONY : CMakeFiles/motionTrack.dir/requires

CMakeFiles/motionTrack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motionTrack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motionTrack.dir/clean

CMakeFiles/motionTrack.dir/depend:
	cd /home/minh/BB8/Test/VisionTest && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minh/BB8/Test/VisionTest /home/minh/BB8/Test/VisionTest /home/minh/BB8/Test/VisionTest /home/minh/BB8/Test/VisionTest /home/minh/BB8/Test/VisionTest/CMakeFiles/motionTrack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/motionTrack.dir/depend

