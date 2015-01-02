#include <iostream>
#include <cstdlib>
#include <random>
#include <queue>

#include "kund.h"

using namespace std;

int main()
{
    srand(time(NULL));

    cout << "Timmar: ";
    int hours;
    cin >> hours;

    cout << "Kund per timme: ";
    int customersPerHour;
    cin >> customersPerHour;
    if(customersPerHour < 0 || customersPerHour > 60) {
        cout << "Fel." << endl;
        return 1;
    }

    queue<Kund> q;
    bool ATM_available = true;
    int served_customers = 0;
    int current_service_time = 0;
    int sum_customers_per_minute = 0;

    default_random_engine generator;
    poisson_distribution<int> distribution(customersPerHour / 60.0);

    for(int m = 0; m < hours * 60; m++) {

        // Randomize customers for the current minute
        int randCustomers = distribution(generator);
        for(int c = 0; c < randCustomers; c++) {
            Kund kund(m);
            q.push(kund);
        }

        // Start serving new customer if ATM is available
        if(ATM_available && !q.empty()) {
            current_service_time = q.front().betjaning();
            ATM_available = false;
        }

        // If service time reaches 0, remove the customer from the queue
        if(!ATM_available && current_service_time == 0) {
            q.pop();
            ATM_available = true;
            ++served_customers;
        }

        // When serving, if there is still serving needed, decrement service time
        if(!ATM_available && current_service_time > 0) {
            --current_service_time;
        }

        sum_customers_per_minute += (q.size() - 1); // Not counting the customer at the front of the queue.
    }

    cout << "Totalt antal betjänade kunder: " << served_customers << endl;
    cout << "Genomsnittslig kölängd: " << sum_customers_per_minute / (hours * 60.0) << endl;
    return 0;
}
