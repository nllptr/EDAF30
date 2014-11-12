#include <iostream>
#include <vector>

using namespace std;

void byt(int& a, int& b);

int main() {
    int a[] = {5, 2, 7, 3, 9, 8, 9, 1, 6, 4};
    vector<int> v(sizeof(a)/sizeof(int));
    for(int i = 0; i < sizeof(a)/sizeof(int); i++) {
        v[i] = a[i];
    }
    for(int k = 0; k < v.size(); k++) {
        for(int m = k; m < v.size(); m++) {
            byt(v[k], v[m]);
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

void byt(int &a, int &b) {
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}
