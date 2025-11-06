#include "../classes/Movies.hpp"

// Container Adapters libraries
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

// Include Ranges library
#include <ranges>

// Algorithm library
#include <algorithm>

#include <utility>
#include <string>
#include <iostream>
#include <cmath>
#include <chrono>
#include <iterator>
#include <memory>
#include <functional>
#include <string_view>

class MovieRecommendation {
private:
    std::string name;

public:
    MovieRecommendation() = default;
    MovieRecommendation(std::string name) : name(name) {}

    const std::string& getName() const {
        return name;
    }

    void setName(std::string name) {
        this->name = name;
    }
};

int main(void) {
    MovieList movies = MovieList(50);
    auto& r_movies = movies.getMovies();
    
    // FILTER
    // Creates a filter to sort which object to target
    std::cout << "---------- Before movies_view ----------\n";
    auto movies_view = r_movies | std::views::filter([](const auto& m) {
        std::cout << "*f*\n";
        return m.getTitle().at(0) == 'S';
    });
    std::cout << "---------- After movies_view---------- \n";

    std::cout << "---------- Before for-loop ----------\n";
    for (auto m : movies_view) {
        std::cout << "*p*\n";
        std::cout << m.getTitle() << std::endl;
    }
    std::cout << "---------- After for-loop ----------\n";


    // TRANSFORM
    // transform into another object of choice
    auto recommendations = r_movies | std::views::filter([] (const auto& m) {
        return m.getYearOfRelease() == "1995";
    }) | std::views::transform([] (const auto& m) {
        return MovieRecommendation(m.getTitle());
    });

    for (auto r : recommendations) {
        std::cout << r.getName() << std::endl;
    }

    // REVERSE
    // reverses the view
    auto reversed_recommentations = r_movies | std::views::filter([] (const auto& m) {
        return m.getYearOfRelease() == "1995";
    }) | std::views::transform([] (const auto& m) {
        return MovieRecommendation(m.getTitle());
    }) | std::views::reverse;

    for (auto r : reversed_recommentations) {
        std::cout << r.getName() << std::endl;
    }


    // TAKE
    // Decides how many of the element in the view to stream
    auto movie_titles = r_movies | std::views::filter([](const auto& m){
        return m.getTitle().length() >= 10;
    }) | std::views::transform([](const auto& m) {
        return "Title: " + m.getTitle() + " | " + std::to_string(m.getTitle().length());
    }) | std::views::take(5);

    for (auto m : movie_titles) {
        std::cout << m << std::endl;
    }


    // CREATE NEW CONTAINER WITH RESULT FROM VIEW
    std::vector result(movies_view.begin(), movies_view.end());
    for (const auto& r : result) {
        std::cout << r.getTitle() << std::endl;
    }


    // SHORTHAND
    for (const auto& r : r_movies
        | std::views::filter([](const auto& m){ return m.getTitle().at(0) == 'T';})
        | std::views::take(10)) {
            std::cout << r.getTitle() << std::endl;
        }

    auto new_recommendation = r_movies | std::views::filter([](const auto& m){
        return
            m.getTitle().at(0) == 'S' && 
            std::ranges::any_of(m.getGenres(), [](const auto& g){ return g == GENRES::DOCUMENTARY; }) &&
            m.getYearOfRelease() == "1995";
    }) | std::views::transform([](const auto& m){
        return MovieRecommendation(m.getTitle());
    });

    auto is_match = [](const auto& m){
        const auto& title = m.getTitle();
        return
            !title.empty() && title.at(0) == 'S' &&
            m.getYearOfRelease() == "1995" &&
            std::ranges::any_of(m.getGenres(), [](const auto& g){
                return g == GENRES::DOCUMENTARY;
            });
    };

    auto to_recommendation = [](const auto& m){
        return MovieRecommendation(m.getTitle());
    };

    for (const auto& r : r_movies | 
        std::views::filter(is_match) | 
        std::views::transform(to_recommendation)) 
        {
        std::cout << r.getName() << std::endl;
    }

    return 0;
}