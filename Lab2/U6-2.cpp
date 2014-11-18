#include <iostream>
#include <vector>

using namespace std;

void jaja(vector<int> &heltal);

int main() {
    vector<int> heltal(4, 8);
    jaja(heltal);
    cout << heltal[3] << endl;

    return 0;
}

void jaja(vector<int> &heltal) {
    for(int i = 0; i < heltal.size(); i++) {
        heltal[i] += 1;
    }
}
