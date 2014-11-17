#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void randMat();

int main() {
    randMat();
}

void randMat() {
    srand(time(NULL));
    vector<int> vec (16);
    int matrix [4][4];
    int pop;
    for(int i = 0; i < 16; i++) {
        vec[i] = i;
    }
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            pop = rand() % vec.size();
            matrix[a][b] = vec[pop];
            vec.erase(vec.begin()+pop, vec.begin()+pop+1);
        }
    }
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            cout << setw(3) << matrix[a][b];
        }
        cout << endl;
    }
}
