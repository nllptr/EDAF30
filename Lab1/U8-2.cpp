#include <iostream>
#include <string>

using namespace std;

string toUpperCase(string);

int main() {
    string in;
    string out = "";
    cout << "Skriv ett meddelande (A-Z): ";
    getline(cin, in);
    if(in.length() > 80) {
        cout << "Meddelande för långt.";
        return 1;
    }
    in = toUpperCase(in);
    for(int i = 0; i < in.length(); i++) {
        if(in[i] == ' ' || in[i] == '.' || in[i] == ',' || in[i] == '!' || in[i] == '?') {
            out += in[i];
        } else {
            if(in[i] + 13 > 90) {
                out +=(in[i] + 13) % 90 + 64;
            } else {
                out += in[i] + 13;
            }
        }
    }
    cout << out;
}

string toUpperCase(string lower) {
    string upper = "";
    for(int i = 0; i < lower.length(); i++) {
        if(lower[i] > 90) {
            upper += lower[i] - 32;
        } else {
            upper += lower[i];
        }
    }
    return upper;
}
