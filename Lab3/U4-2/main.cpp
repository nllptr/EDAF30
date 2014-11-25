#include "dictionary.h"

#include <iostream>

using namespace std;

int main()
{
    Dictionary dict;
    char sw[20];
    char eng[20];
    int in = 0;
    while(true) {
        cout << "Enter action(1 = add new word; 2 = look up word; 3 = exit: ";
        cin >> in;
        if(in == 1) {
            cout << "Enter Swedish word: "; cin >> sw;
            cout << "Enter English word: "; cin >> eng;
            dict.addWord(sw, eng);
        } else if(in == 2) {
            cout << "Enter Swedish word: "; cin >> sw;
            cout << "Swe: " << sw << endl << "Eng: " << dict.findEnglish(sw) << endl;
        } else if(in == 3) {
            break;
        }
    }

    return 0;
}
