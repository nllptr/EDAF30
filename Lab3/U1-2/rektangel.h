#ifndef REKTANGEL_H
#define REKTANGEL_H

class Rektangel
{
public:
    Rektangel();
    void sattVarden(double x, double y);
    double area();
    void visa();
    double omkrets();
    void forstora(double n);
private:
    double x;
    double y;
};

#endif
