#include <iostream>

using namespace std;

void D1();
void D2();
void D3();

int main()
{
    D3();
    return 0;
}

void D1() {
    cout << "Enter number of decimeters: " << endl;
    int dm;
    cin >> dm;
    int mm = dm * 100;
    int inches = double(mm / 25.4);
    int foot = inches / 12;
    inches = inches % 12;
    cout << dm << " dm roughly equals " << foot << " feet and " << inches << " inches." << endl;
}

void D2() {
    cout << "Enter two integers (a and b): " << endl;
    int a, b;
    cin >> a >> b;
    cout << (a % b == 0 ? "b divides a" : "b does not divide a") << endl;
}

void D3() {
    double value = 10000;
    int day = 0;
    while(value < 1000000) {
        double earnings = value * 0.025;
        double courtage = ((earnings * 0.001) < 100) ? 100 : earnings * 0.001;
        value += (earnings - courtage);
        day++;
    }
    cout << "Sara will be a millionaire in " << day << " days." << endl;
}
