# Exercises for week 4
This contains all exercises for week 4!



## Data Structures & Algorithms

### 1. SimpleIntegerArray
Create a heap allocated array using smart pointers. Define the following class:

```cpp

#define MINIMUM_CAPACITY 10

class SimpleIntegerArray {
private:
    std::unique_ptr<int[]> elements;
    size_t size;
    size_t capacity;

public:
    SimpleIntegerArray();
    SimpleIntegerArray(std::initializer_list<int> e);

    void push_back(int element);
    void pop_back();
    int at(size_t index);
    size_t getSize();
    size_t getCapacity();
}
```

Do the following:
* Create a SimpleIntegerArray with the array `{3, 22, 1, 8, 5}`
* Add an integer to the back using push_back(). Print the list.
* Remove the last element using pop_back(). Print the list.
* Print the size and capacity.

---

### 2. DynamicArray
Create a templated dynamic array using smart pointers. Define the following class:

```cpp
class DynamicArray {
private:
    // pointer to array
    // size of array
    // capacity of array
    void reallocate(size_t newCapacity);

public:
    DynamicArray();
    DynamicArray(std::initializer_list<T> e);
    ~DynamicArray();
    void push_back(const T& value);
    void pop_back();
    void removeAt(size_t index);
    T& operator[](size_t index);
    T& at(size_t index);
    size_t getSize() const;
    size_t getCapacity() const;
}
```

---

### 3. Array Algorithms
Use the DynamicArray from the exercise above and add these following member functions to it:

```cpp
// search functions that returns the index of your target
int linearSearch(T target);

// sorting functions
void insertionSort();
void bubbleSort();
```

---

### 4. Binary Search
Add a binary search function to the Dynamic Array. This will only work on sorted arrays, implement a way to decide if it's applicable or not. This can be done by adding a flag that keeps track if the array is sorted or not.

---

### 5. Try the DynamicArray
Now create one of the three different arrays below and add 10 elements to it:

```cpp
DynamicArray<int> integers = {...};
DynamicArray<std::string> strings = {...};
DynamicArray<double> doubles = {...};
```

Try the following functions for your DynamicArray and print the result of each function:
1. Add element with push_back()
2. Remove element with pop_back()
3. Edit element using .at()
4. Search a value using linearSearch()
5. Sort the array using one of the sorting functions
6. Search a value using binarySearch()
7. Remove an element using removeAt()

---

### 6. Single Linked List
Create a templated Single Linked List using smart pointers. A singly linked list consists of nodes where each node contains data and a pointer to the next node. Define the following class:

```cpp
class SingleLinkedList {
private:
    // Struct describing the linkedlist structure and T data
    // pointer to head
    // size

public:
    SingleLinkedList();
    SingleLinkedList(std::initializer_list<T> e);
    void push_front(const T& value);
    void push_back(const T& value);
    void insert(const T& value, int index);
    T& operator[](size_t index);
    T& at(size_t index);
    size_t getSize() const;
    void print() const; // <- prints all elements
};
```

---

### 7. Double Linked List
Create a templated double linked list with both a head and tail. Adjust the functions to make better use of knowing about the tail.

```cpp
class DoubleLinkedList {
private:
    // Struct describing the linkedlist structure and T data
    // pointer to head
    // pointer to tail
    // size

public:
    DoubleLinkedList();
    DoubleLinkedList(std::initializer_list<T> e);
    void push_front(const T& value);
    void push_back(const T& value);
    void insert(const T& value, int index);
    int find(const T&);
    T& operator[](size_t index);
    T& at(size_t index);
    size_t getSize() const;
    void print() const; // <- prints all elements
};
```

---

### 8. Binary Search Tree
Create a templated binary search tree. A binary search tree organizes elements so that left child < parent < right child. Implement the following class:

```cpp
class BST {
private:
    // Struct to describe the node
    // pointer to root
    // size

public:
    BST() = default;
    BST(std::initializer_list<T> e);
    void insert(const T&); // <- duplicates goes to the right subtree
    bool find(const T&);
    void print() const; // <- prints all elements (use inorder algorithm)
};
```

---

### 9. Compare Data Structures
Create a program that measures the performance of each data structure. For each of the following points you shall measure the time by adding the operation between start and end here:

```cpp
#include <chrono> // <- functionality defined in this library

auto start = std::chrono::high_resolution_clock::now();
// operation (for example finding all numbers)
auto end = std::chrono::high_resolution_clock::now();
std::cout << "Operation took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds using <Data Structure Type>" << std::endl;
```

Now measure the performance of the following operations using the above code:
1. Generating and inserting 1000 random integers between 1 and 50.
2. Inserting an integer in the middle (only linked list and array)
3. Finding a specific value in the array

---

### 10. Cache
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

### 11. New measurements
Do [Exercise 6 - Compare Data Structures](#6-compare-data-structures) again and measure the difference in performance of using the cache in CachedDynamicArray vs DynamicArray.

---