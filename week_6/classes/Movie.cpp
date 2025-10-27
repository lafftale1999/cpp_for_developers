#include "Movie.hpp"

#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <string>

Movie::Movie(int id, std::string title, std::string year, std::initializer_list<GENRES> genres)
: id(id), title(title), yearOfRelease(year), genres(genres) {
    validateAttributes(*this);
}

Movie::Movie(int id, std::string title, std::string year, std::vector<GENRES> genres)
: id(id), title(title), yearOfRelease(year), genres(genres) {
    validateAttributes(*this);
}

void Movie::setId(int id) {
    validateId(id);
    this->id = id;
}

void Movie::setTitle(std::string title) {
    validateTitle(title);
    this->title = std::move(title);
}

void Movie::setYearOfRelease(std::string year) {
    validateYear(year);
    yearOfRelease = std::move(year);
}

void Movie::setGenres(std::vector<GENRES>& genres) {
    validateGenres(genres);
    this->genres = genres;
}

int Movie::getId() const {
    return id;
}

const std::string& Movie::getTitle() const {
    return title;
}

const std::string& Movie::getYearOfRelease() const {
    return yearOfRelease;
}

const std::vector<GENRES>& Movie::getGenres() const {
    return genres;
}

std::string Movie::toString() const {
    std::string id = std::to_string(this->id);

    return id + " | " + title + " | " + yearOfRelease + '\n';
}

void Movie::validateAttributes(const Movie& movie) {
    validateId(movie.getId());
    validateTitle(movie.getTitle());
    validateYear(movie.getYearOfRelease());
    validateGenres(movie.getGenres());
}

void Movie::validateId(int id) {
    if (id < 0) throw std::invalid_argument("Invalid id: " + std::to_string(id));
}

void Movie::validateTitle(const std::string& title) {
    if (title.empty()) throw std::invalid_argument("Invalid movie title");
}

void Movie::validateYear(const std::string& year) {
    if (year.length() != 4) throw std::invalid_argument("Invalid year, needs 4 digits");
    if (year.at(0) != '1' || (year.at(1) != '9' && year.at(1) != '2')) throw std::invalid_argument("Invalid year, needs to be from the 1900s or 2000s");
    if (std::any_of(year.begin(), year.end(), [] (const char& c) {
        return !std::isdigit(static_cast<unsigned char>(c));
    })) throw std::invalid_argument("Invalid year, needs to be digits");
}

void Movie::validateGenres(const std::vector<GENRES>& genres) {
    if (genres.empty()) throw std::invalid_argument("Invalid genres, no genres entered");
    if (std::any_of(genres.begin(), genres.end(), [] (const GENRES& g) {
        return g < 0 || g >= GENRES_LEN;
    })) throw std::invalid_argument("Unkown genre entered");
}

bool operator<(const Movie& a, const Movie& b) {
    return a.getTitle() < b.getTitle();
}