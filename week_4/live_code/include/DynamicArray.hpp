#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <initializer_list>

class DynamicIntegerArray {
private:
    std::unique_ptr<int[]> elements;
    size_t size;
    size_t capacity;

    const size_t minCapacity = 10;

    void reallocate();

public:
    DynamicIntegerArray();
    DynamicIntegerArray(std::initializer_list<int> il);

    void push_back(int val);
    void pop_back();

    int at(int index);

    const int* getArray() const;
    int getSize() const;
    int getCapacity() const;

    const int* begin();
    const int* end();
    const int* begin() const;
    const int* end() const;

    void insertionSort();
    int linearSearch(int value) const;
    int binarySearch(int target);
};

#endif