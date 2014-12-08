#include "queue.h"

#include <stdexcept>

using namespace std;

Queue::Queue(int max)
{
    maxSize = max;
    data = new int[maxSize];
    head = 0;
    tail = 0;
    num = 0;
}

Queue::~Queue()
{
    delete[] data;
}

void Queue::clear()
{
    delete[] data;
    head = 0;
    tail = 0;
    num = 0;
    data = new int[maxSize];
}

bool Queue::empty() const
{
    return ((num == 0) ? true : false);
}

bool Queue::full() const
{
    return ((num == maxSize) ? true : false);
}

int Queue::dequeue()
{
    if(num == 0) throw length_error("Queue is empty.");
    int temp = data[head];
    head = (++head) % maxSize;
    num--;
    return temp;
}

void Queue::enqueue(int value)
{
    if(num == maxSize) throw length_error("Queue is full.");
    data[tail] = value;
    tail = (++tail) % maxSize;
    num++;
}
