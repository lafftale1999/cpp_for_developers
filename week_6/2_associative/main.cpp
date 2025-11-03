#include "../classes/Movies.hpp"

// Associative containers libraries
#include <map>
#include <set>
#include <unordered_set>

// Algorithm library
#include <algorithm>

#include <cmath>
#include <chrono>
#include <iterator>
#include <memory>

int main(void) {
    srand(time(NULL));

    MovieList movies = MovieList(200);
    auto& r_movies = movies.getMovies();

    std::string target = "Princess Caraboo";

    // -------------- MAP ------------------
    std::map<int, Movie> movieMap;
    // this is the same as for(auto move : r_movies)
    for (auto it = r_movies.begin(); it != r_movies.end(); ++it) {
        movieMap.insert({it->getId(), *it});
    }

    // searching in a map
    auto it = std::find(movieMap.begin(), movieMap.end(), [&target](const Movie& movie) {
        return movie.getTitle() == target;
    });

    if (it != movieMap.end()) {
        std::cout << it->second.getTitle() << " found!\n"; 
    } else {
        std::cout << target << " was not found!\n";
    }

    // accessing through key
    std::cout << movieMap.at(8).getTitle() << std::endl;

    // Writing out the first 10 movies in the map
    int count = 0;
    const int max_count = 10;
    for (auto it = movieMap.begin(); it != movieMap.end() && count < max_count; ++it, ++count) {
        std::cout << it->first << " | " << it->second.getTitle() << std::endl;
    }


    // ------------- SET ------------------------
    std::set<Movie> movieSet;
    for (auto movie : r_movies) {
        movieSet.insert(movie);
    }

    count = 0;
    for (auto it = movieSet.begin(); it != movieSet.end() && count < max_count; ++it, ++count) {
        std::cout << it->getId() << " | " << it->getTitle() << std::endl;
    }


    // ----------- UNORDERED MAP -----------
    std::unordered_map<int,int> unorderedMap;
    for (int i = 0; i < 100; i++) {
        int rnd = rand() % 10000;
        unorderedMap.insert({i, rnd});
    }

    count = 0;
    for (auto it = unorderedMap.begin(); it != unorderedMap.end() && count < max_count; ++it, ++count) {
        std::cout << it->first << " | " << it->second << std::endl;
    }


    // ----------- UNORDERED SET ------------
    std::unordered_set<int> unorderedSet;
    for (int i = 0; i < 100; i++) {
        int rnd = rand() % 10000;
        unorderedSet.insert(rnd);
    }

    count = 0;
    for (auto it = unorderedSet.begin(); it != unorderedSet.end() && count < max_count; ++it, ++count) {
        std::cout << *it << std::endl;
    }

    return 0;
}