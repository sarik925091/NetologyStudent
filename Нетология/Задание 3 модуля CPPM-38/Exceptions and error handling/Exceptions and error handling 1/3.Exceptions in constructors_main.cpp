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

#define CREATE_AND_PRINT(name, ShapeType, ...) \
    try { \
        std::string figureName{name}; \
        ShapeType obj(figureName, __VA_ARGS__); \
        print_info(&obj); \
    } \
    catch (MyClassExcp& e) { \
        std::cout << "Ошибка создания фигуры. Причина:  " << e.what() << std::endl; \
    }

void print_info(Figure* figure) 
{
    figure->print_info();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CREATE_AND_PRINT("Triangle",Triangle, 10, 20, 30, 50, 60, 70)
    CREATE_AND_PRINT("RightTriangle", RightTriangle, 10, 20, 30, 50, 60, 100)
    CREATE_AND_PRINT("IsoscelesTriangle", IsoscelesTriangle, 10, 20, 30, 50, 60, 70)
    CREATE_AND_PRINT("EquilateralTriangle", EquilateralTriangle, 10, 20, 30, 50, 60, 70)
    CREATE_AND_PRINT("Quadrangle", Quadrangle, 10, 20, 30, 40, 90, 90, 90, 90)
    CREATE_AND_PRINT("Rectangle1", Rectangle1, 10, 20, 30, 40, 50, 60, 70, 80)
    CREATE_AND_PRINT("Square", Square, 10, 20, 30, 40, 50, 60, 90, 80)
    CREATE_AND_PRINT("Parallelogram", Parallelogram, 10, 20, 30, 40, 50, 60, 70, 80)
    CREATE_AND_PRINT("Rhombus", Rhombus, 10, 20, 30, 40, 50, 60, 70, 80)
    
    return 0;
}