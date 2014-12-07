#include <iostream>
#include "pet.h"
#include "bird.h"
#include "cat.h"
#include "dog.h"

using namespace std;

int main()
{
    Bird bird;
    Cat cat;
    Dog dog;
    bird.speak();
    cat.speak();
    dog.speak();
    return 0;
}
