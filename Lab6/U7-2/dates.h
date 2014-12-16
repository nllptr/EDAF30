#ifndef DATES_H
#define DATES_H

#include <stdexcept>

using namespace std;

short int pack(int y, int m, int d) {
    short int packed = 0;
    if(y < 0 || y > 99) {
        cout << "Year too big." << endl;
        return 0;
    } else if(m > 12) {
        cout << "Month too big." << endl;
        return 0;
    } else if(d > 31) {
        cout << "Day too big." << endl;
        return 0;
    }

    y = y << 9;
    m = m << 5;
    packed = y | m | d;
    return packed;
}

void unpack(short int packed, int &y, int &m, int &d) {
    d = packed & 0b0000000000011111;
    m = (packed & 0b0000000111100000) >> 5;
    y = (packed & 0b1111111000000000) >> 9;
}

#endif
