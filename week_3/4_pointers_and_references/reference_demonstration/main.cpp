#include <iostream>
#include <vector>

int main(void) {

    int age = 29;
    int& rAge = age;

    std::cout 
        << rAge
        << '\n';

    return 0;
}

