#include <iostream>
#include <forward_list>
#include <cstdlib>

using namespace std;

forward_list<int>* randomize_list(int n);
int find_greatest(forward_list<int>& list);
void print_list(forward_list<int>& list);

int main()
{
    srand(time(NULL));

    forward_list<int> *list = randomize_list(10);
    cout << "The list:" << endl;
    print_list(*list);

    int greatest = find_greatest(*list);
    cout << endl << "The greatest: " << greatest << endl;

    delete list;
    list = NULL;
    return 0;
}

forward_list<int>* randomize_list(int n)
{
    forward_list<int> *list = new forward_list<int>;
    for(int i = 0; i < n; i++) {
        list->push_front(rand() % 10000);
    }
    return list;
}

int find_greatest(forward_list<int>& list)
{
    int greatest = -1;
    for(forward_list<int>::iterator it = list.begin(); it != list.end(); it++) {
        if(*it > greatest) greatest = *it;
    }

    return greatest;
}

void print_list(forward_list<int>& list)
{
    for(forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
        cout << *it << endl;
}
