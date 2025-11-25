#include "Hyperbola.h"
#include <cmath>

Hyperbola::Hyperbola(double a, double b) : a(a), b(b) {}

bool Hyperbola::belongs(double x, double y) const {
    double val = (x * x) / (a * a) - (y * y) / (b * b);
    return (val == 1);
}
