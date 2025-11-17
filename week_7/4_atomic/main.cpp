#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <initializer_list>
#include <algorithm>
#include <ranges>
#include <atomic>

std::atomic<int> atomic_counter = 0;
int counter = 0;

void atomic_count(int amount) {
    for (int i = 0; i < amount; i++) {
        atomic_counter++;
    }
}

void normal_count(int amount) {
    for (int i = 0; i < amount; i++) {
        counter++;
    }
}

int main(void) {

    // Using atomic
    std::thread t1(atomic_count, 1000000);
    std::thread t2(atomic_count, 1000000);
    
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();

    std::cout << "Atomic counter: " << atomic_counter << std::endl;

    // Not using atomic
    t1 = std::thread(normal_count, 1000000);
    t2 = std::thread(normal_count, 1000000);

    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();

    std::cout << "Normal counter: " << counter << std::endl;
    
    return 0;
}