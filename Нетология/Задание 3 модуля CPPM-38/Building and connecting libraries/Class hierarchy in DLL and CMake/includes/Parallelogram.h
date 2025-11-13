#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrangle.h"

class Parallelogram : public Quadrangle {
public:
    __EXPORT Parallelogram(int a, int b, int A, int B);
    __EXPORT void print_info() override;
};

#endif