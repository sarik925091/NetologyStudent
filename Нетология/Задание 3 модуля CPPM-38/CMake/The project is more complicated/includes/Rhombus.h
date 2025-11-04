#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Quadrangle.h"

class Rhombus : public Quadrangle {
public:
    Rhombus(int a, int A, int B);
    void print_info() override;
};

#endif