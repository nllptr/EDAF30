#include <iostream>

#include "binarysearch.h"

using namespace std;

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int *correct_int = &arr1[5];
    cout << "Address to correct int:    " << correct_int << " (value: " << *correct_int << ")" << endl;
    int *found_int = bin_sok(6, &arr1[0], &arr1[5]);
    cout << "Address to found int:      " << found_int << (correct_int == found_int ? " => OK!" : " => Incorrect!") << endl << endl;

    double arr2[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
    double *correct_dbl = &arr2[4];
    cout << "Address to correct double: " << correct_dbl << " (value: " << *correct_dbl << ")" << endl;
    double *found_dbl = bin_sok(5.6, &arr2[0], &arr2[5]);
    cout << "Address to found double:   " << found_dbl << (correct_dbl == found_dbl ? " => OK!" : " => Incorrect!") << endl << endl;

    int arr3[] = {1, 2, 3, 4, 5, 6};
    int *not_found_int = bin_sok(7, &arr3[0], &arr3[5]);
    cout << "Address when not found:    " << not_found_int << endl;

    return 0;
}
