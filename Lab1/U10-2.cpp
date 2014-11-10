#include <iostream>
#include <string>

using namespace std;

int main() {
    string roman;
    cout << "Skriv in romerskt tal: ";
    cin >> roman;
    int decimal[roman.length()];
    int total = 0;

    for(int i = 0; i < roman.length(); i++) {
        switch(roman[i]) {
        case 'I': decimal[i] = 1; break;
        case 'V': decimal[i] = 5; break;
        case 'X': decimal[i] = 10; break;
        case 'L': decimal[i] = 50; break;
        case 'C': decimal[i] = 100; break;
        case 'D': decimal[i] = 500; break;
        case 'M': decimal[i] = 1000; break;
        default: cout << roman[i] << " is not a valid number." << endl; return 1;
        }
    }

    for(int i = 0; i < roman.length(); i++) {
        if(i < roman.length()) {
            if(decimal[i] == decimal[i+1]/2) {
                cout << "Invalid format. " << roman[i] << " cannot preceed " << roman[i+1] << endl;
                return 1;
            } else if (i < roman.length() - 1 && decimal[i] < decimal[i+2]) {
                cout << "The sequence " << roman[i] << roman[i+1] << roman[i+2] << " is not allowed." << endl;
                return 1;
            }
        }
    }

    if(roman.length() > 1) {
        for(int i = 0; i < roman.length(); i++) {
            if(decimal[i] > decimal[i+1] && i+1< roman.length()) {
                total += decimal[i];
            } else if (decimal[i] < decimal[i+1] && i+1 < roman.length()){
                total -= decimal[i];
            } else {
                total += decimal[i];
            }
        }
    } else {
        total = decimal[0];
    }
    cout << roman << " = " << total;
}
