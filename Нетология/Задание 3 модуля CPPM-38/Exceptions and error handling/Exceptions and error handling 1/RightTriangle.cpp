#include "RightTriangle.h"
#include <iostream>

RightTriangle::RightTriangle(std::string name, int a, int b, int c,int A, int B, int C) : Triangle(name, a, b, c, A, B, C)
{   //Прямоугольный треугольник: (угол C всегда равен 90);
    if (name == "RightTriangle" && C != 90) { throw MyClassExcp("угол C не равен 90"); }
}

void RightTriangle::print_info() 
{     
    std::cout << "Прямоугольный треугольник (стороны " <<a<<", " << b<<", " << c<<"; " << "углы " << A << ", " << B << ", " << C << ")" << std::endl;
}