#ifndef REKTANGEL_H
#define REKTANGEL_H

class Rektangel
{
public:
    Rektangel();
    void sattVarden(double x, double y);
    double area();
    double omkrets();
    void forstora(double faktor);
    void visa();
private:
    double x;
    double y;
};

#endif // REKTANGEL_H
