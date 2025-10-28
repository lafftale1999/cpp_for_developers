#include "../classes/Movies.hpp"

// Container Adapters libraries
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

// Algorithm library
#include <algorithm>

#include <cmath>
#include <chrono>
#include <iterator>
#include <memory>
#include <functional>

int main(void) {
    MovieList movies = MovieList(50);
    auto& r_movies = movies.getMovies();

    // SEQUENCE CONTAINERS
    std::array<Movie, 100> movieArray;
    std::vector<Movie> movieVector;
    std::deque<Movie> movieDeque;
    std::list<Movie> movieList;
    std::forward_list<Movie> movieForwardList;

    // --------------------- COPY ---------------------
    // Copies a RANGE of elements to a new location
    int n = std::min(movieArray.size(), r_movies.size());
    std::copy_n(r_movies.begin(), n, movieArray.begin());
    std::copy(r_movies.begin(), r_movies.end(), std::back_inserter(movieVector));
    std::copy(r_movies.begin(), r_movies.end(), std::back_inserter(movieDeque));
    std::copy(r_movies.begin(), r_movies.end(), std::back_inserter(movieList));
    std::copy(r_movies.begin(), r_movies.end(), std::front_inserter(movieForwardList));
    movieForwardList.reverse();

    // ------------ LOOP THROUGH CONTAINERS ----------------------
    std::function<void(const Movie& movie)> printMovie = [](const Movie& movie) {
        std::cout << movie.getId() << "\t|\t" << movie.getYearOfRelease() << "\t|\t" << movie.getTitle() << std::endl;
    };

    std::cout << "\n ----- ARRAY ----- \n";
    std::for_each(movieArray.begin(), movieArray.end(), printMovie);
    std::cout << " ----- ARRAY ----- \n";

    std::cout << "\n ----- VECTOR ----- \n";
    std::for_each(movieVector.begin(), movieVector.end(), printMovie);
    std::cout << " ----- VECTOR ----- \n";

    std::cout << "\n ----- DEQUE ----- \n";
    std::for_each(movieDeque.begin(), movieDeque.end(), printMovie);
    std::cout << " ----- DEQUE ----- \n";

    std::cout << "\n ----- LIST ----- \n";
    std::for_each(movieList.begin(), movieList.end(), printMovie);
    std::cout << " ----- LIST ----- \n";

    std::cout << "\n ----- FORWARD_LIST ----- \n";
    std::for_each(movieForwardList.begin(), movieForwardList.end(), printMovie);
    std::cout << " ----- FORWARD_LIST ----- \n";

    // --------------------- SEARCHES ---------------------
    // preparing the search function
    std::string titleTarget = "Copycat";
    std::function<bool(const Movie& movie)> searchFunction = [&titleTarget](const Movie& movie) {
        return titleTarget == movie.getTitle();
    };


    // - all_of
    if (std::all_of(movieArray.begin(), movieArray.end(), searchFunction)) {
        std::cout << "The array only contains the movie: " << titleTarget << std::endl;
    } else {
        std::cout << "The array has mixed movies!\n";
    }


    // - any_of
    if (std::any_of(movieVector.begin(), movieVector.end(), searchFunction)) {
        std::cout << "The vector contains the movie: " << titleTarget << std::endl;
    } else {
        std::cout << "The vector did not contain the movie: " << titleTarget << std::endl;
    }


    // none_of
    if (std::none_of(movieDeque.begin(), movieDeque.end(), searchFunction)) {
        std::cout << "The deque does not contain the movie: " << titleTarget << std::endl;
    } else {
        std::cout << "The deque contains the movie: " << titleTarget << std::endl;
    }


    // find
    const auto find_it = std::find_if(movieList.begin(), movieList.end(), searchFunction);
    if (find_it != movieList.end()) {
        std::cout << "The list contains the movie: " << find_it->getTitle() << std::endl;
    }


    // count_if
    std::string yearTarget = "1994";
    auto count = std::count_if(movieForwardList.begin(), movieForwardList.end(), [&yearTarget](const auto& movie) {
        return movie.getYearOfRelease() == yearTarget;
    });
    std::cout << "There where " << count << " movies released in " << yearTarget << std::endl;
    


    // --------------------- REMOVE ---------------------
    // remove_if
    // it will not remove , but rearrange the container and put the elements to remove at the back
    // and then return an iterator to where the first element to be removed is

    // Containers with random access (array, vector and deque)
    auto remove_it = std::remove_if(movieVector.begin(), movieVector.end(), [&yearTarget](const Movie& movie) {
        return movie.getYearOfRelease() == yearTarget;
    });

    // then we use this iterator to create a range of elements we want to remove
    movieVector.erase(remove_it, movieVector.end());

    count = std::count_if(movieVector.begin(), movieVector.end(), [&yearTarget](const auto& movie) {
        return movie.getYearOfRelease() == yearTarget;
    });
    std::cout << "There where " << count << " movies released in " << yearTarget << std::endl;


    // Containers without random access (list and forward list)
    // This basically works the same way, but without the extra step for the random access containers
    std::string removeTargetTitle = "Clueless";
    movieList.remove_if([&removeTargetTitle](const Movie& movie) {
        return movie.getTitle() == "Clueless";
    });

    // creating and checking a temporary iterator to see if the removed title still exists
    if (auto temp_it = std::find_if(movieList.begin(), movieList.end(), [&removeTargetTitle] (const Movie& movie) {
        return movie.getTitle() == removeTargetTitle;
    }); temp_it != movieList.end()) {
        std::cout << "The list contains the movie: " << temp_it->getTitle() << std::endl;
    } else {
        std::cout << "The list no longer contain: " << removeTargetTitle << std::endl;
    }
    
    
    
    // --------------------- SORT ---------------------
    std::sort(movieVector.begin(), movieVector.end(), [](const auto& a, const auto& b) {
        return a.getTitle() < b.getTitle();
    });

    if (std::is_sorted(movieVector.begin(), movieVector.end())) {
        std::cout << "Movie Vector is now sorted!\n";

        for (const auto& movie: movieVector) {
            printMovie(movie);
        }
    }

    return 0;
}