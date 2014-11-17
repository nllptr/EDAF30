#include <iostream>
#include <cstring>

using namespace std;

void downcase(char *str);

int main()
{
    char str1[] = "HellO THIS is Me!";
    char str2[] = "Och så testar vi med svenska också, ni vet med Å, Ä och Ö. Stora ÄNDRAS, små är kvar.";
    downcase(str1);
    downcase(str2);
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}

// Ask for advice on this one. The function should take a c-style string, but how do I overcome the wider characters used for å ä ö?

void downcase(char *str) {
    for(unsigned int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
        else if(str[i] == 'Å')
            str[i] = 'å';
        else if(str[i] == 'Ä')
            str[i] = 'ä';
        else if(str[i] == 'Ö')
            str[i] = 'ö';
    }
}
