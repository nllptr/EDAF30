#pragma once
#include <ostream>

class Vektor
{
public:
    friend void kvadrera(Vektor& v);
    friend std::ostream& operator<<(std::ostream& o, const Vektor& v);

    Vektor(int lng = 10); // Även defaultkonstruktor
    Vektor(const Vektor& v); // Kopiering!
    ~Vektor(); // Destruktor
    int lngd() {return ant;} // Inline!
    int get_elem(int ind);
    void set_elem(int ind, int val);
    Vektor& inc();

    bool operator==(const Vektor& v) const;
    const Vektor& operator+=(const Vektor& v);
    Vektor operator+(const Vektor& v) const;
    const Vektor& operator+=(int d);
    Vektor operator+(int d) const;
    Vektor operator- () const;
    const Vektor& operator++ (); // prefix  (++v)
    Vektor operator++ (int);     // postfix (v++)
    // Dummy-parameter i postfix för att se skillnad
    const Vektor& operator=(const Vektor& v);
    int& operator[] (int i);
    int operator[] (int i) const; // Se definitionerna!

private:
    int *p; // Själva vektorn
    int ant;// Antalet element
};

Vektor operator+ (int d, const Vektor& v);
