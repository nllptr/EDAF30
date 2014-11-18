#include <iostream>
#include <cstring>

using namespace std;

void strreverse(char *s);

int main() {
    char str[] = "Hello";
    strreverse(str);
    cout << str;
}

void strreverse(char *s) {
    string tS = "";
    int sMax = 0;
    while(s[sMax] != '\0') {
        tS += s[sMax];
        sMax++;
    }
    for(int i = 0; i < tS.size(); i++) {
        s[i] = tS[(tS.size()-1) - i];
    }
}
