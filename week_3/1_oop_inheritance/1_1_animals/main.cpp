#include "include/cat.h"
#include "include/dog.h"
#include "include/owner.h"

int main(void) {
    Animal animal = Animal("Ringo", "Ahssjsjsjs", 231);

    Owner owner = Owner("Birk", "0748312374", animal);

    animal.run();
    animal.makeSound();

    Cat cat = Cat("Snuffles", "Mjaow", 8, 2.31);
    cat.run();
    cat.makeSound();
    cat.jump();

    return 0;
}

