#include <iostream>

using namespace std;

int addSqrtRec(int);
int addSqrtIte(int);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Recursive: " << addSqrtRec(n) << endl;
    cout << "Iterative: " << addSqrtIte(n);
}

int addSqrtRec(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n*n+addSqrtRec(n-1);
    }
}

int addSqrtIte(int n) {
    int total = 0;
    for(int i = 1; i <= n; i++) {
        total += i*i;
    }
    return total;
}
