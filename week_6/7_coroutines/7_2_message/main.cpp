// Include Ranges library
#include <ranges>

// Algorithm library
#include <algorithm>

#include <coroutine>

#include <utility>
#include <string>
#include <iostream>
#include <memory>
#include <functional>

struct Task {

    struct promise_type {
        std::string incoming_message{};
        std::string outgoing_message{};

        Task get_return_object() {
            return Task(std::coroutine_handle<promise_type>::from_promise(*this));
        }

        auto initial_suspend() noexcept {
            return std::suspend_always{};
        }

        auto final_suspend() noexcept {
            return std::suspend_always{};
        }

        void unhandled_exception() {}

        auto yield_value(std::string message) noexcept {
            outgoing_message = std::move(message);
            return std::suspend_always{};
        }

        auto await_transform(std::string) noexcept {
            struct awaiter {
                promise_type& promise;
                constexpr bool await_ready() const noexcept { return true; }
                std::string await_resume() const noexcept {
                    return std::move(promise.incoming_message);
                }
                void await_suspend(std::coroutine_handle<>) const noexcept {}
            };

            return awaiter{*this};
        }

        void return_value(std::string message) noexcept {
            outgoing_message = std::move(message);
        }
    };

    std::coroutine_handle<promise_type> coro_handle = nullptr;

    Task() = default;
    explicit Task(std::coroutine_handle<promise_type> handle) : coro_handle(handle) {}

    ~Task() {
        if (coro_handle) coro_handle.destroy();
    }

    Task(Task&& old) : coro_handle(old.coro_handle) {
        old.coro_handle = nullptr;
    }

    Task& operator=(Task&& old) {
        if (&old != this) {
            coro_handle = old.coro_handle;
            old.coro_handle = nullptr;
        }
        return *this;
    }

    std::string listen() {
        if (!coro_handle.done()) {
            coro_handle.resume();
        }

        return std::move(coro_handle.promise().outgoing_message);
    }

    void answer(std::string message) {
        coro_handle.promise().incoming_message = message;
        if (!coro_handle.done()) {
            coro_handle.resume();
        }
    }
};

Task messages() {
    co_yield "Hello!\n";

    std::cout << co_await std::string{};

    co_return "I'm good, how about you?\n";
}


int main(void) {

    auto chat = messages();

    std::cout << chat.listen();

    chat.answer("Hello!\n");

    std::cout << chat.listen();

    std::cout << "I'm great!\n";

    return 0;
}