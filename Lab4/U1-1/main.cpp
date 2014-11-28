#include <iostream>

#include "circle.h"
#include "cylinder.h"

using namespace std;

int main()
{
    Circle circle(3);
    Cylinder cylinder(3.0, 4.0);
    cout << "Circle:" << endl << "r=" << circle.getRadius() << endl << "a=" << circle.getArea() << endl << endl;
    cout << "Cylinder:" << endl << "r=" << cylinder.getRadius() << endl << "a=" << cylinder.getArea() << endl << "h=" << cylinder.getHeight() << endl << "v=" << cylinder.getVolume() << endl;
    return 0;
}

