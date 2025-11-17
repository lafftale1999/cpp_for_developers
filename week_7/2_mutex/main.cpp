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
    : id(_id), name(std::move(_name)), salary(_salary) {
        if (id < 0 || name.empty() || salary < 0) {
            throw std::invalid_argument("Failed to create new employee");
        }
    }
};

class Employees {
std::vector<Employee> employees;

// Every instance of the Employees Class will have a mutex (a lock and key)
std::mutex mtx;

public:
    
    /*
    We use this line in every method that manipulates or read the objects attributes:
    std::lock_guard<std::mutex> lock(mtx);
     
    This will:
    1. Wait until it acquires the key.
    2. Lock the mutex
    3. Release the lock when going out of scope. (RAII)
    */

    void addEmployee(Employee&& e) {
        std::lock_guard<std::mutex> lock(mtx);
        employees.emplace_back(std::move(e));
    }

    bool updateSalary(int id, double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        
        auto it = std::ranges::find_if(employees, [&id](const auto& e){
            return e.id == id;
        });

        if (it != employees.end()) {
            it->salary += amount;
            return true;
        }
        
        return false;
    }

    void paySalary() {
        std::lock_guard<std::mutex> lock(mtx);
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

    std::thread updateThread;
    std::thread payThread;
    std::thread addEmployeeThread;

    // 0 = update salary
    // 1 = pay salary
    // 2 = add employee
    if (user_input == 0) {
        updateThread = std::thread(&Employees::updateSalary, &company, 4, 3400);
    } else if (user_input == 1) {
        payThread = std::thread(&Employees::paySalary, &company);
    } else if (user_input == 2) {
        addEmployeeThread = std::thread(&Employees::addEmployee, &company, Employee(21, "Carl", 23700));
    }

    if (updateThread.joinable()) updateThread.join();
    if (payThread.joinable()) payThread.join();
    if (addEmployeeThread.joinable()) addEmployeeThread.join();

    return 0;
}