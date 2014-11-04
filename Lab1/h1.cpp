#include <iostream>

using namespace std;

int comp (int, int, int);

int main() {
    // x = (a > b) ? a : (b > c) ? b : c ; as if statements

    for (int a = 1; a <= 3; a++) {
        for (int b = 1; b <= 3; b++) {
            for (int c = 1; c <= 3; c++) {
                int x  = 0;
                int m = a; if (b > m) m = b; if (c > m) m = c;

                x = comp (a, b, c);

                cout << "a b c x = " << a << " " << b << " " << c << " " << x;
                if (x != m) cout << " Fel: max = " << m;
                cout << endl;
            }
        }
    }

    return 0;
}

int comp (int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}


