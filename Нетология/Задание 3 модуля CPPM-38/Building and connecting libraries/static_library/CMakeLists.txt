cmake_minimum_required(VERSION 3.22.0)
project(static_lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../bin)
add_library(static_lib STATIC)
target_sources(static_lib PRIVATE static_lib.cpp static_lib.h)

