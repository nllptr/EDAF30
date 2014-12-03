#include <iostream>
#include "rektangel.h"

using namespace std;

int main()
{
    double x = 0, y = 0;
    cout << "Enter rectangle width and height." << endl;
    cin >> x >> y;
    Rektangel rect;
    rect.sattVarden(x, y);
    cout << "Rectangle area: " << rect.area() << endl;
    cout << "Rectangle circumference: " << rect.omkrets() << endl;
    cout << "Rectangle attributes: ";
    rect.visa();
    cout << endl;

    cout << "Enter magnification factor: ";
    double fact = 0;
    cin >> fact;
    rect.forstora(fact);

    cout << "Rectangle area: " << rect.area() << endl;
    cout << "Rectangle circumference: " << rect.omkrets() << endl;
    cout << "Rectangle attributes: ";
    rect.visa();
    cout << endl;

    return 0;
}
