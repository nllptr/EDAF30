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

void Rektangel::visa() {
    cout << "x: " << x << endl << "y: " << y << endl;
}

double Rektangel::omkrets() {
    return x * 2 + y * 2;
}

void Rektangel::forstora(double n) {
    x = x * n;
    y = y * n;
}
