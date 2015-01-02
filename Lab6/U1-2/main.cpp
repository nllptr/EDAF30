#include <iostream>
#include "falt.h"

using namespace std;

int main()
{
    int n[] = {1, 3, 5, 7, 9};
    string str[] = {"bread", "butter", "cheese"};
    skrivUtFalt(n, (sizeof(n)/sizeof(int)));
    skrivUtFalt(str, (sizeof(str)/sizeof(string)));
    return 0;
}
