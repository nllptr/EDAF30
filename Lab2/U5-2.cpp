#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void poly(int*);

int main() {
    int coeff[5];
    cout << "p(x) = ax⁴ + bx³ + cx² + dx + e" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Enter " << (char)(97 + i) << ": ";
        cin >> coeff[i];
    }
    poly(coeff);
}

void poly(int* coeff){
    srand(time(NULL));
    int x = rand()%9 + 1;
    int total = 0;
    for(int i = 0; i < 5; i++) {
    total += pow(x, 4-i)*coeff[i];
    }
    cout << "p(" << x << ") = " << coeff[0] << "*" << x << "⁴ + " << coeff[1] << "*" << x << "³ + " << coeff[2] << "*" << x << "² + " << coeff[3] << "*" << x<< " + " << coeff[4] << endl;
    cout << " = " << total;
}
