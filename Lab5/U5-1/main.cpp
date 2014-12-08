#include <iostream>

#include "stack.h"

using namespace std;

int main()
{
    Stack stack(3);
    //stack.pop();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    //stack.push(4);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}

