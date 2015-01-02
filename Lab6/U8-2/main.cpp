#include <iostream>

using namespace std;

union Temp {
    unsigned int four;
    unsigned short int two[2];
    unsigned char one[4];
};

int main()
{
    cout << "Size of Temp: " << sizeof(Temp) << endl;
    Temp temp;
    temp.four = 3338778661;

    cout << "four: " << hex << temp.four << endl;

    cout << "two: " << hex;
    for(int i = 0; i < 2; i++) {
        cout << (int) temp.two[i] << " ";
    }
    cout << endl;

    cout << "one: " << hex;
    for(int i = 0; i < 4; i++) {
        cout << (int) temp.one[i] << " ";
    }

    cout << endl;
    return 0;
}
