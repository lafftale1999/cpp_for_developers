#include <iostream>
#include <vector>

int main(void) {
    
    // Sole owner of pointer
    // Destroyed when out of scope
    std::unique_ptr<int> pAge = std::make_unique<int>(29);

    // Shared owner
    // Destroyed when last owner is out of scope
    std::shared_ptr<int> aGrade = std::make_shared<int>(2);
    std::shared_ptr<int> bGrade = aGrade;

    // No ownership
    std::weak_ptr<int> cGrade = aGrade;

    // Access weak_ptr
    if (auto sp = cGrade.lock()) {  // Try to get shared_ptr
        std::cout << "Grade: " << *sp << std::endl;
    } else {
        std::cout << "Grade object no longer exists." << std::endl;
    }
}

