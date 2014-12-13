#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <class T>
class Queue {
private:
    int maxSize; // Köns maximala storlek
    T *data; // Data
    int head; // index till nästa pos att läsa från
    int tail; // index till nästa pos att skriva till
    int currentSize;
public:
    Queue(int max=100) {
        maxSize = max;
        head = tail = currentSize = 0;
        data = new T[maxSize];
    }
    ~Queue() { delete[] data; }
    void clear() { delete[] data; data = new T[maxSize]; }
    bool empty() const { return currentSize == 0 ? true : false; }
    bool full() const { return currentSize == maxSize ? true : false; }
    T dequeue() {
        if(empty()) throw std::length_error("Queue is empty.");
        T value = data[head];
        head++;
        head = head % maxSize;
        currentSize--;
        return value;
    }
    void enqueue(T value) {
        if(full()) throw std::length_error("Queue is full.");
        data[tail] = value;
        tail++;
        tail = tail % maxSize;
        currentSize++;
    }
    int length() { return currentSize; }
};

#endif // QUEUE_H
