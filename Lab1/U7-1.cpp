#include <iostream>

using namespace std;

int main() {
    cout << "Skriv in ett registreringsnummer: ";
    string num;
    cin >> num;
    bool letters_ok, numbers_ok;
    letters_ok = numbers_ok = true;
    if(num.length() != 6)
        cout << "Exakt 6 tecken krävs." << endl;
    else {
        for(int i = 0; i < 3; i++)
            if(!(num[i] >= 'A' && num[i] <= 'Z') && !(num[i] >= 'a' && num[i] <= 'z')) {
                cout << "Tecken nr " << (i + 1) << " måste vara en bokstav." << endl;
                letters_ok = false;
            }
        for(int i = 3; i < 6; i++)
            if(num[i] < '0' || num[i] > '9') {
                cout << "Tecen nr " << (i + 1) << " måste vara en siffra." << endl;
                numbers_ok = false;
            }
    }
    if(letters_ok && numbers_ok) {
        cout << "Registreringsnumret ser bra ut." << endl;
        return 0;
    }
    else return 1;
}
