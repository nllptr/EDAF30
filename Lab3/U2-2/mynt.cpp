#include "mynt.h"
#include <iostream>

using namespace std;

Mynt::Mynt()
{
    srand(time(NULL));
    kasta();
}

void Mynt::kasta() {
    sida = rand() % 2 == 0 ? krona : klave;
}

void Mynt::visa() {
    cout << "Sida: " << ((sida == 0) ? "krona" : "klave") << endl;
}

Myntsida Mynt::uppsida() {
    return sida == 0 ? krona : klave;
}
