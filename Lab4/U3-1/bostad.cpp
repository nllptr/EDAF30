#include "bostad.h"

Bostad::Bostad(int k_yta, bool k_disk, bool k_frys,
               int b_yta, bool b_dusch,
               int v_yta, bool v_balkong,
               int *s_yta, int *s_garderober, int s_antal) :
    kok(k_yta, k_disk, k_frys),
    badrum(b_yta, b_dusch),
    vardagsrum(v_yta, v_balkong),
    sovrum_antal(s_antal) {
    sovrum = new Sovrum[s_antal];
    for(int i = 0; i < sovrum_antal; i++) {
        sovrum[i] = Sovrum(s_yta[i], s_garderober[i]);
    }
}

Bostad::~Bostad() {
    delete[] sovrum;
    sovrum = NULL;
}

void Bostad::skriv() const {
    kok.skriv();
    badrum.skriv();
    vardagsrum.skriv();
    for(int i = 0; i < sovrum_antal; i++) {
        sovrum[i].skriv();
    }
}
