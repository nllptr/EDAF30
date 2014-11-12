#include <iostream>
#include <vector>

using namespace std;

vector<int> jaja(vector<int>&);

int main() {
    vector<int> heltal(4, 8);
    jaja(heltal);
    cout << heltal[3] << endl;

    return 0;
}

vector<int> jaja(vector<int>& heltal) {
    for(int i = 0; i < heltal.size(); i++) {
        heltal[i] += 1;
    }
    return heltal;
}
