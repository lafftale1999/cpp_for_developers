#include "Movies.hpp"

#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cstdint>

#define MOVIE_FILE_PATH "../resources/movies.csv"

enum MoviesCSVHeaders {
    H_ID,
    H_TITLE,
    H_YEAR,
    H_GENRES,
    HEADERS_COUNT
};

MovieList::MovieList(size_t moviesWanted) {
    std::ifstream file(MOVIE_FILE_PATH);

    if (!file.is_open()) {
        throw std::runtime_error("Movie filepath does not exist");
    }

    std::string line;
    std::string fields[HEADERS_COUNT];
    std::string raw_headers;

    std::getline(file, raw_headers);

    int exceptions_count = 0;
    while(std::getline(file, line) && movies.size() < moviesWanted) {
        try {
            std::istringstream ss(line);
            std::string token;
            uint8_t fields_index = 0;

            while(std::getline(ss, token, ',')) {
                /* token.erase(std::remove_if(token.begin(), token.end(), [](const unsigned char c) {
                    return std::isspace(c);
                }), token.end()); */

                if(fields_index >= HEADERS_COUNT) throw std::runtime_error("Error parsing line: " + line + "\nOn token: " + token);
                
                fields[fields_index++] = token;
            }
            
            int id = std::stoi(fields[H_ID]);
            std::vector<GENRES> g = setGenres(fields[H_GENRES]);

            movies.emplace_back(Movie(id, std::move(fields[H_TITLE]), std::move(fields[H_YEAR]), std::move(g)));
        } catch (const std::exception& e) {
            std::cout << "Exception thrown while reading file on line: " << line << " | Error thrown: " << e.what() << std::endl;
            exceptions_count++;
            continue;
        }
    }

    std::cout << "File is read! Exceptions thrown: " << exceptions_count << std::endl;
}

void MovieList::addMovie(const Movie& movie) {
    movies.emplace_back(movie);
}

// IN REAL WORLD APPLICATIONS THIS SHOULD BE A CONST FOR READ ONLY
std::vector<Movie>& MovieList::getMovies() {
    return movies;
}

std::vector<GENRES> MovieList::setGenres(std::string genresIn) {    
    std::vector<GENRES> result;
    std::istringstream ss(genresIn);
    std::string temp;

    while(std::getline(ss, temp, '|')) {
        temp.erase(std::remove_if(temp.begin(), temp.end(), [](const unsigned char c) {
            return std::isspace(c);
        }), temp.end());

        auto it = genreMap.find(temp);
        if (it != genreMap.end()) result.push_back(it->second);
        else continue;
    }
    
    return result;
}