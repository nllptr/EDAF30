#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "vektor.h"

using namespace std;

int main()
{
    try {
        //Trying to call vector with argument < 0.
        Vektor v(-1);
    } catch (invalid_argument& e) {
        cout << "Ogiltigt argument: " << typeid(e).name() << ": " << e.what() << endl;
    }

    return 0;
}
