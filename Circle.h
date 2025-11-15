#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle() : radius(0) {}
    Circle(double r) : radius(r) {}
    ~Circle() override {}

    double perimeter() const override;
};
