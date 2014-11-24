#ifndef PERSONNUMMER_H
#define PERSONNUMMER_H

#include <iostream>

using namespace std;

class Personnummer
{
public:
    Personnummer();
    bool operator!();

    friend ostream& operator<<(ostream& o, Personnummer& p);
    friend istream& operator>>(istream& i, Personnummer& p);
private:
    bool checkValid(char *str);
    char pNr[11];
    bool valid;
};

#endif // PERSONNUMMER_H
