#include <iostream>

template <typename T>
T addTwoNumbers(T x, T y) {
    return x + y;
}

int main(void) {
    std::cout << addTwoNumbers(5, 10) << std::endl;
    std::cout << addTwoNumbers(5.3, 10.2) << std::endl;
}