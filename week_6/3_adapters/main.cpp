#include "../classes/Movies.hpp"

// Container Adapters libraries
#include <queue>
#include <stack>

// Algorithm library
#include <algorithm>

#include <cmath>
#include <chrono>
#include <iterator>
#include <memory>

int main(void) {
    srand(time(NULL));

    MovieList movies = MovieList();
    auto& r_movies = movies.getMovies();

    // ------------- QUEUE ---------------
    std::cout << "------------------- QUEUE ---------------\n";
    std::queue<Movie*> movieQueue;
    for (int i = 0; i < 10; i++) {
        int rnd = rand() % r_movies.size();

        movieQueue.push(&r_movies.at(rnd));
        std::cout << "Added to queue: " << movieQueue.back()->getTitle() << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << "Now watching: " << movieQueue.front()->getTitle() << std::endl;
        movieQueue.pop();
    }
    std::cout << "------------------- END ---------------\n";

    // ----------------- STACK ----------------
    std::cout << "------------------- STACK ---------------\n";
    std::stack<Movie*> movieStack;
    for (int i = 0; i < 10; i++) {
        int rnd = rand() % r_movies.size();

        movieStack.push(&r_movies.at(rnd));
        std::cout << "Added to stack: " << movieStack.top()->getTitle() << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << "Now watching: " << movieStack.top()->getTitle() << std::endl;
        movieStack.pop();
    }
    std::cout << "------------------- END ---------------\n";

    return 0;
}