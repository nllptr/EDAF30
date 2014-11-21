#include <iostream>
#include "mynt.h"

using namespace std;

int main()
{
    Mynt mynt;
    mynt.visa();
    cout << endl;
    for(int i = 0; i < 10; i++) {
        mynt.kasta();
        mynt.visa();
    }

    return 0;
}

