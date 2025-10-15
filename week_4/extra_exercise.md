# Extra Exercises!
### 1. Cache
Creata a templated cache using a circular linked list. The class can look something like this:

```cpp
class Cache {
private:
    struct Element {
        T e;
        size_t index;
    }

    // struct defining the nodes (use element as data)
    // pointer to head
    // pointer to tail
    // size and capacity

public:
    Cache();
    Cache(size_t capacity);
    void save(const T& element, size_t index); // <- Create Element struct and adds to front
    size_t load(const T& element); // <- returns the index saved in Element struct if found
};
```

Create a new class based on DynamicArray called CachedDynamicArray and add the cache as a member. Implement this behaviour:
* Everytime you search in your array - look through the cache first to get the index faster.
* When an element is found, it should be placed at the front of your cache.
    * If an element is found inside the cache, this should also be placed at the front. Remember to rearrange pointers.
* The cache capacity should be set at 10.
* When the cache is full, evict the oldest element.

---

### 2. Compare Data Structures
Create a program that measures the performance of your DynamicArracy and your CachedDynamicArray. For each of the following points you shall measure the time by adding the operation between start and end here:

```cpp
#include <chrono> // <- functionality defined in this library

auto start = std::chrono::high_resolution_clock::now();
// operation (for example finding all numbers)
auto end = std::chrono::high_resolution_clock::now();
std::cout << "Operation took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds using <Data Structure Type>" << std::endl;
```

Now do the following:
* Generate and insert a 1000 random integers between 1 and 50.
* Do 100 iterations of searching for random numbers between 1 and 50 using linear search in each Array.
* Calculate the average time for searching with and without a Cache.

---