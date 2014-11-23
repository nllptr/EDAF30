#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>

#include "word.h"

using namespace std;

class Dictionary
{
public:
    void addWord(char *sw, char *eng);
    string findSwedish(char *sw);
    void printAll();
private:
    vector<Word> v;
};

#endif // DICTIONARY_H
