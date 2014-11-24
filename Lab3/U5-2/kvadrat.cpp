#include "kvadrat.h"

using namespace std;

Kvadrat::Kvadrat() {
    sida = 1;
}

Kvadrat::Kvadrat(int sida) {
    this->sida = sida;
}

int Kvadrat::area() {
    return sida*sida;
}

const Kvadrat& Kvadrat::operator++() {
    sida++;
    return *this;
}

const Kvadrat& Kvadrat::operator--() {
    if(sida > 0){
        sida--;
    }
    return *this;
}

Kvadrat Kvadrat::operator+(const int i) {
    Kvadrat temp(this->sida);
    temp.sida += i;
    return temp;
}

Kvadrat Kvadrat::operator-(const int i) {
    Kvadrat temp(this->sida);
    if(temp.sida > 0) {
        temp.sida -= i;
    }
    return temp;
}

bool operator==(const Kvadrat& k1, const Kvadrat& k2) {
    if(k1.sida == k2.sida) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(const Kvadrat& k1, const Kvadrat& k2) {
    if(k1.sida > k2.sida) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(const Kvadrat& k1, const Kvadrat& k2) {
    if(k1.sida < k2.sida) {
        return true;
    }
    else {
        return false;
    }
}
