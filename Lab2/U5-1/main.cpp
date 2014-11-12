#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double poly(double x, vector<double> coeff);

/*
 * Prints the sum of a polynomial using the value x
 * and the coefficients of the vector coeff.
 *
 * The polynomial can have an arbitrary length.
 */
int main()
{
    double x = 3;
    vector<double> coeff = {4.5, 3.2, 7.8};
    for(int i = 0; i < coeff.size(); i++)
        cout << coeff[i] << endl;
    cout << poly(x, coeff);
    return 0;
}

double poly(double x, vector<double> coeff) {
    double returnValue = 0;
    for(int i = 0; i < coeff.size(); i++) {
        returnValue += coeff[i] * pow(x, (coeff.size() - i - 1));
    }
    return returnValue;
}
