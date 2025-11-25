#pragma once
#include "Curve.h"

class Ellipse : public Curve {
    double a, b;  
public:
    Ellipse(double a, double b);
    bool belongs(double x, double y) const override;
};
