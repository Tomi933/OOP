#pragma once
#include "Shape.h"

class Square : public Shape {
private:
    double side;
public:
    Square() : side(0) {}
    Square(double s) : side(s) {}
    ~Square() override {}

    double perimeter() const override;
};
