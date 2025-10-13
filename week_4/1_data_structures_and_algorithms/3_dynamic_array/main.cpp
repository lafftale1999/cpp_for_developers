#include <iostream>
#include <memory>
#include <stdexcept>
#include <initializer_list>

#define CALC_CAPACITY(size) ((size) * 2)

class DynamicIntegerArray {
private:
    std::unique_ptr<int[]> elements;
    size_t size;
    size_t capacity;

    const size_t minCapacity = 10;

    void reallocate() {
        capacity = (capacity == 0) ? minCapacity : CALC_CAPACITY(size);
        auto temp = std::make_unique<int[]>(capacity);

        if (!temp) {
            throw std::runtime_error("Unable to reallocate memory");
        } 

        for (int i = 0; i < size; i++) {
            temp[i] = elements[i];
        }

        elements = std::move(temp);
    }

public:
    DynamicIntegerArray()
    : elements(nullptr), size(0), capacity(0) {}

    DynamicIntegerArray(std::initializer_list<int> il)
    : elements(nullptr), size(il.size()), capacity(CALC_CAPACITY(size)) {
        if (size > 0) {
            elements = std::make_unique<int[]>(capacity);
            if (!elements) {
                throw std::runtime_error("Unable to allocate memory");
            }

            std::copy(il.begin(), il.end(), elements.get());
        }
    }

    void push_back(int val) {
        if (size == capacity) {
            reallocate();
        }
        elements[size++] = val;
    }

    void pop_back() {
        if (size <= 0) throw std::out_of_range("Trying to pop an empty array");
        size--;
        if (size < (capacity / 4) && size > minCapacity) {
            reallocate();
        }
    }

    int at(int index) {
        if (size == 0 ||
            index < 0 ||
            index >= size ) {
                throw std::out_of_range("Index out of range");
            }

        return elements[index];
    }

    const int* getArray() const {
        return elements.get();
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    const int* begin() { 
        return elements.get(); 
    }

    const int* end() { 
        return elements.get() + size; 
    }

    const int* begin() const { 
        return elements.get(); 
    }

    const int* end() const { 
        return elements.get() + size; 
    }

    void insertionSort() {
        for (int i = 1; i < size; i++) {
            int valueToInsert = elements[i];
            int insertionIndex = i;

            while (insertionIndex > 0 && elements[insertionIndex - 1] > valueToInsert) {
                elements[insertionIndex] = elements[insertionIndex - 1];
                insertionIndex--;
            }

            elements[insertionIndex] = valueToInsert;
        }
    }

    int linearSearch(int value) const {
        for(int i = 0; i < size; i++) {
            if (elements[i] == value) return i;
        }
        return -1;
    }

    int binarySearch(int target) {
        int tries = 50;

        int begin = 0;
        int end = size;
        
        while (begin < end) {
            int mid = begin + (end - begin) / 2;

            int value = elements[mid];

            if (target == value) return mid;
            else if (target < value) end = mid;
            else if (target > value) begin = mid + 1;
            if(tries-- == 0) return -1;
        }

        return -1;
    }
};

int main(void) {

    DynamicIntegerArray arr = {3, 1, 2, 9, 8, 3, 24, 12, 32, 9, 21, 17, 84};

    for( auto n : arr) {
        std::cout << n << std::endl;
    }

    arr.insertionSort();

    for (auto n : arr) {
        std::cout << n << std::endl;
    }
    
    int index = arr.binarySearch(24);
    if (index -1) {
        std::cout << "Found at: " << index << std::endl;
    }
    return 0;
}