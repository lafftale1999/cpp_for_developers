#include "../classes/Movies.hpp"

// Container Adapters libraries
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <unordered_set>

// Algorithm library
#include <algorithm>

#include <cmath>
#include <chrono>
#include <iterator>
#include <memory>
#include <functional>

#include <cmath>

#include <ranges>
#include <vector>
#include <deque>

#include <coroutine>

struct Chat {

    struct promise_type {
        std::string incoming_message;
        std::string outgoing_message;

        Chat get_return_object() {
            std::cout << "get_return_object()\n";
            return Chat(std::coroutine_handle<promise_type>::from_promise(*this));
        }

        auto initial_suspend() noexcept {
            std::cout << "initial_suspend()\n";
            return std::suspend_always{};
        }

        auto final_suspend() noexcept {
            std::cout << "final_suspend()\n";
            return std::suspend_always{};
        }

        void unhandled_exception() {};

        auto yield_value(std::string message) noexcept {
            std::cout << "yield_value()\n";
            outgoing_message = std::move(message);
            return std::suspend_always{};
        }

        auto await_transform(std::string) noexcept {
            std::cout << "await_transform()\n";
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
            std::cout << "return_value()\n";
            outgoing_message = std::move(message);
        }
    };

    std::coroutine_handle<promise_type> coro_handle = nullptr;

    Chat() = default;
    explicit Chat(std::coroutine_handle<promise_type> handle) : coro_handle(handle) {
        std::cout << "Chat created!\n";
    }

    ~Chat() {
        if (coro_handle) coro_handle.destroy();
    }

    Chat(Chat&& old) : coro_handle(old.coro_handle) {
        old.coro_handle = nullptr;
    }

    Chat& operator=(Chat&& old) {
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
        std::cout << "\nlisten()\n";
        return std::move(coro_handle.promise().outgoing_message);
    }

    void answer(std::string message) {
        std::cout << "\nanswer()\n";
        coro_handle.promise().incoming_message = message;
        if (!coro_handle.done()) {
            coro_handle.resume();
        }
    }
};

Chat messages() {
    co_yield "Hello from Coroutine!\n";

    std::cout << co_await std::string{};

    co_return "Goodbye from Coroutine!\n";
}

int main(void) {
    auto chat = messages();

    std::cout << chat.listen();
    chat.answer("Hello from the main function!\n");

    std::cout << chat.listen();

    // create coroutine
    // print out a message from coroutine
    // send a message to the coroutine
    // print out a message from the coroutine






















    /* 
    // Importing movies from a list
    // and creating a direct reference to the list
    MovieList movies = MovieList(50);
    auto& r_movies = movies.getMovies();

    std::deque<Movie> movies_deque;

    std::ranges::copy(r_movies, std::back_inserter(movies_deque));
    // std::ranges::sort(movies_deque, {}, &Movie::getTitle);

    std::cout << "\nbefore movies_view\n";
    auto movies_view = movies_deque | std::views::filter([](const auto& m) {
        std::cout << "*f\n";
        return m.getTitle().at(0) == 'P';
    }) | std::views::transform([](const auto& m) {
        std::cout << "*t\n";
        return m.getTitle();
    });

    std::cout << "\nAfter movies_view\n";

    for (auto m : movies_view) {
        std::cout << "*l\n";
        std::cout << m << std::endl;
    } */

    /* // FOUND
    auto found = std::ranges::any_of(movies_deque, [](const auto& m){
        return m.getTitle() == "Othello";
    });

    if (found) std::cout << "Othello was found!\n";

    // REMOVE
    auto remove_range = std::ranges::remove_if(movies_deque, [](const auto& m) {
        return m.getTitle().at(0) == 'C';
    });

    movies_deque.erase(remove_range.begin(), remove_range.end());

    // SORT
    std::ranges::sort(movies_deque, {}, &Movie::getTitle);

    for (const auto& m : movies_deque) {
        std::cout << m.getId() << " | " << m.getTitle() << std::endl;
    } */

    return 0;
}