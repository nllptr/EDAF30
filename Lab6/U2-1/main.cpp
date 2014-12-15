#include <iostream>

#include "quicksort.h"
#include "../U1-1/printarray.h"

using namespace std;

int main()
{
    cout << "Test 1:" << endl;
    int test1[] = {5, 22, 11, 7, 9, 2, 7, 3, 1, 32, 6};
    skrivUtFalt(test1, 10);
    quicksort::quicksort(test1, 0, 9);
    skrivUtFalt(test1, 10);

    cout << endl << endl << "Test 2:" << endl;
    char str[] = "Testing with characters";
    skrivUtFalt(str, 22);
    quicksort::quicksort(str, 0, 21);
    skrivUtFalt(str, 22);

    cout << endl << endl << "Test 3:" << endl;
    string str2[] = {"Testing with characters", "Another test", "more elements!"};
    skrivUtFalt(str2, 3);
    quicksort::quicksort(str2, 0, 2);
    skrivUtFalt(str2, 3);

    return 0;
}

