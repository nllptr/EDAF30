#ifndef KUND_H
#define KUND_H

#include <cstdlib>

class Kund
{
public:
    Kund(int arrival) : atid(arrival) {
        btid = (rand() % 4) + 1;
    }
    int ankomst() { return atid; }
    int betjaning() { return btid; }
private:
    int atid;
    int btid;
};

#endif // KUND_H
