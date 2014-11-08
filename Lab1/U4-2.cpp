#include <iostream>
#include <fstream>
#include <string>
#include <climits>

using namespace std;

int main() {
    string content;
    cout << "Enter input file name: ";
    string infile;
    cin >> infile;
    ifstream ifile (infile);
    int max = INT_MIN;
    int min = INT_MAX;
    int maxScore = 20;
    int i = 0;
    int scores[20];
    int total = 0;
    ifile >> scores[i];
    while(!ifile.eof()) {
        if(scores[i] < min) {
            min = scores[i];
        }
        if(scores[i] > max) {
            max = scores[i];
        }
        //cout << scores[i] << " and " << i << endl;
        total += scores[i];
        i++;
        ifile >> scores[i];
    }
    total = total - (max + min);
    double mean = (double)total/(i-2);
    cout << "Enter output file name: ";
    string outfile;
    cin >> outfile;
    ofstream ofile (outfile);
    if(i > 2){
        ofile << "Mean: " << mean;
    } else {
        ofile << "Not enough scores.";
    }

    return 0;
}
