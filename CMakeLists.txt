
cmake_minimum_required(VERSION 3.4.3)

project(WinEditLine LANGUAGES C VERSION 2.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_POSITION_INDEPENDENT_CODE YES)

configure_file("${PROJECT_SOURCE_DIR}/src/config.h.in"
               "${PROJECT_BINARY_DIR}/config.h")

option(MSVC_USE_STATIC_RUNTIME "link against the static runtime (/MT)" OFF)
if (MSVC AND MSVC_USE_STATIC_RUNTIME)
  message(STATUS "Using static MSVC CRT")
  add_compile_options("$<$<CONFIG:Debug>:/MTd>"
                      "$<$<CONFIG:Release>:/MT>"
                      "$<$<CONFIG:RelWithDebInfo>:/MT>"
                      "$<$<CONFIG:MinSizeRel>:/MT>")
endif()

add_subdirectory(src)
