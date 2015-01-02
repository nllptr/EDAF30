#include "bostad.h"

Bostad::Bostad(int kyta, bool kdisk, bool kfrys,
               int byta, bool bdusch,
               int vyta, bool vbalkong,
               int *syta, int *sgarderober, int santal) :
    kok(kyta, kdisk, kfrys),
    badrum(byta, bdusch),
    vardagsrum(vyta, vbalkong),
    sovrumantal(santal) {
    sovrum = new Sovrum[santal];
    for(int i = 0; i < sovrumantal; i++) {
        sovrum[i] = Sovrum(syta[i], sgarderober[i]);
    }
}

Bostad::~Bostad() {
    delete[] sovrum;
    sovrum = nullptr;
}

void Bostad::skriv() const {
    kok.skriv();
    badrum.skriv();
    vardagsrum.skriv();
    for(int i = 0; i < sovrumantal; i++) {
        sovrum[i].skriv();
    }
}
