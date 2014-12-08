#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
    Queue(int max = 100);
    ~Queue();
    void clear();
    bool empty() const;
    bool full() const;
    int dequeue();
    void enqueue(int value);
    int length();
private:
    int maxSize;
    int currentSize;
    int *data;
    int head;
    int tail;
};

#endif // QUEUE_H
