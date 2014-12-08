#include "stack.h"

#include <stdexcept>

using namespace std;

Stack::Stack(int max)
{
    maxSize = max;
    data = new int[maxSize];
    num = 0;
}

Stack::~Stack()
{
    delete[] data;
}

void Stack::clear()
{
    delete[] data;
    data = new int[maxSize];
}

bool Stack::empty() const
{
    return (num == 0 ? true : false);
}

bool Stack::full() const
{
    return (num == maxSize ? true : false);
}

int Stack::pop()
{
    if(num == 0) throw length_error("Stack is empty.");
    return data[--num];
}

void Stack::push(int value)
{
    if(num == maxSize) throw length_error("Stack is full.");
    data[num++] = value;
}
