#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Quadrangle.h"

class Rhombus : public Quadrangle {
public:
    Rhombus(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
    void print_info() override;
};

#endif