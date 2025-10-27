#include "../classes/Movies.hpp"

// Sequence containers libraries
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

// Algorithm library
#include <algorithm>

#include <chrono>
#include <iterator>
#include <memory>

template <typename T>
void findMovie(const T& container, std::string target, std::string containerType) {
    
    std::cout << "\n---------- FIND MOVIE IN CONTAINER TYPE: " << containerType << " ----------\n";

    auto start = std::chrono::high_resolution_clock::now();
    bool found = std::any_of(container.begin(), container.end(), [&target](const auto& element) {
        return element.getTitle() == target;
    });
    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    std::cout << (found ? "FOUND! " : "NOT FOUND! ") << "Operation took: " << ms << "μs | Using containertype: " << containerType << std::endl;
    std::cout << "---------- END ----------\n";
}

template <typename T>
void sortList(T& container, std::string containerType) {
    std::cout << "\n---------- SORT MOVIES BY TITLE IN CONTAINER TYPE: " << containerType << " ----------\n";

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(container.begin(), container.end(), [] (const auto& a, const auto& b) {
        return a.getTitle() < b.getTitle();
    });
    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "SORTED! " << "Operation took: " << ms << "ms | Using containertype: " << containerType << std::endl;
    std::cout << "---------- END ----------\n";
}

int main(void) {

    MovieList movies = MovieList();

    auto& movieReference = movies.getMovies();

    std::string target = "Princess Caraboo";
    
    // ---- ARRAY ----
    std::array<Movie, 1000> moviesArray;
    auto n = std::min(moviesArray.size(), movieReference.size());
    std::copy_n(movieReference.begin(), n, moviesArray.begin());
    findMovie(moviesArray, target, "Array");
    sortList(moviesArray, "Array");
    /* if (std::is_sorted(moviesArray.begin(), moviesArray.end())) std::cout << "sorted\n";
    else std::cout << "not sorted\n"; */

    // ---- VECTOR ----
    std::vector<Movie> moviesVector;
    std::copy(movieReference.begin(), movieReference.end(), std::back_inserter(moviesVector));
    findMovie(moviesVector, target, "Vector");
    sortList(moviesVector, "Vector");

    // ---- DEQUEUE ----
    std::deque<Movie> moviesDoubleEndedQueue;
    std::copy(movieReference.begin(), movieReference.end(), std::back_inserter(moviesDoubleEndedQueue));
    findMovie(moviesDoubleEndedQueue, target, "Dequeue");
    sortList(moviesDoubleEndedQueue, "Dequeue");

    // ---- LIST ----
    std::list<Movie> moviesDoublyLinkedList;
    std::copy(movieReference.begin(), movieReference.end(), std::back_inserter(moviesDoublyLinkedList));
    findMovie(moviesDoublyLinkedList, target, "List");
    moviesDoublyLinkedList.sort();

    // ---- FORWARD LIST ----
    std::forward_list<Movie> moviesSingleLinkedList;
    std::copy(movieReference.begin(), movieReference.end(), std::front_inserter(moviesSingleLinkedList));
    findMovie(moviesSingleLinkedList, target, "Forward List");
    moviesSingleLinkedList.sort();

    return 0;
}