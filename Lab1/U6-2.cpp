/*
DISCLAIMER: This code is not made to handle the letters (both upper and lower case) å, ä and ö.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string in;
    string out = "";
    cout << "Skriv in en sträng: ";
    cin >> in;
    for(int i = in.length()-1; i >= 0; i--) {
        out += in[i];
    }
    cout << out;
}
