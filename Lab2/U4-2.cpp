#include <iostream>

using namespace std;

void downcase(string &str);

int main() {
    string s = "BReAd";
    downcase(s);
    cout << s;
}

void downcase(string &str) {
    string upper = str;
    str = "";
    for(int i = 0; i < upper.length(); i++) {
        if(upper[i] >= 'A' && upper[i] <= 'Z') {
            str += upper[i] + 32;
        } else {
            str += upper[i];
        }
    }
}
