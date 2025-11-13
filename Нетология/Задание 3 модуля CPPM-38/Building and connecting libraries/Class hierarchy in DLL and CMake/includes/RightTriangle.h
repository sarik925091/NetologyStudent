#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H


#include "Triangle.h"

class RightTriangle : public Triangle {
public:
    __EXPORT RightTriangle(int a, int b, int c, int A, int B);
    __EXPORT void print_info() override;
};

#endif