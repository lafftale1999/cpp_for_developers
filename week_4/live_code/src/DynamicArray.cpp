#include "../include/DynamicArray.hpp"
#include <iostream>

#define CALC_CAPACITY(size) ((size) * 2)

void DynamicIntegerArray::reallocate() {
    capacity = (capacity == 0) ? minCapacity : CALC_CAPACITY(size);
    auto temp = std::make_unique<int[]>(capacity);

    if(!temp) {
        throw std::runtime_error("Unable to allocate memory");
    }

    for (int i = 0; i < size; i++) {
        temp[i] = elements[i];
    }

    elements = std::move(temp);
}

DynamicIntegerArray::DynamicIntegerArray()
: elements(nullptr), size(0), capacity(0) {}

DynamicIntegerArray::DynamicIntegerArray(std::initializer_list<int> il)
: elements(nullptr), size(il.size()), capacity(CALC_CAPACITY(size)) {
    if (size > 0) {
        elements = std::make_unique<int[]>(capacity);
        if(!elements) {
            throw std::runtime_error("Unable to allocate memory");
        }

        std::copy(il.begin(), il.end(), elements.get());
    }
}


void DynamicIntegerArray::push_back(int val) {
    if (size == capacity) {
        reallocate();
    }

    elements[size++] = val;
}

void DynamicIntegerArray::pop_back() {

}

int DynamicIntegerArray::at(int index) {

}

const int* DynamicIntegerArray::getArray() const {

}

int DynamicIntegerArray::getSize() const {

}

int DynamicIntegerArray::getCapacity() const {

}

const int* DynamicIntegerArray::begin() {

}

const int* DynamicIntegerArray::end() {

}

const int* DynamicIntegerArray::begin() const {

}

const int* DynamicIntegerArray::end() const {

}

void DynamicIntegerArray::insertionSort() {

}

int DynamicIntegerArray::linearSearch(int value) const {

}

int DynamicIntegerArray::binarySearch(int target) {

}