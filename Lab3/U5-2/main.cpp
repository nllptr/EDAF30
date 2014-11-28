#include <iostream>

#include "kvadrat.h"

using namespace std;

int main()
{
    Kvadrat k1, k2(5);
    cout << "k1: " << k1.area() << endl << "k2: " << k2.area() << endl;
    k1 = k1 + 4;
    ++k2;
    cout << "k1: " << k1.area() << endl << "k2: " << k2.area() << endl;
    --k1;
    k2 = k2 - 3;
    cout << "k1: " << k1.area() << endl << "k2: " << k2.area() << endl;

    return 0;
}
