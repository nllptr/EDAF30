#include <iostream>
#include "../U5-2/queue.h"
#include "kund.h"

using namespace std;

string getRandName();
int main()
{
    int opt;
    int customers = 0;
    int total = 0;
    string name;
    int money;
    srand(time(0));
    Queue<Kund> q(20);
    cout << "Welcome!" << endl;
    while(true) {
    cout << endl << "1: enqueue new customer\n2: dequeue customer\n3: close for the day" << endl;
    cin >> opt;
        if(opt == 1) {
            name = getRandName();
            money = rand()%1000 + 1;
            Kund k = {name, money};
            q.enqueue(k);
            cout << endl <<"Enqueued " << name << " with " << money;
        } else if(opt == 2) {
            Kund temp = q.dequeue();
            customers++;
            total += temp.belopp;
            cout << endl << "Dequeued " << temp.namn << " with " << temp.belopp;
        } else if(opt == 3) {
            cout << endl << "customers: " << customers << endl << "cash: " << total;
            return 1;
        }
    }
    return 0;
}

string getRandName() {
    string names[10] = {"Jean-Luc Picard", "William Riker", "Beverly Crusher", "Deanna Troi",
                  "Geordi La Forge", "Data", "Worf", "Wesley Crusher", "Guinan", "Tasha Yar"};
    srand(time(0));
    return names[rand()%10];
}
