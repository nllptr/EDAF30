#include <iostream>

#include "queue.h"

using namespace std;

int main()
{
    Queue queue(3);
    cout << queue.empty() << endl;
    queue.enqueue(5);
    cout << queue.empty() << endl;
    cout << queue.full() << endl;
    queue.enqueue(6);
    queue.enqueue(7);
    cout << queue.full() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    queue.enqueue(8);
    cout << queue.dequeue() << endl;
    queue.enqueue(9);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    return 0;
}

