#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    Stack(int max = 100);
    ~Stack();
    void clear();
    bool empty() const;
    bool full() const;
    int pop();
    void push(int value);
private:
    int maxSize;
    int *data;
    int num;
};

#endif // STACK_H
