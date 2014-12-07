#ifndef PET_H
#define PET_H

#include <iostream>

class Pet
{
public:
    Pet();
    virtual ~Pet();
    void virtual speak() = 0;
};

#endif
