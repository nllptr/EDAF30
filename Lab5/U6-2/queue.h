#include <stdexcept>

class Queue {
private:
    int maxSize; // Köns maximala storlek
    int *data; // Data
    int head; // index till nästa pos att läsa från
    int tail; // index till nästa pos att skriva till
    int num;
public:
    Queue(int max=100);
    ~Queue();
    void clear();
    bool empty() const;
    bool full() const;
    int dequeue(); //Hämta+avlägsna elem, throw (length_error)
    void enqueue(int value); // throw (length_error)
    int length();
};
