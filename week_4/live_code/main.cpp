#include <iostream>
#include <vector>
#include <cmath>

/* #include "include/DynamicArray.hpp"
#include "include/BinarySearchTree.hpp"
#include "include/LinkedList.hpp" */

/*
explanation why we use templates:
instead of overloading the same function
several times, we use templates - which under the hood
will create the overloaded functions we use, but we
don't need to write them!
*/

// This will only work properly for integers, there's no floating precision
int addNumber(int x, int y) {
    return x + y;
}

// This will work with doubles aswell
double addNumber(double x, double y) {
    return x + y;
}

// This will work for all datatypes that support addition
template <typename T>
T genericAdder(T x, T y) {
    return x + y;
}

template <typename T, typename Y>
Y divideTwoNumbers(T x, Y y) {
    return x / y;
}

template <typename T>
T sumVector(std::vector<T> values) {
    T sum = 0;
    for(const auto& v : values) {
        sum += v;
    }

    return sum;
}

double addTwoNumbers(double x, double y) {
    std::cout << "overloaded called\n";
    return x + y;
}

// ----------- Small showcasing of callback functions -----------
void printNumber(int x) {
    std::cout << x << std::endl;
}

void addition(int x, int y, void (*callback)(int)) {
    int result = x + y;
    callback(result);
}

#include <algorithm>

// Templated search function
template <typename T, typename Compare>
bool find_any_of(std::vector<T>& values, T target, Compare compare) {
    for (const auto& v : values) {
        if(compare(v, target)) return true; 
    }

    return false;
}

int main(void) {

    // Using templated functions to add numbers
    std::vector<int> values {3,9,21};
    std::cout << sumVector(values) << std::endl;
    std::cout << addTwoNumbers(4.2, 9.3) << std::endl;

    // Showcasing callbacks and function pointers
    void (*callback)(int);
    callback = printNumber;
    callback(53);

    // How we use STL algorithms and lambda functions to
    // manipulate the containers
    std::vector<int> values = {3, 9, 82, 38, 49, 2, 7, 74};
    std::sort(values.begin(), values.end(), [](const int& a, const int& b) {
        return a < b;
    });

    int target = 82;

    // Using STL search algorithm and lambda to search in container
    if(std::any_of(values.begin(), values.end(), [&](const auto& a) {
        return target == a;
    })) {
        std::cout << "Target found\n";
    } else {
        std::cout << "Not found\n";
    }

    // Using our own templated search function + lambda expression
    if (find_any_of(values, 82, [](const int& a, const int& c) {
        return a == c;
    })) {
        std::cout << "Target found\n";
    } else {
        std::cout << "Not found\n";
    }

    // Passing lambda function as an argument to our function
    addition(24, 84, [](int n) {
        std::cout << "Lambda function callback: " << n << std::endl;
    });

    // Showcasing how the vector behaves when adding and ereasing elements
    std::vector<int> values = {3,9,2,1};
    std::cout << "Before adding\n";
    for(auto v : values) {
        std::cout << v << std::endl;
    }

    std::vector<int> valuesToAdd {9,8,22,32,91};
    values.insert(values.end(), valuesToAdd.begin(), valuesToAdd.end());

    std::cout << "After adding\n";
    for(auto v : values) {
        std::cout << v << std::endl;
    }

    values.erase(values.begin() + 4, values.end());
    std::cout << "After deleting\n";
    for(auto v : values) {
        std::cout << v << std::endl;
    }

    return 0;
}