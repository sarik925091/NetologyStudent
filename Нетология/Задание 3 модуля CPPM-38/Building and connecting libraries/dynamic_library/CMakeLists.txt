cmake_minimum_required(VERSION 3.22.0)
project(dynamic_lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../bin)
add_library(dynamic_lib SHARED)
target_sources(dynamic_lib PRIVATE dynamic_lib.cpp dynamic_lib.h)

