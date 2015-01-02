#ifndef RUM_H
#define RUM_H

#include <iostream>

using namespace std;

class Rum
{
public:
    Rum(int y) : yta(y) {}
    virtual ~Rum() {}
    virtual void skriv() const { cout << "Yta: " << yta; }
private:
    int yta;
};

class Badrum : public Rum {
public:
    Badrum(int yta, bool dusch) : Rum(yta), harDusch(dusch) {}
    ~Badrum() {}
    void skriv() const {
        cout << "Badrum: "; Rum::skriv(); cout << ", Dusch: " << (harDusch ? "Ja" : "Nej") << endl;
    }
private:
    bool harDusch;
};

class Kok : public Rum {
public:
    Kok(int yta, bool disk, bool frys) : Rum(yta), harDiskmaskin(disk), harFrys(frys) {}
    ~Kok() {}
    void skriv() const { cout << "Kök: "; Rum::skriv(); cout << ", Diskmaskin: " << (harDiskmaskin ? "Ja" : "Nej") << ", Frys: " << (harFrys ? "Ja" : "Nej") << endl; }
private:
    bool harDiskmaskin;
    bool harFrys;
};

class Sovrum : public Rum {
public:
    Sovrum() : Rum(0), antalGarderober(0) {}
    Sovrum(int yta, int garderober) : Rum(yta), antalGarderober(garderober) {}
    ~Sovrum() {}
    void skriv() const { cout << "Sovrum: "; Rum::skriv(); cout << ", " << antalGarderober << (antalGarderober > 1 ? " garderober" : " garderob") << endl; }
private:
    int antalGarderober;
};

class Vardagsrum : public Rum {
public:
    Vardagsrum(int yta, bool balkong) : Rum(yta), harBalkong(balkong) {}
    ~Vardagsrum() {}
    void skriv() const { cout << "Vardagsrum: "; Rum::skriv(); cout << ", Balkong: " << (harBalkong ? "Ja" : "Nej") << endl; }
private:
    bool harBalkong;
};

#endif
