#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(double a, double b) : a(a), b(b) {}

bool Ellipse::belongs(double x, double y) const {
    double val = (x * x) / (a * a) + (y * y) / (b * b);
    return (val == 1);
}
