#pragma once
#include "Shape.h"

class IsoscelesTriangle : public Shape {
private:
    double base;
    double side;
public:
    IsoscelesTriangle() : base(0), side(0) {}
    IsoscelesTriangle(double b, double s) : base(b), side(s) {}
    ~IsoscelesTriangle() override {}

    double perimeter() const override;
};
