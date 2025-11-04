#include <iostream>
#include <Windows.h>
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Rectangle1.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

void print_info(Figure* figure) {
    figure->print_info();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle(10, 20, 30, 50, 60, 70);
    print_info(&triangle);

    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    print_info(&rightTriangle);

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    print_info(&isoscelesTriangle);

    EquilateralTriangle equilateralTriangle(30);
    print_info(&equilateralTriangle);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(&quadrangle);

    Rectangle1 rectangle1(10, 20);
    print_info(&rectangle1);

    Square square(20);
    print_info(&square);

    Parallelogram parallelogram(20, 30, 30, 40);
    print_info(&parallelogram);

    Rhombus rhombus(30, 30, 40);
    print_info(&rhombus);

    return 0;
}