#include "../include/smart_pointers.hpp"
#include <iostream>
#include <vector>
#include <memory>

// Simple struct for examples
struct Person {
    std::string name;
    std::string phone;
    std::string address;

    Person(std::string n, std::string p, std::string a) : name(n), phone(p), address(a) {}
};

int smartPointerMain(void) {
    // -------------------- RAW POINTERS ----------------
    // 1. Create container with raw pointers
    std::vector<Person*> rawAddressBook {
        new Person("Carl", "123", "Höstgatan 3"),
        new Person("Osman", "42365", "Vintergatan 4"),
        new Person("Klara", "938745", "Sommargatan 34")
    };

    // 2. Do something with the container
    for (auto& person : rawAddressBook) {
        std::cout << person->name << " lives at " << person->address << std::endl;
    }

    // 3. When we are done, we need to free all the memory
    for (auto& person : rawAddressBook) {
        delete(person);
    }
    
    // -------------------- SMART POINTERS ----------------
    // 1. Create container with smart pointers
    std::vector<std::unique_ptr<Person>> raiiAddressBook {
        std::make_unique<Person>("Carl", "123", "Höstgatan 3"),
        std::make_unique<Person>("Osman", "42365", "Vintergatan 4"),
        std::make_unique<Person>("Klara", "938745", "Sommargatan 34")
    };

    // 2. Do something with the container
    for (auto& person : raiiAddressBook) {
        std::cout << person->name << " lives at " << person->address << std::endl;
    }

    // 3. The resources are freed automatically because they are now tied
    // to the objects lifetime (scope)

    // -------------------- DIFFERENT TYPES OF POINTERS --------------------------
    // Sole owner of pointer
    // Destroyed when out of scope
    std::unique_ptr<int> pAge = std::make_unique<int>(29);

    // Shared owner
    // Destroyed when last owner is out of scope
    std::shared_ptr<int> aGrade = std::make_shared<int>(2);
    std::shared_ptr<int> bGrade = aGrade;

    // No ownership
    std::weak_ptr<int> cGrade = aGrade;

    // Access weak_ptr by acquiring a shared_ptr 
    if (auto sp = cGrade.lock()) {  // Try to get shared_ptr
        std::cout << "Grade: " << *sp << std::endl;
    } else {
        std::cout << "Grade object no longer exists." << std::endl;
    }

    return 0;
}
