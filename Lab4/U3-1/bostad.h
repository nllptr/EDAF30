#ifndef BOSTAD_H
#define BOSTAD_H

#include "rum.h"

class Bostad
{
public:
    Bostad(int k_yta, bool k_disk, bool k_frys,
           int b_yta, bool b_dusch,
           int v_yta, bool v_balkong,
           int *s_yta, int *s_garderober, int s_antal);
    ~Bostad();
    void skriv() const;
private:
    Kok kok;
    Badrum badrum;
    Vardagsrum vardagsrum;
    Sovrum *sovrum;
    int sovrum_antal;
};

#endif // BOSTAD_H
