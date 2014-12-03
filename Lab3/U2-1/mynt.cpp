#include "mynt.h"
#include <iostream>
#include <cstdlib>

Mynt::Mynt()
{
    //std::srand(time(NULL));
    kasta();
}

void Mynt::kasta() {
    sida = std::rand() % 2 == 0 ? krona : klave;
}

void Mynt::visa() {
    std::cout << (sida == krona ? "Krona" : "Klave");
}

Myntsida Mynt::uppsida() {
    return sida;
}
