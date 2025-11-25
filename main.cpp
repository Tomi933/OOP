#include <iostream>
#include <typeinfo>

#include "Line.h"
#include "Ellipse.h"
#include "Hyperbola.h"

using namespace std;

int main() {
    Curve* curves[3];

    curves[0] = new Line(2, -4);
    curves[1] = new Ellipse(3, 2);
    curves[2] = new Hyperbola(2, 3);

    double x = 2, y = 0;

    for (int i = 0; i < 3; i++) {
        cout << "\nObject #" << i + 1 << endl;

        cout << "Type (real type): " << typeid(*curves[i]).name() << endl;

        if (curves[i]->belongs(x, y))
            cout << "Point (" << x << ", " << y << ") BELONGS to the curve.\n";
        else
            cout << "Point (" << x << ", " << y << ") does NOT belong to the curve.\n";
    }


    for (int i = 0; i < 3; i++)
        delete curves[i];

    return 0;
}
