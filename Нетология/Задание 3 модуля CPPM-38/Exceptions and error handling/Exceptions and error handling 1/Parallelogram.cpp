#include "Parallelogram.h"
#include <iostream>

Parallelogram::Parallelogram(std::string name, int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrangle(name, a, b, c, d, A, B, C, D)   //Параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
{
    if (a != c && b != d && A != C && B != D) { throw MyClassExcp("стороны a,c и b,d не равны, углы A,C и B,D не равны"); }
}

void Parallelogram::print_info() 
{
    std::cout << "Параллелограмм (стороны " << a << ", " << b << ", " << c << ", " << d << ";" << "углы " << A << ", " << B << ", " << C << "," << D << ")" << std::endl;
}