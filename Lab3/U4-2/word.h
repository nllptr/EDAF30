#ifndef WORD_H
#define WORD_H

class Word {
public:
    Word(char *sw, char *eng); //Svenskt sw, engelskt eng
    Word(const Word &w);
    ~Word();
    const char *get_sw() const; //Hämta svenskt ord
    const char *get_eng() const; //Hämta engelsk översättning
private:
    char *swedish;
    char *english;
};

#endif
