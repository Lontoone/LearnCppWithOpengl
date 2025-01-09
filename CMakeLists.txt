cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Add subdirectories
add_subdirectory(src/CoreLibrary)
add_subdirectory(src/Executable)
add_dependencies(MyExecutable MyLibrary)