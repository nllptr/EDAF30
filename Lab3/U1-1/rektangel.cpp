#include "rektangel.h"
#include <iostream>

using namespace std;

Rektangel::Rektangel()
{
    x = 0;
    y = 0;
}

void Rektangel::sattVarden(double x, double y) {
    this->x = x;
    this->y = y;
}

double Rektangel::area() {
    return x * y;
}

double Rektangel::omkrets() {
    return 2 * x + 2 * y;
}

void Rektangel::forstora(double faktor) {
    x *= faktor;
    y *= faktor;
}

void Rektangel::visa() {
    cout << "x: " << x << ", y: " << y;
}
