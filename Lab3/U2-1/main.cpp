#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "mynt.h"

using namespace std;

void ettMynt();
void tvaMynt();
void nMynt();

int main()
{
    srand(time(NULL));
    nMynt();
    return 0;
}

void ettMynt() {
    Mynt mynt;
    cout << "Hur många gånger vill du kasta myntet? ";
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        mynt.kasta();
        cout << i << ": ";
        mynt.visa();
        cout << endl;
    }
}

void tvaMynt() {
    Mynt mynt1, mynt2;
    cout << "Hur många gånger vill du kasta de två mynten? ";
    int n, equal = 0;
    cin >> n;
    cout << setw(5) << "Kast" << setw(10) << "Mynt 1" << setw(10) << "Mynt 2" << endl;
    for(int i = 1; i <= n; i++) {
        cout << setw(5) << i;
        mynt1.kasta();
        mynt2.kasta();
        if(mynt1.uppsida() == mynt2.uppsida()) equal++;
        cout << setw(10);
        mynt1.visa();
        cout << setw(10);
        mynt2.visa();
        cout << endl;
    }
    cout << endl << "Mynten visade lika " << equal << " gånger." << endl;
}

void nMynt() {
    cout << "Hur många mynt vill du kasta? ";
    int mynt;
    cin >> mynt;

    cout << "Hur många gånger vill du kasta mynten? ";
    int kast;
    cin >> kast;

    // Dynamically allocate array.
    Mynt * mPtr = new Mynt[mynt];
    // Initialize array
    for(int i = 0; i < mynt; i++)
        mPtr[i] = Mynt();


    // Print first line of output
    cout << setw(4) << "Kast";
    for(int i = 0; i < mynt; i++)
        cout << setw(7);
    cout << endl;

    int lika = 0;

    for(int i = 1; i <= kast; i++) {
        cout << setw(4) << i;
        bool allaLika = true;
        Myntsida sida;
        for(int j = 0; j < mynt; j++) {
            mPtr[j].kasta();
            if(j == 0)
                sida = mPtr[j].uppsida();
            else
                if(mPtr[j].uppsida() != sida)
                    allaLika = false;
            cout << setw(7);
            mPtr[j].visa();
        }
        cout << endl;
        if(allaLika) lika++;
    }
    cout << endl << "Mynten visade alla lika " << lika << " gånger." << endl;
}
