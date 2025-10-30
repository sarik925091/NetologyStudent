#include "Square.h"
#include <iostream>

Square::Square(std::string name, int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrangle(name, a, b, c, d, A, B, C, D)     //Квадрат (угол C всегда равен 90);
{
    if (C != 90) { throw MyClassExcp("угол C не равен 90"); }
}

void Square::print_info() 
{
    std::cout << "Квадрат (стороны " << a << ", " << b << ", " << c << ", " << d << ";" << "углы " << A << ", " << B << ", " << C << "," << D << ")" << std::endl;
}