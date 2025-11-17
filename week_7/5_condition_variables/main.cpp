#include <iostream>

#include <vector>
#include <queue>
#include <initializer_list>

#include <algorithm>
#include <ranges>
#include <cmath>

#include <optional>

// Thread related includes
#include <thread>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <shared_mutex>

// Time library
#include <chrono>

template <typename T>
class SimpleQueue {
private:
    // our container for pushing and popping elements
    std::queue<T> queue;

    // mutex for locking critical sections
    std::mutex mtx;

    // condition variable to enable signaling between threads
    std::condition_variable cv;

    // bool to control if the queue is still running or not
    std::atomic<bool> stop = false;

public:
    T fetch() {
        // acquire a lock. cw.wait() only works with a std::unique_lock
        // because std::lock_guard is scope-based.
        std::unique_lock<std::mutex> lock(mtx);

        /* 
        By using cv.wait(), the following will happen:
        1. It will evaluate the predicate.
        2. If the predicate returns true, it will continue execution.
        3. If false, it will wait until it's notified.
        */
        cv.wait(lock, [this]{return !queue.empty() || stop.load(); });

        /* 
        If we reached this section, it means that either:
        1. An item was pushed to the queue and we are supposed to fetch it.
        2. The queue is stopping and we should try to empty the queue.
        */
        if (!queue.empty()) {
            T element = std::move(queue.front());
            queue.pop();

            std::cout << "Fetching: " << element << std::endl;
            return element;
        }

        /*
        If there is no item left, we throw an error - only affecting the thread
        in execution. This will terminate the thread.
        */
        throw std::runtime_error("Queue is stopping");
    }

    void push(T value) {
        {
            /* 
            Acquire the lock. Here we use the std::lock_guard as a scope based
            lock works fine here.
            */
            std::lock_guard<std::mutex> lock(mtx);

            /*
            We check if the queue is still running. If not, we should terminate
            this thread.
            */
            if (stop.load()) {
                throw std::runtime_error("Queue is stopping");
            }

            std::cout << "Pushing: " << value << std::endl;
            // If not, we push it to the queue
            queue.push(std::move(value));
        }

        /* 
        This will notify one of the threads waiting to be awaken by elements being
        pushed to the queue. Then it will continue to execute after line 45!
        */
        cv.notify_one();
    }

    /* 
    Helper function to properly stop the queue.
    */
    void stopQueue() {
        /* 
        Securely assigning the bool value true to stop, signaling that all the threads
        working with the queue should finish execution of our queue.
        */
        stop.store(true);

        /* 
        This will wake up all the threads waiting to be notified and evaluate the cv.wait() predicate.
        Since the predicate will now return true - it will start executing from line 45!
        */
        cv.notify_all();
    }

    ~SimpleQueue() {
        /* 
        Ensuring that we are properly stopping the threads executing in the queue when object
        runs out of scope.
        */
        stopQueue();
    }
};

// IMPORTANT: This will not handle the joining of the threads themselves, this still needs to be defined by the caller!


int main(void) {
    srand(time(NULL));

    SimpleQueue<int> numberQueue;

    /* 
    Thread 1 is producing and pushing 50 random rumbers between 0 and 99.
    */
    std::thread producer1([&numberQueue](){
        for (int i = 0; i < 50; i++) {
            int rnd = rand() % 100;
            numberQueue.push(rnd);
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    });

    /* 
    Thread 2 is fetching numbers from the queue. If the queue is stopped
    and emptied - an exception will be thrown and the thread will finish.
    */
    std::thread consumer1([&numberQueue](){
        try {
            while (true) {
                int n = numberQueue.fetch();
                n += 0; // just to avoid compile warnings
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
        } catch (const std::runtime_error& e) {
            std::cout << "Consumer exiting: " << e.what() << '\n';
        }
    });
    
    /* 
    Join producer and stop the queue since no more elements will be added.
    */
    if (producer1.joinable()) producer1.join();
    numberQueue.stopQueue();

    /* 
    Let the consumer thread empty the queue.
    */
    if (consumer1.joinable()) consumer1.join();

    return 0;
}