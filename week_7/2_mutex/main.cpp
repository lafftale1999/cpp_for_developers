#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <algorithm>
#include <ranges>

class Employee {
public:
    int id;
    std::string name;
    double salary;

    Employee(int _id, std::string _name, double _salary)
    : id(_id), name(_name), salary(_salary) {
        if (id < 0 || name.empty() || salary < 0) {
            throw std::invalid_argument("Failed to create new employee");
        }
    }
};

class Employees {
public:
    std::vector<Employee> employees;
    // Every employees object will have a mutex (a lock and key)
    std::mutex mtx;

    // Simple move constructor
    void addEmployee(Employee&& e) {
        employees.emplace_back(std::move(e));
    }

    // Our data manipulation method which can cause race conditions.
    void updateSalary(int id, double amount) {
        // Here we acquire the lock. std::lock_guard follows RAII
        // which means we don't need to worry about scope.
        std::lock_guard<std::mutex> lock(mtx);
        
        auto it = std::ranges::find_if(employees, [&id](const auto& e){
            return e.id == id;
        });

        it->salary += amount;
    }

    void paySalary() {
        for (const auto& e : employees) {
            std::cout << e.name << " was paid: " << e.salary << " SEK!\n";
        }
    }
};

int main(void) {
    
    Employees company;

    company.addEmployee(Employee(1,  "Alice",      32000));
    company.addEmployee(Employee(2,  "Bob",        35000));
    company.addEmployee(Employee(3,  "Charlie",    31000));
    company.addEmployee(Employee(4,  "Diana",      40000));
    company.addEmployee(Employee(5,  "Ethan",      29000));
    company.addEmployee(Employee(6,  "Fiona",      36000));
    company.addEmployee(Employee(7,  "George",     33000));
    company.addEmployee(Employee(8,  "Hannah",     39000));
    company.addEmployee(Employee(9,  "Ian",        27000));
    company.addEmployee(Employee(10, "Jenny",      42000));
    company.addEmployee(Employee(11, "Karl",       31000));
    company.addEmployee(Employee(12, "Laura",      37000));
    company.addEmployee(Employee(13, "Mike",       34000));
    company.addEmployee(Employee(14, "Nina",       35500));
    company.addEmployee(Employee(15, "Oscar",      30000));
    company.addEmployee(Employee(16, "Paula",      38500));
    company.addEmployee(Employee(17, "Quinn",      29500));
    company.addEmployee(Employee(18, "Rita",       36000));
    company.addEmployee(Employee(19, "Sam",        41000));
    company.addEmployee(Employee(20, "Tina",       37500));

    int user_input = 0;

    // 0 = update salary
    // 1 = pay salary
    // 2 = change name
    if (user_input == 0) {
        std::thread update(&Employees::updateSalary, &company, 4, 3400);
        update.join();
    } else if (user_input == 1) {
        std::thread pay(&Employees::paySalary, &company, )
    }

    return 0;
}