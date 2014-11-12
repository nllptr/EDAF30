#include <iostream>

using namespace std;

bool delbar(int a, int b);

int main()
{
    cout << delbar(10, 2) << endl;
    cout << delbar(9, 5) << endl;
    return 0;
}

bool delbar(int a, int b) {
    return a % b == 0 ? true : false;
}

