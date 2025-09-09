#include <iostream>

int main(void) {
    // WHILE
    // The loop will run WHILE the statement within the ()-brackets is true.
    int loopMax = 5;
    int loopCounter = 0;

    while(loopCounter++ < loopMax) {
        std::cout << "While loop:" << loopCounter << std::endl;
    }

    // DO WHILE
    // The loop will run ATLEAST once before checking of the statement
    // within the ()-brackets are true.
    int doWhileCounter = 0;
    loopCounter = 0;

    do {
        std::cout << "Do-While loop:" << loopCounter << std::endl;
    } while (loopCounter++ < doWhileCounter);

    // FOR-LOOP
    // Loops through a user defined range and gives us an index,
    // good for navigating through arrays when you need their positions
    int ages[] = {25, 32, 29, 19, 43};

    for(int i = 0; i < loopMax; i++) {
        std::cout << "For-loop:" << ages[i] << std::endl;
    }

    // ENHANCED FOR-LOOP
    // Loops through a container of elements. Unable to have index here.
    for(int age : ages) {
        std::cout << age << std::endl;
    }

    return 0;
}