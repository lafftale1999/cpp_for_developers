#include <iostream>
#include <concepts>
#include <type_traits>

template <typename T>
requires (std::is_integral_v<T> || std::is_floating_point_v<T>)
T square(T x) {
    return x * x;
}

template <typename S>
requires (std::convertible_to<S, std::string>)
int countCharacters (S s) {
    int count = 0;
    for (const auto& char c : s) {
        std::cout << c;
        count++;
    }

    std::cout << std::endl;

    return count;
}

int main(void) {




    return 0;
}