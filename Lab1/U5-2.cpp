#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    string comp;
    string user;
    int number;
    cout << "STEN, SAX eller PÅSE: ";
    cin >> user;

    srand (time(NULL));
    number = rand() % 3 + 1;

    switch(number) {
    case 1: comp = "STEN"; break;
    case 2: comp = "SAX"; break;
    case 3: comp = "PÅSE"; break;
    default: comp = ""; break;
    }

    if(user.compare(comp) == 0) {
        cout << "Båda valde " << user << ". Ingen vann.";
    } else if((user.compare("STEN") == 0 && comp.compare("SAX") == 0) || (user.compare("SAX") == 0 && comp.compare("PÅSE") == 0) || (user.compare("PÅSE") == 0 && comp.compare("STEN") == 0)) {
        cout << "Grattis, du vann med " << user << " mot " << comp;
    } else {
        cout << "Tyvärr, du förlorade med " << user << " mot " << comp;
    }
}
