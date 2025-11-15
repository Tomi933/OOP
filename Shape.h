#pragma once

class Shape {
public:
    Shape() {}
    virtual ~Shape() {}
    virtual double perimeter() const = 0;
};
