# EXERCISES WEEK 7: MULTITHREADING

## 1. Greetings!
Create a program that uses 4 different threads that print out the following message a set amount of times:

```
Greetings from <Thread name>!
```

## 2. Count to a million
Create a program that uses 4 threads to count to a 1000000! When it has reached 1000000, print out the result!

## 3. Safe Request Counter
Create a program with 5 threads and a global variable `request_counter` which should be initialized to 0. Every thread should make 50 requests, which should **increment** `request_counter`.

After all threads have finished their tasks, print out the result!

## 4. Synchronized Address Book
Create a class AddressBook, which contains a `std::vector` of `Person(name, address, phone)`. `AddressBook` should implement the following methods:
* addContact(Person)
* printContact(std::string name)
* updateContact(std::string name, Person p)
* printAllContacts()

All of these methods should be synchronized.

## 5. Synchronized counter
Create a program with a global `std::atomic<int> counter = 0`. Now implement two functions:
* increment() - increments the counter by 1.
* logCount() - prints out the current count.

Create two threads, one responsible for incrementing and one responsible for logging the count.

## 6. SimpleQueue
Create a templated queue that is threadsafe. It should include the following:

```cpp
template <typename T>
class SimpleQueue {
private:
    std::queue<T> queue;
    std::condition_variable cv;
    std::atomic<bool> stop = false;

public:
    T fetch();
    void push(T value);
    void stopQueue();
    ~SimpleQueue();
};
```

Make sure that the queue is working by applying this code:

```cpp
    srand(time(NULL));

    SimpleQueue<int> numberQueue;

    std::thread producer1([&numberQueue](){
        for (int i = 0; i < 50; i++) {
            int rnd = rand() % 100;
            numberQueue.push(rnd);
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    });

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

    if (producer1.joinable()) producer1.join();
    numberQueue.stopQueue();

    if (consumer1.joinable()) consumer1.join();
```