cmake_minimum_required(VERSION 2.8)
project(dcpu-vm)

add_library(dcpu-vm ${LIBRARY_FORMAT}
    dcpu.cpp
    dcpu.hpp
)
