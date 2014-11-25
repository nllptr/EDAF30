#include <iostream>
#include "rektangel.h"

using namespace std;

int main()
{
    double x, y, n;
    cout << "Enter x: "; cin >> x;
    cout << "enter y: "; cin >> y;
    Rektangel rect;
    rect.sattVarden(x, y);
    rect.visa();
    cout << "Area: " << rect.area() << endl;
    cout << "Omkrets: " << rect.omkrets() << endl;
    cout << "Enter n: "; cin >> n;
    rect.forstora(n);
    rect.visa();
    cout << "Area: " << rect.area() << endl;
    cout << "Omkrets: " << rect.omkrets() << endl;
    return 0;
}
