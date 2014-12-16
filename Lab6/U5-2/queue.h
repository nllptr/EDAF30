#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

using namespace std;

template <class T>
class Queue {
private:
    int maxSize; // Köns maximala storlek
    T *data; // Data
    int head; // index till nästa pos att läsa från
    int tail; // index till nästa pos att skriva till
    int num;
public:
    Queue(int max=100) : maxSize(max), head(0), tail(0), num(0) {
        data = new T[maxSize];
    };
    ~Queue() {
        delete[] data;
    };
    void clear() {
        head = 0;
        tail = 0;
        num = 0;
        delete[] data;
        data = new T[maxSize];
    };
    bool empty() const {
        return ((num == 0) ? true : false);
    };
    bool full() const {
        return ((num == maxSize) ? true : false);
    };
    T dequeue() {
        if(num == 0) throw length_error("Queue is empty.");
        T temp = data[head];
        head = (++head) % maxSize;
        num--;
        return temp;
    }
    void enqueue(T value){
        if(num == maxSize) throw length_error("Queue is full.");
        data[tail] = value;
        tail = (++tail) % maxSize;
        num++;
    };

    int length();
};

#endif
