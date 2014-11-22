#ifndef WORD_H
#define WORD_H

class Word
{
public:
    Word(char *sw, char *eng);
    ~Word();
    const char *get_sw() const;
    const char *get_eng() const;
private:
    char *swedish;
    char *english;
};

#endif // WORD_H
