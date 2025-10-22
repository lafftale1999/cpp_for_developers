#include <iostream>
#include <vector>

struct Person {
    std::string name;
};

const int* findValue(int target, const std::vector<int>& v) {
    
    // int& direct reference to the number
    // *v is the vector we are looping through

    for (const int& n : v) {
        if (target == n) return &n;
    }

    return nullptr;
}

int pointerProgram(void) {
    
    /* char* pointer_to_grade = nullptr;

    // a variable of type char
    char grade = 'C';

    // pointing to a variable of type char
    pointer_to_grade = &grade; */

    std::vector<int> numbers = { 1 , 4, 9 ,2, 10, 7};

    const int* n = findValue(10, numbers);

    if (n != nullptr) {
        int index = n - &numbers[0];
        std::cout << "the value was found at " << index << "!\n";
    } else {
        std::cout << "it wasnt found!\n";
    }

    int age = 29;
    int* pAge = &age;
    
    std::cout << age << std::endl;
    std::cout << pAge << std::endl;
    std::cout << *pAge << std::endl;

    pAge++;

    std::cout << age << std::endl;
    std::cout << pAge << std::endl;
    std::cout << *pAge << std::endl;

    return 0;
}