#include <cstring>
#include <iomanip>
#include <iostream>

#define MAX_NUMBERS 100

using namespace std;

bool get_number(char * s);
void check_winnings(char * w, char * s);

int main () {

    cout << "Enter the winning number." << endl;
    char win[7];
    while(!get_number(win));

    cout << "Enter numbers to check. End input with CTRL-D." << endl;
    int i = 0;
    char numbers[MAX_NUMBERS][7];
    while(!cin.eof()) {
        if(get_number(numbers[i]))
            i++;
    }

    cout << endl << "Checking winnings..." << endl;
    for(int j = 0; j <= i; j++)
        check_winnings(win, numbers[j]);

//    for(int j = 0; j <= i; j++) {
//        cout << numbers[j] << endl;
//    }
}

// Gets input from the user and stores it in
// the supplied char array if it's considered
// a valid Joker number.
bool get_number(char * s) {
    cin >> setw(7) >> s;
    s[6] = '\0';
    bool returnval = true;
    for(int i = 0; i < 6; i++) {
        if(s[i] - '0' < 0 || s[i] - '0' > 9) {
            returnval = false;
        }
    }
    return returnval;
}

void check_winnings(char * w, char * s) {
    if(strcmp(w, s) == 0) {
        cout << "==============================" << endl;
        cout << s << " is a winner!" << endl;
        cout << "==============================" << endl;
    }
}
