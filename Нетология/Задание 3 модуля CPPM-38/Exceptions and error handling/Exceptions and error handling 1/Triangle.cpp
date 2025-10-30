#include "Triangle.h"
#include <iostream>

Triangle::Triangle(std::string name, int a, int b, int c, int A, int B, int C): Figure(a, b, c, A, B, C) 
{                                                  //треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);     
  
    if (name == "Triangle" && A + B + C != 180) { throw MyClassExcp("сумма углов не равна 180"); }
}


void Triangle::print_info() 
{
    std::cout << "треугольник (стороны " << a << ", " << b << ", " << c << "; " << "углы " << A << ", " << B << ", " << C << ")" << std::endl;
}