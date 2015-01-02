#include <iostream>
#include "quicksort.h"
#include "../U1-2/falt.h"

using namespace std;

int main()
{
    int n[] = {2, 6, 1, 9, 8, 4, 5};
    cout << "n: ";
    skrivUtFalt(n, (sizeof(n)/sizeof(int)));
    quicksort(n, 0, 6);
    cout << endl << "n after quicksort: ";
    skrivUtFalt(n, (sizeof(n)/sizeof(int)));

    string str[] = {"a", "b", "ab"};
    cout << endl << "str: ";
    skrivUtFalt(str, (sizeof(n)/sizeof(string)));
    quicksort(str, 0, 2);
    cout << endl << "str after sorting: ";
    skrivUtFalt(str, (sizeof(str)/sizeof(string)));

    return 0;
}
