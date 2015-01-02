#include <iostream>

#include "bostad.h"

using namespace std;

int main()
{
    int storlek[2] = {18, 22};
    int garderober[2] = {2, 4};
    Bostad bostad(12, false, true,
                  4, true,
                  24, false,
                  storlek,
                  garderober,
                  sizeof(storlek) / sizeof(int)
                  );
    bostad.skriv();
    return 0;
}
