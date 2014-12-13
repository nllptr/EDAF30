#include <iostream>
#include <cstdlib>

#include "queue.h"

using namespace std;

int main()
{
    std::srand(time(NULL));
    Queue<int> q(3);
    while(!q.full()) {
        int r = rand() % 100;
        q.enqueue(r);
        cout << "Enqueued " << r << endl;
    }

    cout << "Queue is full." << endl;

    cout << "Dequeued " << q.dequeue() << endl;
    cout << "Dequeued " << q.dequeue() << endl;

    while(!q.full()) {
        int r = rand() % 100;
        q.enqueue(r);
        cout << "Enqueued " << r << endl;
    }

    while(!q.empty()) {
        cout << "Dequeued " << q.dequeue() << endl;
    }

    cout << "Queue is empty." << endl;

    return 0;
}

