#include <iostream>

using namespace std;

void mystrcat(char *s, const char *t);

int main() {
    char str1[]  = "Hello", str2[] = " world";
    mystrcat(str1, str2);
    cout << str1;
    return 0;
}

void mystrcat(char *s, const char *t) {
    int sMax = 0; int tMax = 0;
    while(s[sMax] != '\0') {
        sMax++;
    }
    while(t[tMax] != '\0') {
        tMax++;
    }
    for(int i = 0; i < tMax; i++) {
        s[sMax + i] = t[i];
    }
}

