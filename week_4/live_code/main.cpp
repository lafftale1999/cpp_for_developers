#include <iostream>
#include <vector>
#include <cmath>

/* #include "include/DynamicArray.hpp"
#include "include/BinarySearchTree.hpp"
#include "include/LinkedList.hpp" */

/* int addNumber(int x, int y) {
    return x + y;
}

double addNumber(double x, double y) {
    return x + y;
} */
template <typename T, typename Y>
Y divideTwoNumbers(T x, Y y) {
    return x / y;
}

template <typename T>
T addTwoNumbers(std::vector<T> values) {
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

void printNumber(int x) {
    std::cout << x << std::endl;
}

void addition(int x, int y, void (*callback)(int)) {
    int result = x + y;
    callback(result);
}

#include <algorithm>

template <typename T>
bool find_any_of(std::vector<T>& values, T target, bool(*compare)(T, T)) {
    for (const auto& v : values) {
        if(compare(v, target)) return true; 
    }

    return false;
}

class Person {
public:
    std::string name;
};

bool findPerson (Person& person) {
    std::cout << person.name << std::endl;
}

int main(void) {
    srand(NULL);

/*     std::vector<int> values {3,9,21};

    std::cout << addTwoNumbers(values) << std::endl;
    std::cout << addTwoNumbers(4.2, 9.3) << std::endl; */

    /* void (*callback)(int);
    callback = printNumber;
    callback(53); */

    std::vector<int> values = {3, 9, 82, 38, 49, 2, 7, 74};

    std::sort(values.begin(), values.end(), [](const auto& a, const auto& b) {
        return a < b;
    });

    int target = 82;

    if (find_any_of(values, 82, [](int a, int c) {
        return a == c;
    })) {
        std::cout << "Target found\n";
    } else {
        std::cout << "Not found\n";
    }

    
    /* if(std::any_of(values.begin(), values.end(), [&](const auto& a) {
        return target == a;
    })) {
        std::cout << "Target found\n";
    } else {
        std::cout << "Not found\n";
    }

    for (const auto& v : values) {
        std::cout << v << ", ";
    } */

    std::cout << std::endl;

    addition(24, 84, [](int n) {
        std::cout << "Lambda function callback: " << n << std::endl;
    });

    

    /* std::vector<std::string> first_names = {"Carl", "Hussein", "Ava", "Richard"};
    std::vector<std::string> last_names = {"Sevor", "River", "Lovefruit", "Grip"};

    std::vector<std::string> names;

    int fn_size = first_names.size();
    int ln_size = last_names.size();

    for(int i = 0; i < 30; i++) {
        int fn = rand() % fn_size;
        int ln = rand() % ln_size;

        std::string name = first_names.at(fn) + " " + last_names.at(ln);
        names.push_back(name);
    }

    for (const auto& name : names) {
        std::cout << name << std::endl;
    } */

    /* std::vector<int> values = {3,9,2,1};

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
    } */

    return 0;
}