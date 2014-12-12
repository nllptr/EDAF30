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
    char str[] = "Testar lite med tecken";
    skrivUtFalt(str, 22);
    quicksort::quicksort(str, 0, 21);
    skrivUtFalt(str, 22);
    return 0;
}

