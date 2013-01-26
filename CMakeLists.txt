cmake_minimum_required(VERSION 2.8)
project(toolchain2)

option(DCPU_LIBS "Build the Toolchain libraries" ON)
option(SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

if(${DCPU_LIBS})
    add_subdirectory(src/libs)
endif()

add_subdirectory(src/tests)

if(${SHARED_LIBS})
    set(LIBRARY_FORMAT SHARED)
else()
    set(LIBRARY_FORMAT STATIC)
endif()

