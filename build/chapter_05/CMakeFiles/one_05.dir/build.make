# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/c1over/Documents/OpencvWorkspace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/c1over/Documents/OpencvWorkspace/build

# Include any dependencies generated for this target.
include chapter_05/CMakeFiles/one_05.dir/depend.make

# Include the progress variables for this target.
include chapter_05/CMakeFiles/one_05.dir/progress.make

# Include the compile flags for this target's objects.
include chapter_05/CMakeFiles/one_05.dir/flags.make

chapter_05/CMakeFiles/one_05.dir/one.cpp.o: chapter_05/CMakeFiles/one_05.dir/flags.make
chapter_05/CMakeFiles/one_05.dir/one.cpp.o: ../chapter_05/one.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/c1over/Documents/OpencvWorkspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object chapter_05/CMakeFiles/one_05.dir/one.cpp.o"
	cd /Users/c1over/Documents/OpencvWorkspace/build/chapter_05 && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/one_05.dir/one.cpp.o -c /Users/c1over/Documents/OpencvWorkspace/chapter_05/one.cpp

chapter_05/CMakeFiles/one_05.dir/one.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/one_05.dir/one.cpp.i"
	cd /Users/c1over/Documents/OpencvWorkspace/build/chapter_05 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/c1over/Documents/OpencvWorkspace/chapter_05/one.cpp > CMakeFiles/one_05.dir/one.cpp.i

chapter_05/CMakeFiles/one_05.dir/one.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/one_05.dir/one.cpp.s"
	cd /Users/c1over/Documents/OpencvWorkspace/build/chapter_05 && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/c1over/Documents/OpencvWorkspace/chapter_05/one.cpp -o CMakeFiles/one_05.dir/one.cpp.s

# Object files for target one_05
one_05_OBJECTS = \
"CMakeFiles/one_05.dir/one.cpp.o"

# External object files for target one_05
one_05_EXTERNAL_OBJECTS =

chapter_05/one_05: chapter_05/CMakeFiles/one_05.dir/one.cpp.o
chapter_05/one_05: chapter_05/CMakeFiles/one_05.dir/build.make
chapter_05/one_05: /usr/local/lib/libopencv_gapi.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_stitching.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_aruco.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_bgsegm.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_bioinspired.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_ccalib.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_dnn_objdetect.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_dpm.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_face.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_freetype.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_fuzzy.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_hfs.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_img_hash.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_line_descriptor.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_quality.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_reg.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_rgbd.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_saliency.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_sfm.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_stereo.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_structured_light.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_superres.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_surface_matching.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_tracking.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_videostab.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_xfeatures2d.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_xobjdetect.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_xphoto.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_shape.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_datasets.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_plot.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_text.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_dnn.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_ml.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_phase_unwrapping.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_optflow.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_ximgproc.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_video.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_objdetect.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_calib3d.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_features2d.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_flann.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_highgui.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_videoio.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_imgcodecs.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_photo.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_imgproc.4.1.0.dylib
chapter_05/one_05: /usr/local/lib/libopencv_core.4.1.0.dylib
chapter_05/one_05: chapter_05/CMakeFiles/one_05.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/c1over/Documents/OpencvWorkspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable one_05"
	cd /Users/c1over/Documents/OpencvWorkspace/build/chapter_05 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/one_05.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chapter_05/CMakeFiles/one_05.dir/build: chapter_05/one_05

.PHONY : chapter_05/CMakeFiles/one_05.dir/build

chapter_05/CMakeFiles/one_05.dir/clean:
	cd /Users/c1over/Documents/OpencvWorkspace/build/chapter_05 && $(CMAKE_COMMAND) -P CMakeFiles/one_05.dir/cmake_clean.cmake
.PHONY : chapter_05/CMakeFiles/one_05.dir/clean

chapter_05/CMakeFiles/one_05.dir/depend:
	cd /Users/c1over/Documents/OpencvWorkspace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/c1over/Documents/OpencvWorkspace /Users/c1over/Documents/OpencvWorkspace/chapter_05 /Users/c1over/Documents/OpencvWorkspace/build /Users/c1over/Documents/OpencvWorkspace/build/chapter_05 /Users/c1over/Documents/OpencvWorkspace/build/chapter_05/CMakeFiles/one_05.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chapter_05/CMakeFiles/one_05.dir/depend

