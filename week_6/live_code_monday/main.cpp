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

    
    return 0;
}