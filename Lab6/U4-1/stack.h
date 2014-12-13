#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <class T>
class Stack {
private:
    int maxSize;
    T *data;
    int num;
public:
    Stack(int max=100) : maxSize(max), num(0) { data = new T[maxSize]; }
    ~Stack() { delete[] data; }
    void clear() { delete[] data; data = new T[maxSize]; }
    bool empty() const { return (num == 0 ? true : false); }
    bool full() const { return (num == maxSize ? true : false); }
    T pop() {
        if(num == 0) throw std::length_error("Stack is empty");
        return data[--num];
    }
    void push(T value) {
        if(num == maxSize) throw std::length_error("Stack is full");
        data[num++] = value;
    }
};

#endif // STACK_H
