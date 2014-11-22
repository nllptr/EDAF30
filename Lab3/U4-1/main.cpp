#include <iostream>

#include "word.h"

using namespace std;

int main()
{
    char *s1 = "Hej";
    char *s2 = "Hello";
    Word *w1 = new Word(s1, s2);
    cout << w1->get_sw() << endl << w1->get_eng() << endl;
    delete w1;
}
