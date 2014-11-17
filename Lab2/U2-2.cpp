#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void kvadratkubtabell(int);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    kvadratkubtabell(n);
    return 0;
}

void kvadratkubtabell(int n) {
    int num = pow(n, 3);
    int length = 1;
    while(num > 0) {
        num = num/10;
        length++;
    }
    cout << "Kvadratkubtabell för " << n << endl;
    for(int i = 1; i < n+1; i++) {
        cout << "i: " << setw(3) << i << "   " << setw(length) << pow(i, 2) << "   " << setw(length) << pow(i, 3) << "\n";
    }
}
