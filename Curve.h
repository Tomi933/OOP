#pragma once

class Curve {
public:
    virtual bool belongs(double x, double y) const = 0;
    virtual ~Curve() {}
};
