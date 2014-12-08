#include <iostream>

#include "dbllinked.h"

using namespace std;

int main()
{
    // Example 1, using doubly-linked lists as implemented on page 502.
    // However, this only does linear search
    Element *first = new Element();
    first->fram = first;
    first->bak = first;
    put_first(first, 1);
    put_last(first, 2);
    put_last(first, 3);
    print_list(first);
    cout << "What are you looking for? ";
    int d;
    cin >> d;
    Element *r = linear_search(first, d);
    cout << "Found: ";
    if(r == NULL) cout << "nothing" << endl;
    else cout << r->data << endl;

    return 0;
}
