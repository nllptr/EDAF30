#include <iostream>
#include <climits>

#define MAX_SCORES 50

using namespace std;

int main() {
    cout << "Enter scores. End input with CTRL-D." << endl;
    int min, max, i = 0;
    min = INT_MAX;
    max = INT_MIN;
    int scores[MAX_SCORES];
    cin >> scores[i];
    while(!cin.eof()) {
        if(min == INT_MAX) min = scores[i];
        else if(scores[i] < min) min = scores[i];

        if(max == INT_MIN) max = scores[i];
        else if(scores[i] > max) max = scores[i];

        //cout << "Added " << scores[i] << " to scores[" << i << "]." << endl;
        i++;
        cin >> scores[i];
    }

    //cout << "Max is " << max << endl;
    //cout << "Min is " << min << endl;

    if(i >= 3) {
        double total = 0;
        for(int j = 0; j < i; j++) {
            total += scores[j];
        }
        total = total - max - min;
        double average = total / (i - 2);
        //cout << total << " / (" << i << " - 2)" << endl;

        cout << "Average score is: " << average << endl;
    } else {
        cout << "Too few scores, impossible to calculate average." << endl;
        //cout << "i was " << i << endl;
    }

    return 0;
}
