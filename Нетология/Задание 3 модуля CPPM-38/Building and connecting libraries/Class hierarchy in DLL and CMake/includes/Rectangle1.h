#ifndef RECTANGLE1_H
#define RECTANGLE1_H

#include "Quadrangle.h"

class Rectangle1 : public Quadrangle {
public:
    __EXPORT Rectangle1(int a, int b);
    __EXPORT void print_info() override;
};

#endif