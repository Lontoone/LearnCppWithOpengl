cmake_minimum_required(VERSION 3.10)
project(MyProject)


# Include the FetchContent module
include(FetchContent)
#==========================
#		Opengl
#==========================
find_package(OpenGL REQUIRED)

#==========================
#		GLFW
#==========================
# Define GLFW dependency
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG latest
)
# Make GLFW available
FetchContent_MakeAvailable(glfw)

#==========================
#		Imgui
#==========================


# Add the spdlog submodule directory
add_subdirectory(external/spdlog)

# Add subdirectories
add_subdirectory(src/CoreLibrary)
add_subdirectory(src/Executable)
add_dependencies(MyExecutable MyLibrary)
