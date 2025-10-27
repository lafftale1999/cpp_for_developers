#ifndef MOVIE_LIST_CLASS_HPP_
#define MOVIE_LIST_CLASS_HPP_

#include <iostream>
#include <vector>
#include "Movie.hpp"

class MovieList {
private:
    std::vector<Movie> movies;

    static std::vector<GENRES> setGenres(std::string genresIn);
public:
    MovieList();

    void addMovie(const Movie& movie);
    std::vector<Movie>& getMovies();
};

#endif