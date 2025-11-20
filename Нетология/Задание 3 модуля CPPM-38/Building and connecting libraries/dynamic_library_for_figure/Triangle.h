#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
public:
    __EXPORT Triangle(int a, int b, int c, int A, int B, int C);
    __EXPORT virtual void print_info() override;
};

#endif