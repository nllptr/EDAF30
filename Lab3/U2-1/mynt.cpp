#include "mynt.h"
#include <iostream>
#include <cstdlib>

Mynt::Mynt()
{
    std::srand(time(NULL));
    sida = std::rand() % 2;
}

void Mynt::kasta() {
    sida = std::rand() % 2 == 0 ? krona : klave;
}

void Mynt::visa() {
    std::cout << ((uppsida() == krona) ? "Krona" : "Klave") << std::endl;
}

Myntsida Mynt::uppsida() {
    return sida == 0 ? krona : klave;
}
