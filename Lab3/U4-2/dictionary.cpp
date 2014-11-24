#include "dictionary.h"

#include <vector>
#include <cstring>

void Dictionary::addWord(char *sw, char *eng) {
    Word w(sw, eng);
    v.push_back(w);
}

string Dictionary::findEnglish(char *sw) {
    for(Word w : v) {
        if(strcmp(sw, w.get_sw()) == 0) {
            return string(w.get_eng());
        }
    }
    return "Ingen översättning hittades.";
}
