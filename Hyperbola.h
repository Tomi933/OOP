#pragma once
#include "Curve.h"

class Hyperbola : public Curve {
    double a, b;  
public:
    Hyperbola(double a, double b);
    bool belongs(double x, double y) const override;
};
