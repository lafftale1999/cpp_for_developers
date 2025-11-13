#include <iostream>
#include <concepts>
#include <type_traits>
#include <string>

template <typename T>
requires (std::is_integral_v<T> || std::is_floating_point_v<T>)
T square(T x) {
    return x * x;
}

template <typename S>
requires (std::convertible_to<S, std::string>)
int countCharacters(S s) {
    std::string str = s;  // ensure it's a proper string
    int count = 0;
    for (char c : str) {
        std::cout << c;
        count++;
    }

    std::cout << std::endl;
    return count;
}

int main() {
    std::string my_string = "Hello world";
    std::cout << my_string << " has " 
              << countCharacters(my_string)
              << " characters in it!\n";

    return 0;
}