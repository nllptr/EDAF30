#include "word.h"
#include <cstring>

Word::Word(char *sw, char *eng) {
    swedish = new char[strlen(sw)];
    strcpy(swedish, sw);
    english = new char[strlen(eng)];
    strcpy(english, eng);
}

Word::~Word() {
    delete[] swedish;
    delete[] english;
}

const char *Word::get_sw() const {
    return swedish;
}

const char *Word::get_eng() const {
    return english;
}
