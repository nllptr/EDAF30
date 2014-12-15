#ifndef FALT_H
#define FALT_H

#include <iostream>

using namespace std;

template <class T>
void skrivUtFalt(T falt[], int n)
{
    for(int i = 0; i < n; i++) {
        cout << falt[i] << " ";
    }
}

#endif
