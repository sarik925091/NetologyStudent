#ifndef RECTANGLE1_H
#define RECTANGLE1_H

#include "Quadrangle.h"

class Rectangle1 : public Quadrangle {
public:
    Rectangle1(int a, int b);
    void print_info() override;
};

#endif