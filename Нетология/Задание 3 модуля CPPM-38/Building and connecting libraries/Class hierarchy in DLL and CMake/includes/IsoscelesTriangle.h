#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
public:
    __EXPORT IsoscelesTriangle(int a, int b, int A, int B);
    __EXPORT void print_info() override;
};

#endif