#include <iostream>
#include <memory>

template <typename T, int N>
class TemplatedArray {
private:
    std::unique_ptr<T[]> element;
};