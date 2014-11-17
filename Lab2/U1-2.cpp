#include <iostream>

using namespace std;

bool delbar(int, int);

int main() {
    int a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    cout << delbar(a, b);
    return 0;
}

bool delbar(int a, int b) {
    if(a%b == 0) {
        return true;
    } else {
        return false;
    }

}
