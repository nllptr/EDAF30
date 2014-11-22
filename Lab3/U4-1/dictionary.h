#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <cstring>

class Dictionary
{
public:
    Dictionary();
    void addWord(char *sw, char *eng);
    char * findSwedish(char *sw);
private:
    vector<string> v;
};

#endif // DICTIONARY_H
