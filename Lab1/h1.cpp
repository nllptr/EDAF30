#include <iostream>

using namespace std;

int comp (int, int, int);
int comp2 (int, int, int);

int main() {

    cout << "Using comp" << endl;  
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
    cout << "--------------------------" << endl;

    cout << "Using comp2" << endl;
    for (int a = 1; a <= 3; a++) {
        for (int b = 1; b <= 3; b++) {
            for (int c = 1; c <= 3; c++) {
                int x  = 0;
                int m = a; if (b > m) m = b; if (c > m) m = c;

                x = comp2 (a, b, c);

                cout << "a b c x = " << a << " " << b << " " << c << " " << x;
                if (x != m) cout << " Fel: max = " << m;
                cout << endl;
            }
        }
    }

    return 0;
}

// Literal translation of x = (a > b) ? a : (b > c) ? b : c;
// Generates wrong maximum for comp(2, 1, 3)
int comp (int a, int b, int c) {
    if (a > b) {
        return a;
    } else if (b > c) {
        return b;
    } else {
        return c;
    }
}

// Fixed version
int comp2 (int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    } else if (b > c) {
        return b;
    } else {
        return c;
    }
}
