# Define the library project
project(MyLibrary)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
# Specify the source files
#set(SOURCES MyLibrary.cpp)
file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp" "*.h" )
# Add the library
add_library(MyLibrary SHARED ${SOURCES})
#Define in Preprocessor
target_compile_definitions(MyLibrary PRIVATE TE_PLATFORM_WINDOES)
target_compile_definitions(MyLibrary PRIVATE TE_BUILD_DLL)

# Specify the include directories
target_include_directories(MyLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Specify the output directory for the DLL and import library
set_target_properties(MyLibrary PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
