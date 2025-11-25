#include "Line.h"
#include <cmath>

Line::Line(double a, double b) : a(a), b(b) {}

bool Line::belongs(double x, double y) const {
    if (y == (a * x + b)) {
        return true;
    }
    return false;
}
