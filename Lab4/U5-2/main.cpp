#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char file1[80];
    char file2[80];

    cout << "Ange första filens namn: ";
    cin >> file1;
    ifstream f1(file1, ifstream::in|ios::binary);
    if(!f1.is_open()) {
        cout << "Filen " << file1 << " existerar inte." << endl;
        f1.close();
        return 1;
    }

    cout << "Ange andra filens namn: ";
    cin >> file2;
    ifstream f2(file2, ifstream::in|ios::binary);
    if(!f2.is_open()) {
        cout << "Filen " << file2 << " existerar inte." << endl;
        f2.close();
        return 1;
    }

    char a, b;
    bool equal = true;
    while(f1.get(a) && f2.get(b)) {
        if(a != b) equal = false;
    }

    f1.close();
    f2.close();

    cout << (equal ? "Filerna är lika" : "Filerna är inte lika") << endl;

    return 0;
}
