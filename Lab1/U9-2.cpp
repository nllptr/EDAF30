#include <iostream>
#include <string>

using namespace std;

string toUpperCase(string);

int main() {
    string alphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string in;
    string out = "";
    getline(cin, in);
    in = toUpperCase(in);
    for(int i = 0; i < in.length(); i++) {
        if(in[i] >= 'A' && in[i] <= 'Z') {
            out += alphabet[in[i]%65];
        } else {
            out += in[i];
        }

    }
    cout << out;
}

string toUpperCase(string lower) {
    string upper = "";
    for(int i = 0; i < lower.length(); i++) {
        if(lower[i] >= 'a' && lower[i] <= 'z') {
            upper += lower[i] - 32;
        } else {
            upper += lower[i];
        }
    }
    return upper;
}
