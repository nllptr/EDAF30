#include "stack.h"

#include <stdexcept>

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

bool Stack::empty()
{
    return (num == 0 ? true : false);
}

bool Stack::full()
{
    return (num == maxSize ? true : false);
}

int Stack::pop()
{
    if(num == 0) throw (length_error);
    return data[num--];
}

void Stack::push(int value)
{
    if(num == maxSize) throw (length_error);
    data[num++] = value;
}
