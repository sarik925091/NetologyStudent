cmake_minimum_required(VERSION 3.22.0)
project(dynamic_lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../../lib)
add_library(dynamic_lib SHARED)
set_target_properties(dynamic_lib PROPERTIES OUTPUT_NAME dll_figure)
target_sources(dynamic_lib PRIVATE 
EquilateralTriangle.cpp  
EquilateralTriangle.h
Figure.cpp  
Figure.h
IsoscelesTriangle.cpp  
IsoscelesTriangle.h
Parallelogram.cpp  
Parallelogram.h
Quadrangle.cpp  
Quadrangle.h
Rectangle1.cpp 
Rectangle1.h
Rhombus.cpp 
Rhombus.h
RightTriangle.cpp  
RightTriangle.h  
Square.cpp
Square.h 
Triangle.cpp
Triangle.h
)
