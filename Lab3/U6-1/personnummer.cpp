#include "personnummer.h"

#include <cstring>

Personnummer::Personnummer() : valid(false)
{
    strcpy(pNr, "0000000000");
}

bool Personnummer::operator!()
{
    return !valid;
}

bool Personnummer::checkValid(char *str)
{
    // Check that the string is 10 characters long
    if(strlen(str) != 10) {
        cout << str << " is not 10 digits!" << endl;
        return false;
    }

    // Check that the string is all numerals
    for(int i = 0; i < 10; i++) {
        if(!isdigit(str[i])) {
            cout << str[i] << " is not a digit!" << endl;
            return false;
        }
    }

    // Check control digit
    int tmp[9];
    for(int i = 0; i < 9; i++) {
        tmp[i] = (i % 2 == 0) ? (str[i] - '0') * 2 : (str[i] - '0');
    }
    for(int i = 0; i < 9; i++)
        cout << tmp[i] << endl;
    int sum = 0;
    for(int i = 0; i < 9; i++) {
        if(tmp[i] > 9) {
            cout << "Adding " << (tmp[i] / 10) + (tmp[i] % 10) << endl;
            sum += (tmp[i] / 10) + (tmp[i] % 10);
        } else {
            cout << "Adding " << tmp[i] << endl;
            sum += tmp[i];
        }
    }
    int control = 10 - (sum % 10);
    cout << "10 - " << sum % 10 << " = " << control << endl;
    if((str[9] - '0') != control) return false;

    cout << "valid" << endl;
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
