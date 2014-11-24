#include "personnummer.h"

#include <cstring>

Personnummer::Personnummer() : valid(false)
{
    strcpy(pNr, "0000000000");
}

bool Personnummer::operator !()
{
    return !valid;
}

bool Personnummer::checkValid(char *str)
{
    // Check that the string is 10 characters long
    if(strlen(str) != 10) return false;

    // Check that the string is all numerals
    for(int i = 0; i < 10; i++)
        if(!isdigit(str[i])) return false;

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
