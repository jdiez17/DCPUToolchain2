cmake_minimum_required(VERSION 2.8)
project(toolchain2)

option(DCPU_LIBS "Build the Toolchain libraries" ON)
option(SHARED_LIBS "Build shared libraries" OFF)

if(${DCPU_LIBS})
    add_subdirectory(libs)
endif()

if(${SHARED_LIBS})
    set(LIBRARY_FORMAT SHARED)
else()
    set(LIBRARY_FORMAT STATIC)
endif()
