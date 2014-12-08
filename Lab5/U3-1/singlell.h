#ifndef SINGLELL_H
#define SINGLELL_H

#include <iostream>

using namespace std;

class Element {
public:
    Element *next;
    int data;
    Element(Element *e, int d) : next(e), data(d) {}
};

void push(Element *& first, int d)
{
    first = new Element(first, d);
}

Element* randomize_list(int n)
{
    Element *e = nullptr;
    for(int i = 0; i < n; i++) {
        push(e, (rand() % 10000));
    }
    return e;
}

int find_greatest(Element *first)
{
    int greatest = -1;
    for(Element *i = first; i; i = i->next) {
        if(i->data > greatest) greatest = i->data;
    }

    return greatest;
}

void print_list(Element *first)
{
    Element *i;
    for(i = first; i; i = i->next) {
        cout << i->data << endl;
    }
}


#endif // SINGLELL_H
