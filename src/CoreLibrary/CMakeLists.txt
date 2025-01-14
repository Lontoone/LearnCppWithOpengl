# Define the library project
project(MyLibrary)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
# Specify the source files
#set(SOURCES MyLibrary.cpp)
set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp" "*.h" )
#list(APPEND SOURCES "glad.c" )

# Add the library
add_library(MyLibrary SHARED ${SOURCES})
#============================
#       Define in Preprocessor
#============================
target_compile_definitions(MyLibrary PRIVATE TE_PLATFORM_WINDOES)
target_compile_definitions(MyLibrary PRIVATE TE_BUILD_DLL)
#
# Specify the include directories
target_include_directories(MyLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

# Specify the output directory for the DLL and import library
set_target_properties(MyLibrary PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

#==========================
#   Output glad as glad.dll into same folder
#==========================
set(GLAD_Include glad/include )
include_directories(${GLAD_Include})
add_library(glad SHARED glad/src/glad.c)
set_target_properties(glad PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
target_compile_definitions(glad PRIVATE GLFW_INCLUDE_NONE)

# Link spdlog to your target
target_link_libraries(MyLibrary spdlog::spdlog glfw OpenGL::GL glad)

#===============================
#        Pre-compile header
#===============================
set(PCH_FILE pch.h)
target_precompile_headers(${PROJECT_NAME} PRIVATE ${PCH_FILE})

#==========================
#		Imgui
#==========================
target_sources(${PROJECT_NAME} PRIVATE
    "${imgui_SOURCE_DIR}/imgui.cpp"
    "${imgui_SOURCE_DIR}/imgui_draw.cpp"
    "${imgui_SOURCE_DIR}/imgui_tables.cpp"
    "${imgui_SOURCE_DIR}/imgui_widgets.cpp"
    #"${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
    #"${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
	)
target_include_directories(${PROJECT_NAME} PRIVATE ${imgui_SOURCE_DIR}/backends)
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC "${imgui_SOURCE_DIR}")
