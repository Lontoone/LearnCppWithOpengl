# Define the executable project
project(MyExecutable)

# Specify the source files
set(SOURCES main.cpp)

# Add the executable
add_executable(MyExecutable ${SOURCES})
target_compile_definitions(MyExecutable PRIVATE TE_PLATFORM_WINDOES)

# Link the executable with the library
target_link_libraries(MyExecutable MyLibrary)

# Specify the include directories
target_include_directories(MyExecutable PUBLIC ${CMAKE_SOURCE_DIR}/src/CoreLibrary)
# Specify the output directory for the DLL and import library
set_target_properties(MyExecutable PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin 
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)