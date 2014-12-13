#include <iostream>

using namespace std;

union Stuff {
    unsigned int four_bytes;
    unsigned short int two_bytes[2];
    unsigned char one_byte[4];
};

int main()
{
    cout << "Stuff is " << sizeof(Stuff) << " bytes." << endl;
    Stuff stuff;
    stuff.four_bytes = 3210987654;

    // Prints four-byte int
    cout << "As int:       " << hex << stuff.four_bytes << endl;

    // Prints two two-byte short ints
    cout << "As short int: ";
    for(int i = 0; i < 2; i++) {
        cout << hex << (int) stuff.two_bytes[i] << " ";
    }
    cout << endl;

    // Prints four one-byte chars
    cout << "As char:      ";
    for(int i = 0; i < 4; i++) {
        cout << hex << (int) stuff.one_byte[i] << " ";
    }
    cout << endl;

    return 0;
}

