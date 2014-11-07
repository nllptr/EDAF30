#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool check_format(string);
int check_winner(string, string);

int main() {
    string win;
    string myNumber;
    cout << "Enter winning number: ";
    cin >> win;
    if(!check_format(win)) {
        cout << "Wrong format on winning number.";
        return 0;
    }
    cout << "Enter you number: ";
    cin >> myNumber;
    if(!check_format(myNumber)) {
        cout << "Wrong format on your number.";
        return 0;
    }
    cout << "You won " << check_winner(myNumber, win) << " SEK.";

    return 0;
}

bool check_format(string num) {
    bool numOK = false;
    if(num.length() == 6){
        numOK = true;
    }
    for(int i = 0; i < 6; i++) {
        if(num[i] - '0' < 0 || num[i] - '0' > 9) {
            numOK = false;
        }
    }
    return numOK;
}

int check_winner(string mNum, string wNum) {
    int prize = 0;
    string first = "";
    for(int i = 3; i < 6; i++) {
        first += mNum[i];
    }
    if(wNum.find(first) != -1) {
        prize = 250;
    }
    if(mNum == wNum) {
        prize = 1000000;
    }
    for(int i = 5; i >= 0; i--) {
        if(mNum[i] == wNum[i]) {
            prize = pow(10, 6 - i);
        }
        else {
            break;
        }
    }
    return prize;
}
