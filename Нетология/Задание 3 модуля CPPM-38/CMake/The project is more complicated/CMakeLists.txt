cmake_minimum_required(VERSION 4.0)
project(class_hierarchy)
message (STATUS "PROJECT NAME: " ${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
include_directories(includes)
add_executable(${PROJECT_NAME}
    src/class_hierarchy.cpp
    src/EquilateralTriangle.cpp
    src/Figure.cpp
    src/IsoscelesTriangle.cpp
    src/Parallelogram.cpp
    src/Quadrangle.cpp
    src/Rectangle1.cpp
    src/Rhombus.cpp
    src/RightTriangle.cpp
    src/Square.cpp
    src/Triangle.cpp
)
