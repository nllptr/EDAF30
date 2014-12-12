#include <iostream>

using namespace std;

int mystrcmp(const char *s1, const char *s2);

int main() {
    char a[] = "Berit";
    char b[] = "Bertil";
    char c[] = "Bert";
    cout << mystrcmp(a, b);
    return 0;
}

int mystrcmp(const char *s1, const char *s2) {
    int s1Max = 0, s2Max = 0;
    int big;
    while(s1[s1Max] != '\0') {
        s1Max++;
    }
    while(s2[s2Max] != '\0') {
        s2Max++;
    }
    if(s1Max > s2Max) {
        big = s1Max;
    } else {
        big = s2Max;
    }
    for(int i = 0; i < big; i++) {
        if(s1[i] - s2[i] != 0) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
