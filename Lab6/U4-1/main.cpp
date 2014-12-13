#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "stack.h"

int main()
{
    std::srand(time(NULL));
    Stack<int> s1(10);

    while (s1.full() == false) {
        int r = rand() % 100;
        std::cout << "Pushing " << std::setw(2) << r << " onto the stack." << std::endl;
        s1.push(r);
    }

    std::cout << std::endl << "Stack is full" << std::endl << std::endl;

    while(s1.empty() == false)
        std::cout << "Popping " << std::setw(2) << s1.pop() << " from the stack." << std::endl;

    std::cout << std::endl << "--------------------------" << std::endl << std::endl;

    Stack<double> s2(3);

    double p = 3.14;
    std::cout << "Pushing " << std::setw(2) << p << " onto the stack." << std::endl;
    s2.push(p);
    p = 6.28;
    std::cout << "Pushing " << std::setw(2) << p << " onto the stack." << std::endl;
    s2.push(p);
    p = 9.42;
    std::cout << "Pushing " << std::setw(2) << p << " onto the stack." << std::endl;
    s2.push(p);

    std::cout << std::endl << "Stack is full" << std::endl << std::endl;

    while(s2.empty() == false)
        std::cout << "Popping " << std::setw(2) << s2.pop() << " from the stack." << std::endl;

    return 0;
}

