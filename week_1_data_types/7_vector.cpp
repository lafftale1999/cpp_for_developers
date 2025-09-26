#include <iostream>
#include <vector>

int main(void) {

    // DECLARING
    std::vector<int> unAssignedVector;

    // ASSIGNING
    unAssignedVector = {3, 2, 9, 10};

    // DECLARING AND ASSIGNING
    std::vector<int> numbers = {1, 4 , 3, 8 , 22, 5, 93, 24};


    // ACCESSING ELEMENTS OF A VECTOR
    std::cout << "Element 0 using .at(): " << numbers.at(0) << std::endl;
    std::cout << "Element 0 using []: " << numbers[0] << std::endl;


    // SIZE OF THE VECTOR
    std::cout << "Size of the vector: " << numbers.size() << std::endl;
    std::cout << "Max size of the vector: " << numbers.max_size() << std::endl;


    // ADDING ELEMENTS TO THE VECTOR
    std::cout << "Before adding elements:" << std::endl;
    for (auto number : numbers) {
        std::cout << number << std::endl;
    }

    // --- removing elements ---
    numbers.push_back(37);
    numbers.insert(numbers.begin() + 3, 72);

    std::cout << "After adding elements:" << std::endl;
    for (auto number : numbers) {
        std::cout << number << std::endl;
    }


    // REMOVING ELEMENTS FROM THE VECTOR
    std::cout << "Before removing elements:" << std::endl;
    for (auto number : numbers) {
        std::cout << number << std::endl;
    }
    
    // --- removing elements ---
    numbers.erase(numbers.begin() + 3);
    numbers.pop_back();

    std::cout << "After removing elements:" << std::endl;
    for (auto number : numbers) {
        std::cout << number << std::endl;
    }

    
    // VECTOR BEHAVIOUR
    std::vector<int> anotherVector = numbers;

    numbers.insert(numbers.begin(), 99);

    std::cout << "Numbers: " << std::endl;
    for (auto n : numbers) {
        std::cout << n << std::endl;
    }

    std::cout << "Another Vector: " << std::endl;
    for (auto n: anotherVector) {
        std::cout << n << std::endl;
    }

    return 0;
}