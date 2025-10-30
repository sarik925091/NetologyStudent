#ifndef RECTANGLE1_H
#define RECTANGLE1_H

#include "Quadrangle.h"

class Rectangle1 : public Quadrangle 
{
public:
    Rectangle1(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
    void print_info() override;
};

#endif