#include <iostream>
#include <memory>

int main(void) {

    // Looping through an array of integers
    int numbers[] = {3, 9, 8, 23, 1, 65, 6};
    for (auto number : numbers) {
        std::cout << number << '\n';
    }

    // Printing and looping through an array of Characters
    char name[] = {'C', 'a', 'r', 'l', '\0'};
    std::cout << name << '\n';
    for (auto c : name) {
        std::cout << c;
    }
    std::cout << '\n';

    // Looping through an array of integers on the heap
    const size_t size = 5;
    auto numbersOnHeap = std::make_unique<int[]>(size);

    numbersOnHeap[0] = 32;
    numbersOnHeap[1] = 6;
    numbersOnHeap[2] = 82;
    numbersOnHeap[3] = 4;
    numbersOnHeap[4] = 231;

    for(int i = 0; i < size; i++) {
        std::cout << numbersOnHeap[i] << '\n';
    }

    return 0;
}