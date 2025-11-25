#pragma once
#include "Curve.h"

class Line : public Curve {
    double a, b;  
public:
    Line(double a, double b);
    bool belongs(double x, double y) const override;
};
