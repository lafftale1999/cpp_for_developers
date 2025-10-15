#include <iostream>
#include <memory>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class TemplatedArray {
private:
    std::unique_ptr<T[]> elements;
    size_t size;
    size_t capacity;

public:
    TemplatedArray() = default;
    TemplatedArray(size_t c)
    : elements(nullptr), size(0), capacity(c) {
        elements = std::make_unique<T[]>(c);
        if (!elements) {
            throw std::runtime_error("Unable to allocate array");
        }
    }

    TemplatedArray(std::initializer_list<T> e) 
    : elements(nullptr), size(e.size()), capacity(0) {
        capacity = size == 0 ? 10 : size * 2;
        elements = std::make_unique<T[]>(capacity);
        if (!elements) {
            throw std::runtime_error("Unable to allocate array");
        }

        std::copy(e.begin(), e.end(), elements.get());
    }

    T& at(int index) {
        if (index < 0 || (size_t)index >= size) {
            throw std::out_of_range("Trying to access out of range index");
        }

        return elements[index];
    }

    void push_back(T& e) {
        if (size == capacity) {
            throw std::runtime_error("TemplatedArray is full");
        }

        elements[size++] = e;
    }

    void pop_back() {
        if (size == 0) {
            throw std::runtime_error("Trying to remove from an empty array");
        }

        size--;
    }
};

int main(void) {

    TemplatedArray<std::string> names = {"carl", "marl", "squarl", "harl"};

    TemplatedArray<int> values = {3, 9, 23, 19, 8};

    TemplatedArray<double> values = {3.9, 2.4, 9.82};

}