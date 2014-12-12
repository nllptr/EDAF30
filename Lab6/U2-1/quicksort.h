#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../U1-1/printarray.h"

namespace {

    template <class T>
    int choosePivot(T array[], int low, int high)
    {
        return low + ((high - low) / 2);
    }

    template <class T>
    int partition(T array[], int low, int high)
    {
        int pivotIndex = choosePivot(array, low, high);
        int pivotValue = array[pivotIndex];
        std::swap(array[pivotIndex], array[high]);
        int storeIndex = low;
        for(int i = low; i < high; i++) {
            if(array[i] < pivotValue) {
                std::swap(array[i], array[storeIndex]);
                storeIndex++;
            }
        }
        std::swap(array[storeIndex], array[high]);
        return storeIndex;
    }
}

namespace quicksort {

    template <class T>
    void quicksort(T array[], int low, int high)
    {
        if(low < high) {
            int p = partition(array, low, high);
            quicksort(array, low, p - 1);
            quicksort(array, p + 1, high);
        }
    }
}
#endif // QUICKSORT_H
