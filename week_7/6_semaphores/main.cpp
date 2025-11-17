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
#include <condition_variable>
#include <queue>
#include <optional>
#include <semaphore>

std::counting_semaphore<1> sem(1);

void printTask(std::string workerName) {
    std::cout << workerName << " is waiting...\n";

    sem.acquire();
    std::cout << workerName << " entered the critical section!\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << workerName << " is leaving the critical section...\n\n";
    sem.release();
}

int main() {
    std::thread t1 (printTask, "Thread 1");
    std::thread t2 (printTask, "Thread 2");
    std::thread t3 (printTask, "Thread 3");

    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    if (t3.joinable()) t3.join();

    return 0;
}