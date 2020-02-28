cmake_minimum_required(VERSION 3.1)
project(cimgui-unity)

set (_cimgui_path ${CMAKE_CURRENT_SOURCE_DIR}/../cimgui/)

#general settings
file(GLOB IMGUI_SOURCES
    imconfig_unity.h
    plugin_custom_assert.cpp
    ${_cimgui_path}cimgui.cpp
    ${_cimgui_path}imgui/imgui.cpp
    ${_cimgui_path}imgui/imgui_draw.cpp
    ${_cimgui_path}imgui/imgui_demo.cpp
    ${_cimgui_path}imgui/imgui_widgets.cpp
)

set(IMGUI_STATIC "no" CACHE STRING "Build as a static library")

#add library and link
if (IMGUI_STATIC)
    add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES})
else (IMGUI_STATIC)
    add_library(${PROJECT_NAME} SHARED ${IMGUI_SOURCES})
endif (IMGUI_STATIC)

# export cpp imgui functions for other libraries eg cimgui-freetype
target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_DISABLE_OBSOLETE_FUNCTIONS=1)
if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_API=__declspec\(dllexport\))
    target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_IMPL_API="extern \"C\" __declspec\(dllexport\) ")
else (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_API=)
    target_compile_definitions(${PROJECT_NAME} PRIVATE IMGUI_IMPL_API="extern \"C\" ")
endif (WIN32)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${_cimgui_path})
target_include_directories(${PROJECT_NAME} PUBLIC ${_cimgui_path}imgui)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "cimgui")

# disable non UDT warnings
if (WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE /wd4190)
else (WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wno-return-type-c-linkage)
endif (WIN32)

#install
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION  .
    LIBRARY DESTINATION  .
    ARCHIVE DESTINATION  .
)
