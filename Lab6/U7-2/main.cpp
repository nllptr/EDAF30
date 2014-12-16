#include <iostream>
#include "dates.h"

using namespace std;

int main()
{
    int year = 1;
    int month = 1;
    int day = 1;
    short int packed = pack(year, month, day);
    int y;
    int m;
    int d;
    unpack(packed, y, m, d);
    cout << "y: " << y << endl;
    cout << "m: " << m << endl;
    cout << "d: " << d << endl;

    cout << hex << endl << packed << endl;
    return 0;
}
