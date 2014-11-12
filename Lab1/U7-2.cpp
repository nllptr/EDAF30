#include <iostream>
#include <string>

using namespace std;

int main() {
    string regnum;
    cout << "Skriv registreringsnummer: ";
    cin >> regnum;
    if(regnum.length() != 6) {
        cout << "Ogiltligt registreringsnummer (längd): " << regnum.length();
        return 1;
    }
    for(int i = 0; i < 3; i++) {
        if(regnum[i] - 'A' < 0 || regnum[i] - 'A' > 25) {
            cout << "Ogiltligt registreringsnummer (tecken): " << regnum[i];
            return 1;
        }
        if(regnum[i+3] - '0' < 0 || regnum[i+3] - '0' > 9) {
            cout << "Ogiltligt registreringsnummer (tecken): " << regnum[i+3];
            return 1;
        }
    }
    cout << "OK";
}
