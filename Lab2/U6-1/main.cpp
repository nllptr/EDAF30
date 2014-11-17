#include <iostream>
#include <vector>

using namespace std;

void addOne(vector<int> &v) {
    for(int i = 0; i < v.size(); i++)
        v[i]++;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    addOne(v);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}

