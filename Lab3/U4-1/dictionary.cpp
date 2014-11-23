#include "dictionary.h"

#include <vector>
#include <cstring>
#include <iostream>
#include <iomanip>

void Dictionary::addWord(char *sw, char *eng) {
    Word w(sw, eng);
    v.push_back(w);
}

string Dictionary::findSwedish(char *sw) {
    for(Word w : v) {
        if(strcmp(sw, w.get_sw()) == 0) {
            return string(w.get_eng());
        }
    }
    return "Ingen översättning hittades.";
}

void Dictionary::printAll() {
    for(Word w : v) {
        cout << setw(20) << left << w.get_sw() << setw(20) << left << w.get_eng() << endl;
    }
}
