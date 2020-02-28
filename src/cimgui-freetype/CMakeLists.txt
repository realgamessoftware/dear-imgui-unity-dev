cmake_minimum_required(VERSION 3.8)
project(cimgui-freetype)

# add imgui_freetype files to project
set(_imgui_freetype_path ${CMAKE_CURRENT_SOURCE_DIR}/../cimgui/imgui/misc/freetype/)
set(_imgui_freetype_sources
    ${_imgui_freetype_path}imgui_freetype.h
    ${_imgui_freetype_path}imgui_freetype.cpp
)
source_group(imgui-freetype FILES ${_imgui_freetype_sources})

# define wrapper lib and respective files
add_library(${PROJECT_NAME} SHARED
    cimgui_freetype.cpp
    ${_imgui_freetype_sources}
)

# link cimgui
target_link_libraries(${PROJECT_NAME} PRIVATE cimgui-unity)
target_include_directories(${PROJECT_NAME} PRIVATE ${_imgui_freetype_path})

# freetype module
# https://cmake.org/cmake/help/latest/module/FindFreetype.html
add_subdirectory(freetype2)
target_link_libraries(${PROJECT_NAME} PRIVATE freetype)
if (UNIX)
    target_compile_options(freetype PRIVATE -fPIC)
endif (UNIX)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

# in this library we want functions marked with IMGUI_API as dllimport
# as those come from imgui.h included headers and do not need to be exported to others
if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_API=__declspec\(dllimport\))
else (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_API=)
endif (WIN32)

# disable non UDT warnings
if (WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE /wd4190)
else (WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wno-return-type-c-linkage)
endif (WIN32)
