#include <iostream>

#include "dlink.h"

using namespace std;

int main()
{
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
