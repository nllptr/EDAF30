#include <iostream>

using namespace std;

char * mystrcat(char *s, const char *t);

int main()
{
    char str1[] = "", str2[] = "Hello", str3[] = " world!", str4[] = " This is awesome!";
    cout << mystrcat(str1, str2) << endl;
    cout << mystrcat(str1, str3) << endl;
    cout << mystrcat(str1, str4) << endl;

    return 0;
}

char * mystrcat(char *s, const char *t) {
    int sMax = 0;
    while(s[sMax] != '\0') sMax++;

    while(s[sMax++] = *t++);
    return s;
}
