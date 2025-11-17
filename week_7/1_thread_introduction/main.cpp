#include <iostream>
#include <thread>
#include <chrono>

void print_symbol(const char symbol, int times) {
    for (int i = 0; i < times; i++) {
        std::cout << symbol;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main(void) {
    int times = 50;

    // A thread takes a function, and any arguments to the function.

    std::thread thread_one(print_symbol, 'H', times);
    
    std::thread thread_two(print_symbol, 'G', times);

    // It also accepts lambda functions
    std::thread thread_three([&times]() {
        for (int i = 0; i < times; i++) {
            std::cout << 'T';
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    });

    // Another way of using a lambda
    std::thread thread_four([](const char symbol, int times) {
        for (int i = 0; i < times; i++) {
            std::cout << symbol;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    },
        'W', times // the arguments passed to the lambda function
    );
    
    // our main thread will stop here and wait for the other threads
    // finish executing. This is necessary as the main thread (function)
    // owns these threads and without this, an exception will be thrown.
    thread_one.join();
    thread_two.join();
    thread_three.join();
    thread_four.join();

    return 0;
}