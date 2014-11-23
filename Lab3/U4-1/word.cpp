#include "word.h"
#include <cstring>

Word::Word(char *sw, char *eng) {
    swedish = new char[strlen(sw)];
    strcpy(swedish, sw);
    english = new char[strlen(eng)];
    strcpy(english, eng);
}

Word::Word(const Word &w) {
    swedish = new char[strlen(w.get_sw())];
    strcpy(swedish, w.get_sw());
    english = new char[strlen(w.get_eng())];
    strcpy(english, w.get_eng());
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
