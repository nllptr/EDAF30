#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "../U5-1/queue.h"

using namespace std;

struct Kund {
    char namn[35];
    double belopp;
};

void queue(Queue<Kund> *q);

int main()
{
    int servedCustomers = 0;
    double total = 0;
    Queue<Kund> q;

    while(true) {
        cout << "---------------------------------------------------" << endl;
        cout << "Betjänade kunder:" << setw(4) << servedCustomers << "   Total försäljning:" << setw(9) << total << endl;
        cout << "1. Köa ny kund." << endl << "2. Betjäna kund." << endl << "3. Avsluta." << endl << "Val (1-3): ";
        int choice;
        cin >> choice;

        switch(choice) {
        case 1:
            queue(&q);
            break;
        case 2:
            try {
                Kund k = q.dequeue();
                servedCustomers++;
                total += k.belopp;
                cout << "Betjänade kund: " << k.namn << endl;
            } catch (length_error) {
                cout << "Kön är tom." << endl;
            }
            break;
        case 3:
            return 0;
        }
    }

    return 0;
}

void queue(Queue<Kund> *q)
{
    Kund k;
    cout << "Ange kundens namn: ";
    cin >> k.namn;
    cout << "Ange kundens betalningsbelopp: ";
    cin >> k.belopp;
    try {
        q->enqueue(k);
    } catch (length_error) {
        cout << "Kön är full. Kunden lades inte till." << endl;
    }
}
