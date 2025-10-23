#include <iostream>
#include <vector>
#include <memory>

#include "include/pointer.hpp"
#include "include/smart_pointers.hpp"

void allocateSomethingOnTheHeap() {
    auto localPointer = std::make_shared<int>(23);
}

int main(void) {
    
    /* int aVariable = 22;
    int* pVariable = &aVariable;
    int& futureReferense = aVariable; */

    std::unique_ptr<int> anotherVariable = std::make_unique<int>(10);
    std::cout << *anotherVariable << std::endl;
    auto smart2 = std::make_unique<int>(25);



    std::shared_ptr<int> shared1 = std::make_shared<int>(32);
    std::cout << *shared1 << std::endl;

    std::vector<std::unique_ptr<int>> vectorOfIntPointers;


    std::weak_ptr<int> weakptr1 = shared1;

    if (auto local_shared_ptr = weakptr1.lock()) {
        std::cout << "Resource is available and acquired\n";
    } else {
        std::cout << "the resource has been deleted\n";
    }

    return 0;
}