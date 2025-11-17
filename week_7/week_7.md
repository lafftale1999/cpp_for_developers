# Lesson 13: Multithreading: Threads and Synchronization

In this lesson, we’ll explore the fundamentals of **multithreading in C++**, a key technique for making programs faster and more responsive. You’ll learn how to run work in parallel and how to coordinate multiple threads safely when they share data.

We’ll begin by introducing threads independent paths of execution that let your program perform several tasks at the *"same time"*. You’ll see how to start threads, pass them work and ensure they finish properly.

Next, we’ll examine **mutexes**, the basic tool for protecting shared data from being accessed or modified by multiple threads at once. Using mutexes ensures correctness when threads interact with common resources. We’ll also look at shared_mutex, which provides a performance boost for scenarios with many readers and few writers. This allows multiple threads to read shared data concurrently while still guaranteeing safe updates.

After that, we’ll introduce semaphores, a synchronization mechanism that limits how many threads can access a resource simultaneously. This is useful for controlling access to things like database connections or rate-limited services. We’ll also explore atomic types, which allow lightweight, lock-free operations on simple shared variables. They’re ideal for fast counters, flags and other small pieces of shared state.

Finally, we’ll cover condition variables, which allow threads to wait efficiently for specific events, such as new tasks arriving or a state change occurring, without constantly checking for updates.

## Materials for this course
All materials for this lesson in order:
* Video - Multithreading Introduction: [C++ Multithreading](https://www.youtube.com/watch?v=XuaZ0PRnkNE)
* Video - Multithreading Continuation: [C++ Multithreading and Thread Pools](https://www.youtube.com/watch?v=HAE_2Y-BlcQ)
* Playlist - Detailed walkthrough of threads and thread-related objects: [CppNuts - Multithreading in C++](https://youtube.com/playlist?list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&si=7kCz_JSYwaAa6Pfx)
* Presentation - Threads: [Threads.pdf](./presentations/1.%20Threads.pdf)

### Code Demos
* Introduction: [1_thread_introduction](./1_thread_introduction/)
* Mutexes:
    * [2_mutex](./2_mutex/)
    * [3_shared_mutex](./3_shared_mutex/)
* Atomic: [4_atomic](./4_atomic/)
* Condition Variables: [5_condition_variables](./5_condition_variables/)
* Semaphores: [6_semaphores](./6_semaphores/)

## Exercises
Exercises practicing this lessons subjects:
* Threads Exercises: [exercises.md](./exercises.md)