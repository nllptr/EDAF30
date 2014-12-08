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

    Pet* pets[3] = {&bird, &cat, &dog};
    for(int i = 0; i < (int) (sizeof(pets)/sizeof(*pets)); i++) {
        pets[i]->speak();
    }

    Pet* dynPets[3] = {new Bird, new Cat, new Dog};
    for(int i = 0; i < (int) (sizeof(dynPets)/sizeof(*dynPets)); i++) {
        dynPets[i]->speak();
    }

    for(int i = 0; i < (int) (sizeof(dynPets)/sizeof(*dynPets)); i++) {
        dynPets[i]->~Pet();
    }

    return 0;
}
