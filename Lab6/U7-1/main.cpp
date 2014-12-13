#include <iostream>
#include <climits>

#include "packeddates.h"

using namespace std;

int main()
{
    cout << "Packing 14-12-13..." << endl;
    short int packed = packDate(14, 12, 13);
    cout << "Packed size of date is " << sizeof(packed) << " bytes." << endl;
    int year, month, day;
    unpackDate(packed, year, month, day);
    cout << "Unpacked date. YY-MM-DD: " << year << "-" << month << "-" << day << endl;
    return 0;
}

