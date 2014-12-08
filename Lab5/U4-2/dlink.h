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

void put_before(Element *e, int i)
{
    Element *pNew = new Element(e, e->bak, i);
    e->bak->fram = pNew;
    e->bak = pNew;
}

void put_first(Element *first, int i)
{
    put_before(first->fram, i);
}

void put_after(Element *e, int i)
{
    put_before(e->fram, i);
}

void put_last(Element *first, int i)
{
    put_before(first->bak, i);
}

void print_list(Element *first)
{
    Element *p;
    for(p = first->fram; p != first; p = p->fram) {
        cout << p->data << endl;
    }
}

Element* linear_search(Element *first, int i)
{
    Element *p;
    for(p = first->fram; p != first; p = p->fram) {
        if(p->data == i) return p;
    }
    return NULL;
}


#endif
