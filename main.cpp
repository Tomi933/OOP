#include <iostream>
#include <typeinfo>
#include "Square.h"
#include "Circle.h"
#include "IsoscelesTriangle.h"
#include "Trapezoid.h"

using namespace std;

int main() {

    Shape* shapes[4];
    shapes[0] = new Square(5);
    shapes[1] = new Circle(3);
    shapes[2] = new IsoscelesTriangle(4, 5);
    shapes[3] = new Trapezoid(3, 4, 5, 6);

    for (int i = 0; i < 4; ++i) {
        cout << "Shape " << i + 1 << " is of type "
            << typeid(*shapes[i]).name() 
            << " with perimeter = " << shapes[i]->perimeter() << endl;
    }


    for (int i = 0; i < 4; ++i) {
        delete shapes[i];
    }

    return 0;
}
