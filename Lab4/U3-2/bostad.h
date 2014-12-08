#ifndef BOSTAD_H
#define BOSTAD_H

#include "rum.h"

class Bostad
{
public:
    Bostad(int kyta, bool kdisk, bool kfrys,
           int byta, bool bdusch,
           int vyta, bool vbalkong,
           int *syta, int *sgarderober, int santal);
    ~Bostad();
    void skriv() const;
private:
    Kok kok;
    Badrum badrum;
    Vardagsrum vardagsrum;
    Sovrum *sovrum;
    int sovrumantal;
};

#endif
