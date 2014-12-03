#include <iostream>

#include "bostad.h"

using namespace std;

int main()
{
    /*
    Kok kok(12, false, true);
    Badrum badrum(4, true);
    Vardagsrum vardagsrum(24, false);
    Sovrum sovrum1(16, 4);
    Sovrum sovrum2(3, 1);

    kok.skriv();
    badrum.skriv();
    vardagsrum.skriv();
    sovrum1.skriv();
    sovrum2.skriv();
    */

    int sovrumsstorlek[2] = {16, 14};
    int garderober[2] = {4, 3};
    Bostad minLya(12, false, true,
                  4, true,
                  24, false,
                  sovrumsstorlek,
                  garderober,
                  sizeof(sovrumsstorlek) / sizeof(int));
    minLya.skriv();

    return 0;
}
