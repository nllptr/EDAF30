#ifndef BIN_SOK_H
#define BIN_SOK_H

#include <iostream>

using namespace std;

template <class T>
T *bin_sok(T done, T *first, T *last) {
    if(first > last) {
        return 0;
    }
    T *middle = first + (last - first)/2;
    if(done < *middle) {
        return bin_sok(done, first, middle - 1);
    }
    else if(done > *middle) {
        return bin_sok(done, middle + 1, last);
    }
    else {
        return middle;
    }
}

#endif
