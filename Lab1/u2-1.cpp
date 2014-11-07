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
    for(int j = 0; j < i; j++)
        check_winnings(win, numbers[j]);

//    for(int j = 0; j <= i; j++) {
//        cout << numbers[j] << endl;
//    }

    return 0;
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

// Compares the winning string (w) against
// another string (s) to determine the winnings.
void check_winnings(char * w, char * s) {

    // Check for winnings according to rule 1
    long winnings = 1;
    for(int i = 5; i >= 0; i--) {
        if(w[i] == s[i])
            winnings *= 10;
        else
            break;
    }
    if(winnings == 1)
        winnings = 0;

    // Check for winnings according to rule 2
    char first_three[4];
    for(int i = 0; i < 3; i++)
        first_three[i] = s[i + 3];
    first_three[3] = '\0';
    for(int i = 0; i < 3; i++) {
        bool flag = true;
        for(int j = 0; j < 3; j++) {
            if(w[i + j] != first_three[j]) flag = false;
            else if(flag == true && j == 2) winnings += 250;
        }
//        cout << "Checked first permutation. Winnings are " << winnings << endl;
    }


    if(winnings > 0) {
        cout << "==============================" << endl;
        cout << s << " won " << winnings << "!" << endl;
        cout << "==============================" << endl;
    }
}
