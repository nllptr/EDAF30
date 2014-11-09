#include <iostream>
#include <string>

using namespace std;

int main() {
    string roman;
    cout << "Skriv in romerskt tal: ";
    cin >> roman;
    int decimal[roman.length()];
    int total;

    for(int i = 0; i < roman.length(); i++) {
        switch(roman[i]) {
        case 'I': decimal[i] = 1; break;
        case 'V': decimal[i] = 5; break;
        case 'X': decimal[i] = 10; break;
        case 'L': decimal[i] = 50; break;
        case 'C': decimal[i] = 100; break;
        case 'D': decimal[i] = 500; break;
        case 'M': decimal[i] = 1000; break;
        default: decimal[i] = 0; break;
        }
    }
    for(int i = 0; i < roman.length(); i++) {
        cout << decimal[i] << endl;
    }

    for(int i = 0; i < roman.length(); i++) {

    }


}
