#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void kvadratkubtabell(int n);

int main()
{
    kvadratkubtabell(100);
    return 0;
}

void kvadratkubtabell(int n) {
    cout << "Kvadratkubtabell för " << n << endl;

    // Calculate max number of digits for nice formatting
    int digits = 0;
    if(n < 0) digits = 1;
    int tmpNumber = pow(n, 3);
    while(tmpNumber) {
        tmpNumber /= 10;
        digits++;
    }

    // Write table
    cout << setw(digits) << "n" << " | " <<setw(digits) << "^2" << " | " << setw(digits) << "^3" << " | " << endl;
    string divider = "--------"; // Initial value, accounting for the " | "-snippets.
    for(int i = 0; i < 3 * digits; i++) divider.append("-");
    cout << divider << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cout << setw(digits) << pow(i, j) << " | ";
        }
        cout << endl;
    }
}
