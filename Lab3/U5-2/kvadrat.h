#ifndef KVADRAT_H
#define KVADRAT_H

class Kvadrat {
public:
    Kvadrat();
    Kvadrat(int side);
    int area();
    const Kvadrat& operator++();
    const Kvadrat& operator--();
    Kvadrat operator+(const int i);
    Kvadrat operator-(const int i);
    friend bool operator==(const Kvadrat& k1, const Kvadrat& k2);
    friend bool operator>(const Kvadrat& k1, const Kvadrat& k2);
    friend bool operator<(const Kvadrat& k1, const Kvadrat& k2);
private:
    int sida;
};

#endif
