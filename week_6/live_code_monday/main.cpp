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

int main(void) {
    srand(time(NULL));

    // Importing movies from a list
    // and creating a direct reference to the list
    MovieList movies = MovieList(50);
    auto& r_movies = movies.getMovies();

    // Containers
    std::deque<Movie> movies_deque;
    std::vector<Movie> movies_vector;
    std::list<Movie> movies_dlist;
    std::forward_list<Movie> movies_flist;

    // COPY 
    std::copy(r_movies.begin(), r_movies.end(), std::back_inserter(movies_deque));
    std::copy(r_movies.begin(), r_movies.end(), std::back_inserter(movies_vector));
    std::copy(r_movies.begin(), r_movies.end(), std::back_inserter(movies_dlist));
    std::copy(r_movies.begin(), r_movies.end(), std::front_inserter(movies_flist));

    std::string targetTitle = "Copycat";
    std::function<bool(const Movie& m)> searchFunction = [&targetTitle](const Movie& m) {
        return m.getTitle() == targetTitle;
    };

    if (std::any_of(movies_deque.begin(), movies_deque.end(), searchFunction)) {
        std::cout << "1. The title " << targetTitle << " was found in the container!\n";
    }

    auto found = std::any_of(movies_dlist.begin(), movies_dlist.end(), [&targetTitle](const auto& m){
        return m.getTitle() == targetTitle;
    });
    if (found) {
        std::cout << "2. The title " << targetTitle << " was found in the container!\n";
    }


    found = std::none_of(movies_dlist.begin(), movies_dlist.end(), searchFunction);
    if (!found) {
        std::cout << "3. The title " << targetTitle << " was found in the container!\n";
    }

    
    auto find_if_it = std::find_if(movies_deque.begin(), movies_deque.end(), searchFunction);
    
    if (find_if_it != movies_deque.end()) {
        std::cout << "After std::find_if we found: " << find_if_it->getTitle() << std::endl;
    }


    std::string yearTarget = "1994";
    auto count = std::count_if(movies_deque.begin(), movies_deque.end(), [&yearTarget](const auto& m){
        return m.getYearOfRelease() == yearTarget;
    });

    std::cout << "there were " << count << " movies released in " << yearTarget << std::endl;



    // REMOVE FROM LISTS - .remove_if(pred/lambda)
    movies_dlist.remove_if([&yearTarget](const auto& m){
        return m.getYearOfRelease() == yearTarget;
    });

    // REMOVE
    auto remove_it = std::remove_if(movies_deque.begin(), movies_deque.end(), 
        [&yearTarget](const auto& m) {
            return m.getYearOfRelease() == yearTarget;
        }
    );

    movies_deque.erase(remove_it, movies_deque.end());

    // COUNT AGAIN
    count = std::count_if(movies_deque.begin(), movies_deque.end(), [&yearTarget](const auto& m){
        return m.getYearOfRelease() == yearTarget;
    });

    std::cout << "there were " << count << " movies released in " << yearTarget << std::endl;



    // SORT

    for (const auto& m : movies_vector) {
        std::cout << m.getId() << " | " << m.getTitle() << std::endl;
    }

    std::cout << "\n\n-------------------------\n\n";

    std::sort(movies_vector.begin(), movies_vector.end(), [](const auto& a, const auto& b){
        return a.getTitle() > b.getTitle();
    });

    std::for_each(movies_vector.begin(), movies_vector.end(), [](const auto& m) {
        std::cout << m.getId() << " | " << m.getTitle() << std::endl;
    });

    return 0;
}