#pragma once
#include "Shape.h"

class Trapezoid : public Shape {
private:
    double a, b, c, d;
public:
    Trapezoid() : a(0), b(0), c(0), d(0) {}
    Trapezoid(double a_, double b_, double c_, double d_) : a(a_), b(b_), c(c_), d(d_) {}
    ~Trapezoid() override {}

    double perimeter() const override;
};
