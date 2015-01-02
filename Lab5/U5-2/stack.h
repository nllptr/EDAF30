#include <stdexcept>

class Stack {
private:
    int maxSize; // Stackens maximala storlek
    int *data; // Data
    int num; // Antalet element i stacken
public:
    Stack(int max=100);
    ~Stack();
    void clear();
    bool empty() const;
    bool full() const ;
    int pop(); // Hämta+avlägsna element, throw (length_error)
    void push(int value);
};
