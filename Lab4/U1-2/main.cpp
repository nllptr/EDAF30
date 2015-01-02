#include <iostream>
#include "circle.h"
#include "cylinder.h"
using namespace std;

int main()
{
    Circle cir(3);
    cout << "Area of circle: " << cir.getArea() << endl;
    cout << "Radius of circle: " << cir.getRadius() << endl;
    Cylinder cyl(cir.getRadius(), 5);
    cout << "Volume of cylinder: " << cyl.getVolume() << endl;
    cout << "Height of cylinder: " << cyl.getHeight() << endl;
    cout << "Radius of cylinder: " << cyl.getRadius() << endl;
    return 0;
}
