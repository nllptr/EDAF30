#include "queue.h"

#include <stdexcept>

using namespace std;

Queue::Queue(int max)
{
    maxSize = max;
    currentSize = 0;
    data = new int[maxSize];
    head = tail = 0;
}

Queue::~Queue()
{
    delete[] data;
}

void Queue::clear()
{
    delete[] data;
    data = new int[maxSize];
}

bool Queue::empty() const
{
    return (currentSize == 0) ? true : false;
}

bool Queue::full() const
{
    return (currentSize == maxSize) ? true : false;
}

int Queue::dequeue()
{
    if(currentSize == 0) throw length_error("Queue is empty.");
    head = (++head) % maxSize;
    currentSize--;
    return data[head];
}

void Queue::enqueue(int value)
{
    if(currentSize == maxSize) throw length_error("Queue is full.");
    tail = (++tail) % maxSize;
    data[tail] = value;
    currentSize++;
}

int Queue::length()
{
    return currentSize;
}
