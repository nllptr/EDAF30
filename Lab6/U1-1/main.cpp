#include <iostream>
#include <string>

#include "printarray.h"

using namespace std;

int main()
{
    int n[] = {1, 2, 3, 4, 5};
    skrivUtFalt(n, 5);
    string str[4] = {"Hello", "world!", "Awesome!"};
    skrivUtFalt(str, 3);
    return 0;
}
