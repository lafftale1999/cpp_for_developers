#include <iostream>
#include <vector>

int main(void) {

    // '\0' is called a null-terminator
    // this signals end of string
    char name[] = "Carl\0";

    char* pName = name;

    while(*pName != '\0') {
        std::cout << *pName;
        pName++;
    }

    std::cout << '\n';

    return 0;
}

