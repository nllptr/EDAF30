#include <iostream>
#include <cstdlib>

#include "singlell.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Element *first = randomize_list(10);
    cout << "The list:" << endl;
    print_list(first);

    int greatest = find_greatest(first);
    cout << endl << "The greatest: " << greatest << endl;

    delete first;
    first = NULL;
    return 0;
}

