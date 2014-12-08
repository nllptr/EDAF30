#ifndef DBLLINKED_H
#define DBLLINKED_H

#include <iostream>

using namespace std;

class Element {
public:
    Element *fram, *bak;
    int data;
    Element(Element *f = 0, Element *b = 0, int d = 0) : fram(f), bak(b), data(d) {}
};

void put_before(Element *e, int d)
{
    Element *pNew = new Element(e, e->bak, d);
    e->bak->fram = pNew;
    e->bak = pNew;
}

void put_first(Element *first, int d)
{
    put_before(first->fram, d);
}

void put_after(Element *e, int d)
{
    put_before(e->fram, d);
}

void put_last(Element *first, int d)
{
    put_after(first->bak, d);
}

void print_list(Element *first)
{
    Element *p;
    for(p = first->fram; p != first; p = p->fram) {
        cout << p->data << endl;
    }
}

Element* linear_search(Element *first, int d)
{
    Element *p;
    for(p = first->fram; p != first; p = p->fram) {
        if(p->data == d) return p;
    }
    return NULL;
}

#endif // DBLLINKED_H
