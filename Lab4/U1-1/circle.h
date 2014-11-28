#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    Circle(double r = 0) : radius(r) {}
    double getArea() const;
    double getRadius() const { return radius; }
private:
    double radius;
};

#endif // CIRCLE_H
