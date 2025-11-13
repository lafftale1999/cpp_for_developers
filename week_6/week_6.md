# Lesson 11: STL Introduction
In this lesson, we’ll explore one of the most powerful parts of modern C++, the Standard Template Library (STL). It provides a rich set of tools that make handling data easier, faster and more expressive.

We’ll start by learning about iterators, the key that unlocks the STL. Iterators let us move through elements in a container just like using pointers, but in a safer and more flexible way. We’ll see how they provide a common interface across all container types, making it possible to use the same algorithms for different type of data structures.

Next, we’ll explore containers, the data structures that store and organize our elements.

* **Sequence containers** (std::vector, std::list, std::deque) maintain element order and handle dynamic data efficiently.

* **Associative containers** (std::set, std::map) keep data sorted and provide fast lookups using keys.

* **Unordered Associative containers** (std::unordered_set, std::unordered_map) use hash tables for even faster access when order doesn’t matter.

* **Container adapters** (std::stack, std::queue, std::priority_queue) provide specialized behavior for common programming patterns.

Finally, we’ll work with the STL’s algorithms ready-to-use, optimized functions for searching, sorting, counting and removing elements. By combining them with iterators, we’ll learn how to perform complex operations with just a few lines of clean, efficient code.

## Materials
All materials for this lesson in order:
* Video - STL Introduction: [C++ STL](https://www.youtube.com/watch?v=_SIL3WygE4s)
* YouTube Playlist - All STL Containers: [STL in C++](https://www.youtube.com/playlist?list=PLk6CEY9XxSIA-xo3HRYC3M0Aitzdut7AA)
* Presentation - STL Introduction: [1. STL Introduction.pdf](/week_6/presentations/1.%20STL%20Introduction.pdf)
* Presentation - Algorithms: [2. Algorithms.pdf](/week_6/presentations/2.%20Algorithms.pdf)

### Code Demos
* Sequence Containers: [1_sequence](/week_6/1_sequence/)
* Associative Containers: [2_associative](/week_6/2_associative/)
* Container Adapters: [3_adapters](/week_6/3_adapters/)
* Algorithms: [4_algorithms](/week_6/4_algorithms/)

## Exercises
Exercises practicing this lessons subjects:
* STL Introduction: [STL Introduction](/week_6/exercises.md/#stl-introduction)

---

# Lesson 12: STL Continuation
In this lesson, we’ll continue exploring the C++20 Big Four: Ranges, Views, Concepts, Modules, and Coroutines. You’ll learn how these modern features simplify code organization, improve safety, and make data processing more expressive.

We’ll build on your knowledge of the Standard Template Library (STL) by using ranges and views to create cleaner, more efficient pipelines for handling collections. You’ll also get introduced to concepts for defining clearer constraints in templates and to modules for structuring larger C++ projects with better compile-time efficiency.

## Materials
All materials for this lesson in order:
* Video - C++20 The Big Four: [C++20 The Big Four](https://www.youtube.com/watch?v=Lw5ne7nX-cc)
* Documentation - Ranges and Views: [Ranges library (since C++20)](https://en.cppreference.com/w/cpp/ranges.html)
* Video - Coroutines by Phil Nash: [Phil Nash: Coroutines from Scratch](https://www.youtube.com/watch?v=EGqz7vmoKco)
* Video - Coroutines by Andreas Fertig: [Andreas Fertig: Coroutines for Beginners](https://www.youtube.com/watch?v=8sEe-4tig_A)
* Documentation - Coroutines Documentation: [Coroutines (C++20)](https://en.cppreference.com/w/cpp/language/coroutines.html)
* Presentation - STL Continuation: [3. STL Continuation.pdf](/week_6/presentations/3.%20STL%20Continuation.pdf)

### Code Demos
* Ranges: [5_ranges](/week_6/5_ranges/)
* Views: [6_views](/week_6/6_views/)
* Coroutines: [7_coroutines](/week_6/7_coroutines/)
* Concepts: [8_concepts](/week_6/8_concepts/)

## Exercises
Exercises practicing this lessons subjects:
* STL Continuation: [STL Continuation](/week_6/exercises.md/#stl-continuation)