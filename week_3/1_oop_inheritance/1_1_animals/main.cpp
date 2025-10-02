#include "include/cat.h"
#include "include/dog.h"
#include "include/owner.h"

int main(void) {

    

    

    // Owner
    std::string name = "Birk";
    std::string phone = "0748312374";
    Animal animal = Animal("Ringo", "Ahssjsjsjs", 231);

    Owner owner = Owner("Birk", "0748312374", animal);

    // Animal
    std::string name;
    std::string sound;
    int age;

    animal.run();
    animal.makeSound();

    Cat cat = Cat("Snuffles", "Mjaow", 8, 2.31);
    cat.run();
    cat.makeSound();
    cat.jump();

    return 0;
}