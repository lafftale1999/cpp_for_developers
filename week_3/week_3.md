# Lesson 5: OOP Inheritance & Polymorphism
In this lesson, we’ll dive into the core object-oriented programming (OOP) concepts that make C++ such a powerful language for building flexible and reusable systems.

We’ll begin with inheritance, where you’ll learn how to structure class hierarchies by sharing common behavior in base classes and extending it in derived classes. This allows you to reduce duplication, keep your code organized, and model real-world relationships more naturally.

Next, we’ll explore abstract classes and interfaces — essential tools for defining shared contracts without locking in specific implementations. You’ll see how abstract methods and virtual destructors make it possible to design modular, extensible systems that can be adapted as your programs grow in complexity.

Finally, we’ll bring these concepts together with polymorphism. You’ll learn how to use base class pointers and references to work with different types through a single, unified interface. This enables you to write more generic, elegant, and powerful code — from logging systems to game dialogue and transport calculators.

## Materials
All materials for this lesson in order:
* YouTube Playlist: Inheritance, Polymorphism and Virtual Functions: [Hank Stalica: Inheritance, Polymorphism and Virtual Functions](https://www.youtube.com/playlist?list=PLaatXkJEXKyKlx6H44MbV2d63AmudD5sd)
* Presentation - OOP Inheritance & Polymorphism: [1. OOP Inheritance & Polymorphism.pdf](/week_3/presentations/1.%20OOP%20Inheritance%20&%20Polymorphism.pdf)

### Code Demos
* OOP Inheritance: [1_oop_inheritance](/week_3/1_oop_inheritance/)
* OOP Polymorphism: [2_oop_polymorphism](/week_3/2_oop_polymorphism/)
* Abstract Classes: [3_abstract_classes](/week_3/3_abstract_classes/)

## Exercises
Exercises practicing this lessons subjects:
- [Inheritance, Abstract Classes and Polymorhpism](/week_3/exercises.md/#inheritance-abstract-classes-and-polymorhpism)
    - [Inheritance](/week_3/exercises.md/#inheritance)
    - [Abstract Classes](/week_3/exercises.md/#abstract-classes)
    - [Polymorphism](/week_3/exercises.md/#polymorphism)

---

# Lesson 6: Memory, Pointers and References
In this lesson, we’ll focus on one of the most important aspects of C++ programming: memory management. You’ll learn how to work directly with memory through pointers and references, and how to manage resources safely and efficiently using the RAII (Resource Acquisition Is Initialization) principle with smart pointers.

We’ll begin by understanding memory and how our program looks during runtime. Focusing on the difference between the stack and the heap, and when they should be used.

Secondly we will talk about pointers, which give you direct access to memory. You’ll learn how to declare and use them, read and modify values through indirection, and apply pointer arithmetic in practical scenarios. This will give you a solid understanding of how data is stored and accessed in memory - a crucial skill for any C++ developer.

Next, we’ll work with references, a safer and more convenient way to refer to existing variables. You’ll see how references make it easy to pass and manipulate data without unnecessary copies and how they’re often preferred in function parameters for clean and efficient code.

Finally, we’ll introduce RAII and smart pointers, modern C++ tools that handle resource management automatically. You’ll learn how std::unique_ptr, std::shared_ptr, and std::weak_ptr help prevent memory leaks and dangling pointers by tying resource lifetimes to object lifetimes.

## Materials
All materials for this lesson in order:
* Video - Introduction to Stack and Heap: [Stack vs Heap in C++](https://www.youtube.com/watch?v=wJ1L2nSIV1s)
* Video - Introduction to Pointers in C++: [Pointers C++](https://www.youtube.com/watch?v=DTxHyVn0ODg)
* Video - Introduction to References in C++: [References in C++](https://www.youtube.com/watch?v=IzoFn3dfsPA)
* Video - Introduction to Smart Pointers (RAII): [Smart Pointers in C++](https://www.youtube.com/watch?v=UOB7-B2MfwA&t=107s)
* Presentation - Memory, Pointers and References: [2. Memory, Pointers and References.pdf](/week_3/presentations/2.%20Memory,%20Pointers%20and%20References.pdf)

### Code Demo
* Pointers and References: [4_pointers_and_references](/week_3/4_pointers_and_references/)

## Exercises
Exercises practicing this lessons subjects:
- [Pointers, References and RAII](/week_3/exercises.md/#pointers-references-and-raii)
    - [Pointers](/week_3/exercises.md/#pointers)
    - [References](/week_3/exercises.md/#references)
    - [RAII (smart pointers)](/week_3/exercises.md/#raii---smart-pointers)