#include <iostream>

using namespace std;

int read_int ();

int main () {
    int win = 0;
    cout << "Enter the winning number: ";
    win = read_int();
    cout << "Got " << win << endl;
    //TODO

    return 0;
}

int read_int () {
    int read = 0, tmp = 0;

    while (read == 0) {
        cin >> tmp;
        if (tmp >= 100000 && tmp <= 999999)
            read = tmp;
    }

    return read;
}
