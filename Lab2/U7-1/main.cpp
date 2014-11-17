#include <iostream>

using namespace std;

int sumSquaresIterative(int n);
int sumSquaresRecursive(int n);

int main()
{
    int n = 100;
    cout << sumSquaresIterative(n) << endl;
    cout << sumSquaresRecursive(n) << endl;
    return 0;
}

int sumSquaresIterative(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int sumSquaresRecursive(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n * n + sumSquaresRecursive(n - 1);
    }
}
