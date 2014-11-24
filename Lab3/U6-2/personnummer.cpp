#include "personnummer.h"
#include <iostream>
#include <cstring>

using namespace std;

Personnummer::Personnummer() : valid(false)
{
    strcpy(pNr, "0000000000");
}

bool Personnummer::operator !()
{
    return !valid;
}

bool Personnummer::checkValid(char *str) {
    for(int i = 0; i < 10; i++) {
        if(!isdigit(str[i])) {
            cout << "Personnummer får bara innehålla siffror(0-9).\n";
            return false;
        }
    }

    if(strlen(str) != 10) {
        cout << "Personnummer måste vara 10 siffror.\n";
        return false;
    }

    int numbers[9];
    for(int i = 0; i < 9; i++) {
        if(i % 2 == 0) {
            numbers[i] = (str[i] - '0') * 2;
        } else {
            numbers[i] = (str[i] - '0');
        }
    }
    int total = 0;
    for(int i = 0; i < 9; i++) {
        if(numbers[i] > 9) {
            total += ((numbers[i] / 10) + (numbers[i] % 10));
        } else {
            total += numbers[i];
        }
    }
    if((10 - (total % 10)) != (str[9] - '0')) {
        cout << "Sista siffran matchar inte.\n";
        return false;
    }

    return true;
}

ostream& operator<<(ostream& o, Personnummer& p)
{
    o << p.pNr;
    return o;
}

istream& operator>>(istream& i, Personnummer& p)
{
    char tmp[11];
    i >> tmp;
    if(p.checkValid(tmp)) {
        strcpy(p.pNr, tmp);
        p.valid = true;
    }
    return i;
}
