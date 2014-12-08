#include <iostream>

#include "stack.h"

using namespace std;

int main()
{
    Stack stack(5);
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(7);
    stack.push(9);

    cout << (stack.full() ? "Full" : "Not full") << endl;

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    cout << (stack.full() ? "Full" : "Not full") << endl;
    cout << (stack.empty() ? "Empty" : "Not empty") << endl;

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    cout << (stack.empty() ? "Empty" : "Not empty") << endl;

    stack.push(11);

    cout << (stack.empty() ? "Empty" : "Not empty") << endl;

    stack.clear();

    cout << (stack.empty() ? "Empty" : "Not empty") << endl;

    return 0;
}
