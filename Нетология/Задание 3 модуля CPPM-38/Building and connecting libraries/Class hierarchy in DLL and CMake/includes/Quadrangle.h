#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include "Figure.h"

class Quadrangle : public Figure {
public:
    __EXPORT Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
    __EXPORT void print_info() override;
};

#endif