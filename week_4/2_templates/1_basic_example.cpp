#include <iostream>

template <typename T>
T addTwoNumbers(T x, T y) {
    return x + y;
}

int main(void) {
    std::cout << addTwoNumbers(5, 10) << '\n';
    std::cout << addTwoNumbers(5.3, 10.2) << '\n';
}