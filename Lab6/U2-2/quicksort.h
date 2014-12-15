#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

using namespace std;

template <class T>
int pivot(T arr[], int left, int right) {
    return left + (right - left)/2;
}

template <class T>
int partition(T arr[], int left, int right)
{
    int index = pivot(arr, left, right);
    T value = arr[index];
    swap(arr[index], arr[right]);
    int save = left;
    for(int i = left; i < right; i++) {
        if(arr[i] < value) {
            swap(arr[i], arr[save]);
            save++;
        }
    }
    swap(arr[save], arr[right]);
    return save;
}

template <class T>
void quicksort(T arr[], int left, int right)
{
    if(left < right) {
        int p = partition(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}

#endif
