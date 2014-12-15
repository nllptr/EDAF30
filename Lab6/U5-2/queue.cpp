#include "queue.h"

#include <stdexcept>

using namespace std;

template <class T>
Queue<T>::Queue(int max)
{
    maxSize = max;
    data = new T[maxSize];
    head = 0;
    tail = 0;
    num = 0;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] data;
}

template <class T>
void Queue<T>::clear()
{
    delete[] data;
    head = 0;
    tail = 0;
    num = 0;
    data = new T[maxSize];
}

template <class T>
bool Queue<T>::empty() const
{
    return ((num == 0) ? true : false);
}

template <class T>
bool Queue<T>::full() const
{
    return ((num == maxSize) ? true : false);
}

template <class T>
T Queue<T>::dequeue()
{
    if(num == 0) throw length_error("Queue is empty.");
    T temp = data[head];
    head = (++head) % maxSize;
    num--;
    return temp;
}

template <class T>
void Queue<T>::enqueue(T value)
{
    if(num == maxSize) throw length_error("Queue is full.");
    data[tail] = value;
    tail = (++tail) % maxSize;
    num++;
}
