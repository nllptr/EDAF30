#include <iostream>
#include <climits>
#include <fstream>
#include <string>

#define MAX_SCORES 50

using namespace std;

int main() {
    cout << "Enter input file name: ";
    string filename_in;
    cin >> filename_in;
    ifstream infile(filename_in);
    if(!infile) {
        cout << "The input file could not be opened." << endl;
        return 1;
    }
    cout << "Enter output file name: ";
    string filename_out;
    cin >> filename_out;
    ofstream outfile(filename_out);
    if(!outfile) {
        cout << "The output file could not be opened or created." << endl;
        return 1;
    }
    int min, max, i = 0;
    min = INT_MAX;
    max = INT_MIN;
    int scores[MAX_SCORES];
    infile >> scores[i];
    while(!infile.eof()) {
        if(min == INT_MAX) min = scores[i];
        else if(scores[i] < min) min = scores[i];

        if(max == INT_MIN) max = scores[i];
        else if(scores[i] > max) max = scores[i];

        //cout << "Added " << scores[i] << " to scores[" << i << "]." << endl;
        i++;
        infile >> scores[i];
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

        outfile << "Average score is: " << average << endl;
    } else {
        cout << "Too few scores, impossible to calculate average." << endl;
        //cout << "i was " << i << endl;
    }

    return 0;
}
