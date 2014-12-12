#ifndef PRINTARRAY_H
#define PRINTARRAY_H

#include <iostream>

template <class T>
void skrivUtFalt(T falt[], int n)
{
    std::cout << "[";
    for(int i = 0; i < n; i++) {
        if(i != 0) std::cout << ",";
        std::cout << " " << falt[i];
    }
    std::cout << " ]" << std::endl;
}

#endif // PRINTARRAY_H
