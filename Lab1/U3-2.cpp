#include <iostream>

using namespace std;

int main() {
    int judges;
    cout << "Judges: ";
    cin >> judges;
    if(judges < 3) {
        cout << "Not enough judges.";
        return 0;
    }
    int scores[judges];
    cout << "Enter scores :" << endl;
    for(int i = 0; i < judges; i++) {
        cin >> scores[i];
    }
    int max = 0;
    int min = 0;
    int total = 0;
    for(int i = 0; i < judges; i++) {
        if(scores[i] < scores[min]) {
            min = i;
        }
        if(scores[i] > scores[max]) {
            max = i;
        }
        total += scores[i];
    }
    total = total - (scores[min] + scores[max]);
    cout << total/(judges - 2);
    return 0;
}
