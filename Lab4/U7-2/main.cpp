#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    cout << "Enter file name: ";
    char input[80];
    cin >>  input;

    wifstream infile(input);
    if(!infile.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }

    int categories[6] = {0, 0, 0, 0, 0, 0};
    long total = 0;
    wchar_t c;
    while(infile.get(c)) {
        if(c == 0) {
            categories[0]++;
        } else if(c >= 1 && c <= 31) {
            categories[1]++;
        } else if(c == 32) {
            categories[2]++;
        } else if(c >= 33 && c <= 127) {
            categories[3]++;
        } else if(c >= 128 && c <= 254) {
            categories[4]++;
        } else if(c == 255) {
            categories[5]++;
        }
        total++;
    }

    cout << setw(10) << "Kod" << setw(10) << "%" << endl;
    cout << "------------------------------" << endl;
    for(int i = 0; i < 6; i++) {
        switch(i) {
        case 0:
            cout << setw(10) << "0:";
            break;
        case 1:
            cout << setw(10) << "1-31:";
            break;
        case 2:
            cout << setw(10) << "32:";
            break;
        case 3:
            cout << setw(10) << "33-127:";
            break;
        case 4:
            cout << setw(10) << "128-254:";
            break;
        case 5:
            cout << setw(10) << "255:";
            break;
        }
        cout << setw(10) << setprecision(4) << (categories[i] / (double) total) * 100 << endl;
    }

    return 0;
}
