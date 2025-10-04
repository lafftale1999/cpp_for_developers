#include <iostream>

int addTwoNumbers(int x, int y) {
    int result = x + y;
    return result;
}

int main(void) {
    int x = 32;
    int y = 14;

    std::cout << addTwoNumbers(x, y);

    return 0;
}

