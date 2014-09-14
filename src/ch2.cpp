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

int ch2ex2()
{
    cout << "Kapitel 2, övning 2" << endl;
    cout << "-------------------" << endl << endl;
    cout << "Ange nuvarande mätarställning (mil): ";
    int current;
    cin >> current;
    cout << "Ange mätarställning för ett år sedan (mil): ";
    int last_year;
    cin >> last_year;
    cout << "Ange förbrukad bensin (liter): ";
    float gas_consumed;
    cin >> gas_consumed;
    cout << "Antal körda mil:     " << current - last_year << endl;
    cout << "Antal liter bensin:  " << gas_consumed << endl;
    cout << "Förbrukning per mil: " << gas_consumed / (current - last_year) << endl;

    return 0;
}

int ch2ex3(int current_year, int car_year)
{
    cout << "Kapitel 2, övning 3" << endl;
    cout << "-------------------" << endl;
    int car_age = current_year - car_year;
    if(car_age < 5)
        cout << "Välj en helförsäkring." << endl;
    else if(car_age >= 5 && car_age < 25)
        cout << "Välj en halvförsäkring." << endl;
    else
        cout << "Välj en veteranbilsförsäkring." << endl;

}

int ch2ex4(double miles_per_gallon)
{
    cout << "Kapitel 2, övning 4" << endl;
    cout << "-------------------" << endl;
    double kilometers_per_gallon = miles_per_gallon * 1.609;
    double kilometers_per_liter = kilometers_per_gallon / 3.785;
    double liters_per_kilometer = 1 / kilometers_per_liter;
    cout << miles_per_gallon << " miles per gallon equals " << liters_per_kilometer << " liters per kilometer." << endl;

    return 0;
}
