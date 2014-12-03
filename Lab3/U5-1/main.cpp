#include <iostream>

#include "kvadrat.h"

using namespace std;

int main()
{
    Kvadrat k1, k2(5);

    // Testing unary operators
    cout << "Area of k1 is " << k1.area() << endl;
    ++k1;
    cout << "After incrementing, area of k1 is " << k1.area() << endl;
    cout << "Area of k2 is " << k2.area() << endl;
    --k2;
    cout << "After decrementing, area of k2 is " << k2.area() << endl;

    // Testing binary operators
    cout << "Adding 4 to k1" << endl;
    k1 = k1 + 4;
    cout << "After adding 4 to k1, area is " << k1.area() << endl;
    cout << "Subtracting 2 from k1" << endl;
    k1 = k1 - 2;
    cout << "After subtracting 2 from k1, area is " << k1.area() << endl;
    cout << "Comparing k1 and k2 for equality" << endl;
    cout << (k1 == k2) << endl;
    cout << "Incrementing k1" << endl;
    ++k1;
    cout << "Comparing k1 to k2 using >" << endl;
    cout << (k1 > k2) << endl;
    cout << "Comparing k1 to k2 using <" << endl;
    cout << (k1 < k2) << endl;
    cout << "Comparing for equality again" << endl;
    cout << (k1 == k2) << endl;
    return 0;
}

