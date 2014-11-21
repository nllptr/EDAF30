#include <iostream>

using namespace std;

void strreverse(char *s);

int main()
{
    char str[] = "Hello! Just testing some stuff.";
    strreverse(str);
    cout << str << endl;
    return 0;
}

void strreverse(char *s) {
    int sMax = 0;
    while(s[sMax] != '\0') sMax++;
    char tmp[sMax];
    for(int i = 0; i < sMax; i++) {
        tmp[i] = s[sMax - i - 1];
    }
    for(int i = 0; (s[i] = tmp[i]) != '\0'; i++);
    s = tmp;
}
