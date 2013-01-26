cmake_minimum_required(VERSION 2.8)
project(tests)

include_directories(${dcpu-vm_SOURCE_DIR})
add_executable(core core.cpp)
target_link_libraries(core dcpu-vm)
