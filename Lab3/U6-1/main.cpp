#include <iostream>

#include "personnummer.h"

using namespace std;

int main()
{
    Personnummer persNum;
    cout << "Ange personnummer: ";
    cin >> persNum;
    while(!persNum) {
        cerr << "Personnumret är felaktigt!\n";
        cout << "Ange personnummer: ";
        cin >> persNum;
    }
    cout << "Personnumret " << persNum << " är korrekt.\n";

    return 0;
}

