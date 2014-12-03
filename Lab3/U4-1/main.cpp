#include <iostream>
#include <string>

#include "dictionary.h"

using namespace std;

int main()
{
    Dictionary dict;
    cout << "Skapade ny ordbok." << endl;
    while(true) {
        cout << "Vad vill du göra? (? för hjälp) ";
        char val;
        cin >> val;
        char sw[20], eng[20];
        switch(val) {
        case '1':
            cout << "Svenskt ord: ";
            cin >> sw;
            cout << "Engels översättning: ";
            cin >> eng;
            dict.addWord(sw, eng);
            break;
        case '2':
            cout << "Vilket svenskt ord vill du söka efter? ";
            char sw[30];
            cin >> sw;
            cout << dict.findSwedish(sw) << endl;
            break;
        case '3':
            cout << "Ej implementerad." << endl;
            break;
        case '4':
            dict.printAll();
            break;
        case 'q':
        case 'Q':
            return 0;
        default:
            cout << "1: Lägg till ord." << endl;
            cout << "2: Sök svenska till engelska." << endl;
            cout << "3: Sök engelska till svenska." << endl;
            cout << "4: Visa alla ord" << endl;
            cout << "q: Avsluta" << endl;
            break;
        }
    }
}
