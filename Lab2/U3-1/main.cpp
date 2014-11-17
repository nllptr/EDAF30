#include <iostream>
#include <cstdlib>

using namespace std;

int randInt(int min, int max);

int main()
{
    srand(time(0));
    for(int i = 0; i < 10; i++)
        cout << randInt(1, 3) << endl;
    return 0;
}

int randInt(int min, int max)
{
    // Reasoning: I want to randomize an int between min and max, including max.
    // min = 0, max = 10: rand % (10-0) = rand % 10 = 0..9 -> wrong!
    // min = 0, max = 10: rand % (10-0+1) = rand % 11 = 0..10 -> ok!
    // min = 3, max = 10: rand % (10-3+1) = rand % 8 = 0..7 -> wrong!
    // min = 3, max = 10: (rand % (10-3+1)) + min = rand % 8 + 3 = 0..7 + 3 = 3..10 -> ok!
    return (rand() % (max - min + 1)) + min;
}
