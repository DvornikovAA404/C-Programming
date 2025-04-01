cmake_minimum_required(VERSION 3.10)

project(MyLibraryProject)

set(CMAKE_C_STANDARD 99)

option(BUILD_SHARED_LIBS "Build shared library instead of static" OFF)

if(BUILD_SHARED_LIBS)
    message(STATUS "Building SHARED library")
else()
    message(STATUS "Building STATIC library")
endif()

add_library(mylib lib.c)

add_executable(myprogram task.c)

target_link_libraries(myprogram mylib)
