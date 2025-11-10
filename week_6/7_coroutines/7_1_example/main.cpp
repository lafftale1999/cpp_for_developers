#include "../classes/Movies.hpp"

// Container Adapters libraries
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

// Include Ranges library
#include <ranges>

// Algorithm library
#include <algorithm>

#include <coroutine>

#include <utility>
#include <string>
#include <iostream>
#include <cmath>
#include <chrono>
#include <iterator>
#include <memory>
#include <functional>
#include <string_view>

// Our wrapper type for the coroutines return type
struct resumable_thing {

    // Mandatory syntactical type "promise_type".
    // This describes the promise object inside the coroutine frame. It defines
    // how the coroutine should behave.
    struct promise_type {
        // can also hold fields

        // returns our wrapper type "resumable_thing", which holds a handle
        // to the co-routines promise object. This is a definition of the
        // "resumable_thing"s ownership of the promise object
        resumable_thing get_return_object() {
            std::cout << "1. get_return_object()\n";
            return resumable_thing(std::coroutine_handle<promise_type>::from_promise(*this));
        }

        // Defines the behaviour of what happens right after our
        // coroutine is created.
        auto initial_suspend() noexcept { 
            std::cout << "3. initial_suspend()\n";
            return std::suspend_never{};
        }

        // Defines the behaviour of what happens when we use co_return
        auto final_suspend() noexcept { 
            std::cout << "final_suspend()\n";
            return std::suspend_always{};
        }

        // Defines the behaviour of returning nothing from our coroutine
        void return_void() noexcept {std::cout << "return_void()\n";}

        // How we should handle exceptions thrown inside our
        // coroutine.
        void unhandled_exception() {
            std::terminate();
        }

        // other type of methods to overload:
        // co_await
        // co_yield
    };

    // handle to the coroutines promise object
    std::coroutine_handle<promise_type> _coroutine = nullptr;

    // Constructors
    resumable_thing() = default;
    
    // Explicit constructor that does not allow implicit casting. The handle
    // must point towars a promise object when creating a "resumable_thing"
    explicit resumable_thing(std::coroutine_handle<promise_type> coroutine)
    : _coroutine(coroutine) {
        std::cout << "2. resumable_thing created\n";
    }
    
    // Deletetion of constructors and operators
    resumable_thing(resumable_thing const&) = delete;               // Deletes copy constructor
    resumable_thing& operator=(resumable_thing const&) = delete;    // Deletes copy assignment operator

    // Move Constructor (Object Creation)
    // Defines how to transfer ownership of resources from on object (other) to a new one
    resumable_thing(resumable_thing&& other) 
    : _coroutine(other._coroutine) {
        other._coroutine = nullptr;
    }

    // Move Assignment Operator (Object assignment)
    // Defines how to transfer ownership during assignment
    resumable_thing& operator=(resumable_thing&& other) {
        if (&other != this) {
            _coroutine = other._coroutine;
            other._coroutine = nullptr;
        }
        return *this;
    }

    // Small control API
    bool resume() const {
        if (!_coroutine || _coroutine.done()) return false;
        std::cout << "\nbefore resume()\n";
        _coroutine.resume();
        std::cout << "after resume()\n";
        return true;
    }

    bool done() const {
        return !_coroutine || _coroutine.done();
    }

    ~resumable_thing() {
        if (_coroutine) { _coroutine.destroy(); }
    }
};

resumable_thing counter() {
    std::cout << "counter: called\n";
    for (unsigned i = 1; ; ++i) {
        co_await std::suspend_always{};
        std::cout << "counter: resumed #" << i << std::endl;
    }
}


int main(void) {
    std::cout << "main: start\n";

    auto coro = counter();

    std::cout << "main: back again\n";
    coro.resume();
    coro.resume();
    coro.resume();

    std::cout << "main: before end\n";

    return 0;
}