#include <iostream>
#include "personnummer.h"

using namespace std;

int main()
{
    Personnummer persnum;
    cout << "Ange personnummer: ";
    cin >> persnum;
    while (!persnum) {
        cerr << "Personnumret är felaktigt!\n";
        cout << "Ange personnummer: ";
        cin >> persnum;
    }
    cout << "Personnumret " << persnum << " är korrekt.\n";
    return 0;
}
