#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Type some stuff: " << endl;
    string stuff;
    getline(cin, stuff);
    for(int i = stuff.length(); i > 0; i--) {
        cout << stuff.back();
        stuff.pop_back();
    }
    cout << endl;
    return 0;
}
