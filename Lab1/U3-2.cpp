#include <iostream>
#include <climits>

using namespace std;

int main() {
    int judges;
    cout << "Judges: ";
    cin >> judges;
    if(judges < 3) {
        cout << "Not enough judges.";
        return 0;
    }
    double scores[judges];
    cout << "Enter scores :" << endl;
    for(int i = 0; i < judges; i++) {
        cin >> scores[i];
    }
    int max = INT_MIN;
    int min = INT_MAX;
    int total = 0;
    for(int i = 0; i < judges; i++) {
        if(scores[i] < min) {
            min = scores[i];
        }
        if(scores[i] > max) {
            max = scores[i];
        }
        total += scores[i];
    }
    total = total - (max + min);
    double mean = (double)total/(judges - 2);
    cout << mean;
    return 0;
}
