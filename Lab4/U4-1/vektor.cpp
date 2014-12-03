#include "vektor.h"
#include <assert.h>
#include <stdexcept>
using namespace std;


Vektor::Vektor(int lng) : ant(lng) {
    //assert(ant>=0); // Indexkontroll
    if(ant < 0) throw invalid_argument("Vektor::Vektor(int lng): lng < 0");
    p = new int[ant]; // Dynamisk allokering
}

//Kopieringskonstruktor
Vektor::Vektor(const Vektor& v) : ant(v.ant) {
    p = new int[ant];
    for (int i=0; i<ant; i++)
        p[i] = v.p[i];
}

//Deallokera allt dynamiskt minnesutrymme
Vektor::~Vektor() {
    delete [] p;
}

int Vektor::get_elem(int ind) {
    assert(ind>=0 && ind<ant);
    return p[ind];
}
void Vektor::set_elem(int ind, int val) {
    assert(ind>=0 && ind<ant);
    p[ind] = val;
}

// Medlemsfunktion som returnerar det
// aktuella objektet inkrementerat
Vektor& Vektor::inc() {
    for (int i=0; i<ant; i++)
        p[i]++;
    return *this; // this är ju pekare
}

bool Vektor::operator==(const Vektor& v) const {
    if (ant!=v.ant)
        return false;
    for (int i=0; i<ant; i++)
        if (p[i] != v.p[i])
            return false;
    return true;
}
// v1 == v2 tolkas som v1.operator==(v2)

const Vektor& Vektor::operator+=(const Vektor& v) {
    assert(ant == v.ant);
    for (int i=0; i<ant; i++)
        p[i] += v.p[i];
    return *this;
}
// Referens till konstant som retur för att
// t.ex. (v1 += v2) += v3 ej ska kunna ske

Vektor Vektor::operator+(const Vektor& v) const {
    assert(ant == v.ant);
    Vektor temp(*this);
    temp += v;
    return temp;
}
// Ingen referens som returvärde (för att undvika
// kvardröjande pekare (dangling pointers))

const Vektor& Vektor::operator+=(int d) {
    for (int i=0; i<ant; i++)
        p[i] += d;
    return *this;
}

Vektor Vektor::operator+(int d) const {
    Vektor temp(*this);
    temp += d;
    return temp;
}

Vektor Vektor::operator- () const {
    Vektor temp(*this); //Temp. kopia
    for (int i=0; i<ant; i++)
        temp.p[i] = -temp.p[i];
    return temp;
}

const Vektor& Vektor::operator++ () { // prefix
    return (*this) += 1; // Returnera inkrementerad
}

Vektor Vektor::operator++ (int) {     // postfix
    Vektor temp(*this); // Kopia av detta objekt
    (*this) += 1;
    return temp; // Returnera oinkrementerad kopia
}

const Vektor& Vektor::operator=(const Vektor& v) {
    if (this != &v) {//Uteslut tilld. till sig själv
        delete[] p; // Städa bort gammal bråte
        ant = v.ant;
        p = new int[ant]; // Fixa plats för ny vektor
        for (int i=0; i<ant; i++)
            p[i] = v.p[i];
    }
    return *this;
}

int& Vektor::operator[] (int i) {
    assert(i>=0 && i<ant);
    return p[i]; // Returnerar en referens
} // Kan anv. i v.l. i en tilldelning

// Överlagrad av variant för konstanta objekt
int Vektor::operator[] (int i) const {
    assert(i>=0 && i<ant);
    return p[i]; // Returnerar en kopia
} // Kan ej anv i v.l. i en tilldelning!

void kvadrera(Vektor& v) {
    for (int i=0; i<v.ant; i++)
        v.p[i] *= v.p[i];
}

Vektor operator+ (int d, const Vektor& v) {
    return v + d; // Utnyttjar andra +-op.!
}

ostream& operator<<(ostream& o, const Vektor& v) {
    o << '{';
    if (v.ant > 0)
        o << v.p[0];
    for (int i=1; i<v.ant; i++)
        o << ", " << v.p[i];
    o << '}';
return o;
}
