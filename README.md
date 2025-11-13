# C++ For developers!
Welcome to your journey into C++! One of the most powerful and influential programming languages in the world. Whether you dream of building games, crafting high-performance software, programming microcontrollers or simply becoming a stronger and more confident developer, this course will give you the foundation you need to get there.

C++ isn’t just another language... It teaches you how software truly works under the hood! By learning it, you gain rare skills that set you apart: deep understanding of memory, performance, data structures, object-oriented design and the ability to build efficient, real-world systems from the ground up.

### What you will learn:
* Master the fundamentals of C++ and write your first programs with confidence

* Learn how to structure code with functions, files, and clean best practices

* Build a strong understanding of object-oriented programming

* Explore memory, pointers, references, and modern C++ resource management

* Work with core data structures, algorithms, and templates

* Step into embedded programming and microcontroller development

* Use the C++ Standard Library and modern C++20 features

* Create real, portfolio-worthy projects that put your skills to the test

### Course Planning
This course is structured for 8 weeks of full-time study, with an estimated 40 hours of work per week. Following this pace will keep you aligned with the intended week-by-week progression and help you build skills steadily.

However, because all content is fully pre-recorded and self-paced, you have complete control over your learning schedule. If 40 hours per week isn’t realistic for you, you can easily stretch the course to 12, 16, or even more weeks without losing any quality of learning.

Before you begin, take a moment to decide how many hours you can dedicate each week and commit to maintaining that pace. Consistency matters far more than speed! Choose a workload that fits your life, stick to it and you’ll progress smoothly through the entire course.

# Study Guide

## Project Templates
The following templates can be used to create C++ projects. You will have to use Makefile Tools in VSCode or CMake depending on what you are used to, and what you want to learn. In the course, we are mainly focusing on Makefile.

* **Simple** project structure (good to start out with): [simple_project_template](/project_templates/simple_project_template/)

* **Intermediate** project structure (good for larger projects): [intermediate_project_template](/project_templates/intermediate_project_template/)

## Week 1
Link to week one: [Week 1 curriculum](/week_1/week_1.md)

### Lesson 1: Introduction
* Introduction to the power and importance of C++
* Overview of the course structure, objectives, and recommendations for success
* Exploration of C++:
    * Brief history and significance in software development
    * Key features that make it exceptional
    * Organization of a C++ program
    * Understanding the compilation process
    * Running your first C++ program
* Setup and installation of necessary tools for the course

### Lesson 2: Syntax and Data Types
* Focus of the lesson: C++ fundamentals — data types and syntax
* Key topics covered:
    * Understanding variables and what happens behind the scenes when they’re created
    * Type conversion and managing value ranges
* Introduction to control statements and loops, essential for program logic
* Discussion of naming conventions and best coding practices
* Introduction to practical data structures for writing clean, efficient, and maintainable code

## Week 2
Link to week two: [Week 2 curriculum](/week_2/week_2.md)

### Lesson 3: Functions and File I/O
* Core concept: Decomposition – breaking complex systems into smaller, reusable parts
* Exploration of functions:
    * What functions are
    * How to use them effectively
    * Types of functions in C++
* Introduction to file input/output (I/O):
    * Reading, writing, and clearing files
    * Understanding data persistence (saving beyond program runtime)
    * Common data formats for storing information

### Lesson 4: OOP Introduction
* Introduction to the OOP paradigm and its impact on modern software development
* Understanding classes and objects – the fundamental building blocks of OOP
* Learning about constructors and destructors and how they manage an object’s lifecycle
* Exploring key OOP principles:
    * Abstraction – simplifying complex systems by focusing on essential features
    * Encapsulation – protecting data and ensuring clean, maintainable, and scalable code

## Week 3
Link to week three: [Week 3 curriculum](/week_3/week_3.md)

### Introduction of Assignment #1: Secure Card System
Build a C++ console-based access control system for a government building with full user/admin functionality, data persistence, validation, and logging.

* Deadline: End of Week 8
* Assignment: [Assignmend #1 - Secure Card System](/assignments/Assignment%20#1%20-%20Secure%20Card%20System.pdf) 

### Lesson 5: OOP Inheritance and Polymorphism
* Deep dive into advanced object-oriented programming (OOP) concepts for building flexible, reusable systems

* Inheritance:
    * Create class hierarchies with shared behavior in base classes
    * Extend functionality in derived classes
    * Reduce duplication and model real-world relationships naturally

* Abstract Classes and Interfaces:
    * Define shared contracts without fixed implementations
    * Use abstract methods and virtual destructors for modular, extensible design
    * Support scalable and adaptable program structures

* Polymorphism:
    * Use base class pointers and references to interact with different object types via a single interface
    * Write generic, elegant, and powerful code
    * Apply concepts in examples like logging systems, game dialogue, and transport calculators

### Lesson 6: Memory, Pointers and References
* **Core topic: Memory management** — controlling and optimizing how programs use memory in C++

* **Memory fundamentals:**
    * Understand how a program looks during runtime
    * Difference between stack and heap memory and when to use each

* **Pointers:**
    * Learn to declare, use, and dereference pointers
    * Understand how data is stored and accessed in memory

* **References:**
    * Learn to declare and use references
    * Enable efficient data manipulation without unnecessary copying
    * Commonly used in function parameters for cleaner and faster code

* **RAII (Resource Acquisition Is Initialization):**
    * Modern approach to safe resource management
    * Introduction to smart pointers:
        * std::unique_ptr – exclusive ownership
        * std::shared_ptr – shared ownership
        * std::weak_ptr – non-owning reference to shared data

## Week 4
Link to week four: [Week 4 curriculum](/week_4/week_4.md)

### Lesson 7 & 8: Data Structures, Algorithms and Templates
* Core data structures:
    * Dynamic arrays, linked lists, and binary search trees
    * Explore their internal organization, data storage, access, and modification

* Algorithms:
    * Study searching and sorting algorithms
    * Analyze performance on different data structures


* Templates and generic programming:
    * Write type-independent code for data structures and algorithms
    * Understand how templates enable flexibility and reusability in C++

* Introduction to cache concepts and types

## Week 5
Link to week five: [Week 5 curriculum](/week_5/week_5.md)

### Introduction of Assignment #2: Embedded Ad Screen
Create the application logic for a company Ad Screen in C++ and finish the LCD driver initialization for an hd44780-based display (using the provided template + Wokwi sketch).

* Deadline: End of Week 8
* Assignment: [Assignmend #2 - Embedded Ad Screen](/assignments/Assignment%20#2%20-%20Embedded.pdf)

### Lesson 9 & 10: Embedded Programming with C++
* What embedded systems are and how MCUs differ from MPUs
* Key terms: peripherals, modules, registers, firmware, datasheets
* Overview of embedded operating systems
* Setting up the AVR library for microcontroller programming
* Arduino Uno architecture basics
* Bit manipulation and simple programs on the AVR ATmega328p

## Week 6
Link to week six: [Week 6 curriculum](/week_6/week_6.md)

### Lesson 11: STL Introduction
* Introduction to the Standard Template Library (STL) and its role in modern C++
* Iterators: unified, pointer-like tools for navigating containers
* Containers:
    * Sequence containers: vector, list, deque
    * Associative containers: set, map
    * Unordered containers: unordered_set, unordered_map
    * Container adapters: stack, queue, priority_queue
* Algorithms: built-in functions for searching, sorting, counting, and modifying data using iterators for clean, efficient code

### Lesson 12: STL Continuation (Out of Scope - Stretch lesson)
* Focus on the C++20 Big Four: Ranges, Views, Concepts, Modules, and Coroutines
* Use ranges and views for cleaner, more expressive data-processing pipelines
* Apply concepts to define safer, clearer template constraints
* Use modules to improve project structure and compile-time performance
* Introduce coroutines for writing efficient asynchronous and lazy computations
* Build on STL knowledge with modern C++20 features that simplify and streamline code

## Week 7
### Lesson 13: Threads

## Week 8
This final week is dedicated to completing and polishing the two major assignments from the course. Your focus should be on finalizing all functionality, ensuring every requirement is met and improving structure and clarity. This is your chance to bring together everything you’ve learned and deliver two fully working, well-designed C++ applications. 

### Assignment #1: Secure Card System (Introduced Week 3)
Build a C++ console-based access control system for a government building with full user/admin functionality, data persistence, validation, and logging.

* Deadline: End of Week 8
* Assignment: [Assignmend #1 - Secure Card System](/assignments/Assignment%20#1%20-%20Secure%20Card%20System.pdf) 

### Assignment #2: Embedded Ad Screen (Introduced Week 5)
Create the application logic for a company Ad Screen in C++ and finish the LCD driver initialization for an hd44780-based display (using the provided template + Wokwi sketch).

* Deadline: End of Week 8
* Assignment: [Assignmend #2 - Embedded Ad Screen](/assignments/Assignment%20#2%20-%20Embedded.pdf)

---

# Course end!
Thank you for taking the time and dedication to complete this course. C++ is a challenging but incredibly rewarding language and the effort you’ve invested here will serve you well as you continue your journey into software development.

I hope the knowledge, techniques and hands-on experience you’ve gained will empower you in future studies, projects, and real-world work. From mastering memory and object-oriented programming to exploring embedded systems, data structures, templates and modern C++ features. You can now proudly claim to be a C++ developer!

Your commitment to learning is what drives progress and I’m confident that the skills you’ve built throughout these weeks will open many doors ahead.

Well done and best of luck in all your future development adventures!

@lafftale1999