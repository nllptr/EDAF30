#include <iostream>

#include "queue.h"

using namespace std;

int main()
{
    Queue<int> q1(2);
    cout << "Created queue with size 2." << endl;
    cout << "Empty: " << (q1.empty() ? "Yes" : "No") << "    Full: " << (q1.full() ? "Yes" : "No") << endl;
    q1.enqueue(9);
    cout << "Added 9 to queue." << endl;
    cout << "Empty: " << (q1.empty() ? "Yes" : "No") << "    Full: " << (q1.full() ? "Yes" : "No") << endl;
    cout << "Dequeueing: " << q1.dequeue() << endl;
    cout << "Empty: " << (q1.empty() ? "Yes" : "No") << "    Full: " << (q1.full() ? "Yes" : "No") << endl;
    cout << "Adding first 8 and then 7" << endl;
    q1.enqueue(8);
    q1.enqueue(7);
    cout << "Empty: " << (q1.empty() ? "Yes" : "No") << "    Full: " << (q1.full() ? "Yes" : "No") << endl;
    cout << "Dequeueing: " << q1.dequeue() << endl;
    cout << "Dequeueing: " << q1.dequeue() << endl;
    cout << "Empty: " << (q1.empty() ? "Yes" : "No") << "    Full: " << (q1.full() ? "Yes" : "No") << endl;
    cout << endl << endl;
    Queue<string> q2(3);
    cout << "Created queue with size 3." << endl;
    cout << "Empty: " << (q2.empty() ? "Yes" : "No") << "    Full: " << (q2.full() ? "Yes" : "No") << endl;
    q2.enqueue("first");
    cout << "Added 'first' to queue." << endl;
    cout << "Empty: " << (q2.empty() ? "Yes" : "No") << "    Full: " << (q2.full() ? "Yes" : "No") << endl;
    q2.enqueue("second");
    q2.enqueue("third");
    cout << "Empty: " << (q2.empty() ? "Yes" : "No") << "    Full: " << (q2.full() ? "Yes" : "No") << endl;
    cout << "Dequeueing: " << q2.dequeue() << endl;
    cout << "Dequeueing: " << q2.dequeue() << endl;
    cout << "Dequeueing: " << q2.dequeue() << endl;
    cout << "Empty: " << (q2.empty() ? "Yes" : "No") << "    Full: " << (q2.full() ? "Yes" : "No") << endl;
    return 0;
}
