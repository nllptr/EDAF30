#include <iostream>

using namespace std;

void capitalize(string& str);
void encrypt(string& str);

int main() {
    cout << "Enter string to encrypt." << endl;
    string str;
    getline(cin, str);
    if(str.length() > 80) {
        cout << "80 charaters maximum." << endl;
        return 1;
    }
    capitalize(str);
    encrypt(str);
    cout << str << endl;
    return 0;
}

void capitalize(string& str) {
    for(int i = 0; i < str.length(); i++)
        if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
}

void encrypt(string &str) {
    for(int i = 0; i < str.length(); i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
}
