#include <iostream>

#include "queue.h"

using namespace std;

int main()
{
    Queue q(2);
    cout << "Created queue with size 2." << endl;
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << "    Full: " << (q.full() ? "Yes" : "No") << endl;
    q.enqueue(9);
    cout << "Added 9 to queue." << endl;
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << "    Full: " << (q.full() ? "Yes" : "No") << endl;
    cout << "Dequeueing: " << q.dequeue() << endl;
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << "    Full: " << (q.full() ? "Yes" : "No") << endl;
    cout << "Adding first 8 and then 7" << endl;
    q.enqueue(8);
    q.enqueue(7);
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << "    Full: " << (q.full() ? "Yes" : "No") << endl;
    cout << "Dequeueing: " << q.dequeue() << endl;
    cout << "Dequeueing: " << q.dequeue() << endl;
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << "    Full: " << (q.full() ? "Yes" : "No") << endl;
    return 0;
}
