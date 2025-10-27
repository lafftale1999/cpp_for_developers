#include "../classes/Movies.hpp"

// Associative containers libraries
#include <map>
#include <set>

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
    auto& r_movies = movies.getMovies();

    std::map<int, Movie> movieMap;
    
    // this is the same as for(auto move : r_movies)
    for (auto it = r_movies.begin(); it != r_movies.end(); ++it) {
        movieMap.insert({it->getId(), *it});
    }

    std::set<Movie> movieSet;
    for (auto movie : r_movies) {
        movieSet.insert(movie);
    }

    return 0;
}