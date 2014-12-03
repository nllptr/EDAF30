#include "kvadrat.h"


// Constructors ---------------------------------

Kvadrat::Kvadrat()
{
    side = 1;
}

Kvadrat::Kvadrat(int side)
{
    this->side = side;
}

// Operators ------------------------------------

const Kvadrat& Kvadrat::operator++() {
    ++side;
    return *this;
}

const Kvadrat& Kvadrat::operator--() {
    if(side > 0) --side;
    return *this;
}

Kvadrat Kvadrat::operator +(const int i) {
    Kvadrat temp(this->side);
    temp.side += i;
    return temp;
}

Kvadrat Kvadrat::operator -(const int i) {
    Kvadrat temp(this->side);
    if(temp.side > 0) temp.side -= i;
    return temp;
}

bool operator==(const Kvadrat& k1, const Kvadrat& k2) {
    if(k1.side == k2.side) return true;
    else return false;
}

bool operator>(const Kvadrat& k1, const Kvadrat& k2) {
    if(k1.side > k2.side) return true;
    else return false;
}

bool operator<(const Kvadrat& k1, const Kvadrat& k2) {
    if(k1.side < k2.side) return true;
    else return false;
}

// Functions ------------------------------------

int Kvadrat::area()
{
    return side * side;
}
