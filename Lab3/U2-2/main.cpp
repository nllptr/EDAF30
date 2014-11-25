#include <iostream>
#include "mynt.h"

using namespace std;

int main()
{
    Mynt mynt;
    int n;
    cout << "Enter n: "; cin >> n;
    int krona = 0, klave = 0;
    for(int i = 0; i < n; i++) {
        mynt.kasta();
        mynt.visa();
        if(mynt.uppsida() == 0) {
            krona++;
        } else {
            klave++;
        }
    }
    cout << "Krona: " << krona << endl;
    cout << "Klave: " << klave << endl;
}
