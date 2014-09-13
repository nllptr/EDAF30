#include <iostream>
#include "../include/ch2.hpp"

using namespace std;

int ch2ex1()
{
    cout << "Kapitel 2, övning 1" << endl;
    cout << "-------------------" << endl << endl;
    cout << "Ange nuvarande mätarställning (mil): ";
    int current;
    cin >> current;
    cout << "Ange mätarställning för ett år sedan (mil): ";
    int last_year;
    cin >> last_year;
    cout << "Bilen har gått " << current - last_year << " mil det senaste året." << endl;

    return 0;
}
