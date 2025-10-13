#include <iostream>
#include <vector>

int main(void) {

    struct Person {
        std::string name;
    };

    // bool isTrue = true;
    // bool isFalse = false;

    int loopCounter = 0;
    int maxLoops = 10;

    while(loopCounter < maxLoops) {
 
    }

    std::cout << "Inside the do while!" << std::endl;
    do {
        std::cout << loopCounter++ << std::endl;    
    } while (loopCounter < maxLoops);

    int transactions[] = {399, 499, 599};

    int size = sizeof(transactions) / sizeof(transactions[0]);

    std::cout << "Inside the for loop!" << std::endl;
    for (int i = 0; i < size; i++) {
        if (transactions[i] == 499) {
            std::cout << "FOUND at : " << i << std::endl;
            break;
        }
    }

    std::cout << "Inside the enhanced for loop!" << std::endl;
    for (int t : transactions) {
        if (t == 499) {
            std::cout << t << std::endl;
        }
    }

    return 0;
}