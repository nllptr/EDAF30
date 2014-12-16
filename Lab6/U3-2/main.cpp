#include <iostream>
#include "../U2-2/quicksort.h"
#include "../U1-2/falt.h"
#include "bin_sok.h"

using namespace std;

int main()
{
    int n[] = {2, 6, 1, 9, 8, 4, 5};
    cout << "n: ";
    skrivUtFalt(n, (sizeof(n)/sizeof(int)));
    quicksort(n, 0, (sizeof(n)/sizeof(int)) - 1);
    cout << endl << "n after quicksort: ";
    skrivUtFalt(n, (sizeof(n)/sizeof(int)));
    int *result = bin_sok(9, &n[0], &n[4]);
    if(result != nullptr) {
        cout << endl << *result;
    } else {
        cout << endl << "not found";
    }
    return 0;
}
