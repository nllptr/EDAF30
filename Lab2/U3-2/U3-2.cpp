#include <iostream>

using namespace std;

int randInt(int min, int max);

int main() {
    cout << randInt(3, 7) << endl;
}

int randInt(int min, int max) {
    srand(time(NULL));
    return rand() % (max-min+1) + min;
}
