#include <iostream>
#include <vector>

using namespace std;

void byt(int &a, int &b);

int main()
{
    vector<int> v {5, 3, 6, 9, 4, 7, 8, 1, 2};
    for(int i : v)
        cout << i;
    cout << endl;
    for(int i = 0; i < v.size() - 1; i++) {
        for(int j = i + 1; j < v.size(); j++)
            byt(v[i], v[j]);
    }

    for(int i: v)
        cout << i;
    cout << endl;
    return 0;
}

void byt(int &a, int &b) {
    if(a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}
