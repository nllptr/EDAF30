#include <iostream>

#include "pet.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"

using namespace std;

int main()
{
    cout << "Creating dog." << endl;
    Dog dog;
    dog.speak();
    cout << "Creating cat." << endl;
    Cat cat;
    cat.speak();
    cout << "Creating bird." << endl;
    Bird bird;
    bird.speak();
    cout << "All animals created." << endl << endl;

    cout << "Creating pet pointer array." << endl;
    cout << "Adding created pets to array." << endl;
    Pet* petPtr[3] = {&dog, &cat, &bird};
    cout << "Iterating over array." << endl;
    for(int i = 0; i < (int) (sizeof(petPtr) / sizeof(*petPtr)); i++) {
        petPtr[i]->speak();
    }

    cout << endl << "Creating array of dynamically allocated animals." << endl;
    Pet* dynAllocPets[3] = {new Dog, new Cat, new Bird};
    cout << "Iterating over array." << endl;
    for(int i = 0; i < (int) (sizeof(dynAllocPets) / sizeof(*dynAllocPets)); i++) {
        dynAllocPets[i]->speak();
    }
    cout << "Calling destructors." << endl;
    for(int i = 0; i < (int) (sizeof(dynAllocPets) / sizeof(*dynAllocPets)); i++) {
        dynAllocPets[i]->~Pet();
    }

    cout << endl << "Trying to declare oject of type Pet (will not compile)." << endl;
    Pet pet;
    return 0;
}

