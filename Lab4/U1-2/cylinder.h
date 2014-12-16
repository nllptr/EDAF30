#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class Cylinder : public Circle
{
public:
    Cylinder(double r = 0, double h = 0) : Circle(r), height(h) {}
    double getVolume() const { return getArea() * height; }
    double getHeight() const { return height; }
private:
    double height;
};

#endif
