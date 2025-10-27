#ifndef MOVIES_CLASS_HPP_
#define MOVIES_CLASS_HPP_

#include <iostream>
#include <vector>
#include <initializer_list>
#include <unordered_map>

enum GENRES {
    ACTION,
    ADVENTURE,
    ANIMATION,
    CHILDREN,
    COMEDY,
    CRIME,
    DOCUMENTARY,
    DRAMA,
    FANTASY,
    FILM_NOIR,
    HORROR,
    IMAX,
    MUSICAL,
    MYSTERY,
    ROMANCE,
    SCI_FI,
    THRILLER,
    WAR,
    WESTERN,
    GENRES_LEN
};

static const std::unordered_map<std::string, GENRES> genreMap {
    {"Action", ACTION},
    {"Adventure", ADVENTURE},
    {"Animation", ANIMATION},
    {"Children", CHILDREN},
    {"Comedy", COMEDY},
    {"Crime", CRIME},
    {"Documentary", DOCUMENTARY},
    {"Drama", DRAMA},
    {"Fantasy", FANTASY},
    {"Film-Noir", FILM_NOIR},
    {"Horror", HORROR},
    {"IMAX", IMAX},
    {"Musical", MUSICAL},
    {"Mystery", MYSTERY},
    {"Romance", ROMANCE},
    {"Sci-Fi", SCI_FI},
    {"Thriller", THRILLER},
    {"War", WAR},
    {"Western", WESTERN}
};

class Movie {
private:
    int id;
    std::string title;
    std::string yearOfRelease;
    std::vector<GENRES> genres;

    static void validateAttributes(const Movie& movie);
    static void validateId(int id);
    static void validateTitle(const std::string& title);
    static void validateYear(const std::string& year);
    static void validateGenres(const std::vector<GENRES>& genres);

public:
    Movie() = default;
    Movie(int id, std::string title, std::string year, std::initializer_list<GENRES> genres);
    Movie(int id, std::string title, std::string year, std::vector<GENRES> genres);
    
    void setId(int id);
    void setTitle(std::string title);
    void setYearOfRelease(std::string year);
    void setGenres(std::vector<GENRES>& genres);

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getYearOfRelease() const;
    const std::vector<GENRES>& getGenres() const;

    friend bool operator<(const Movie& a, const Movie& b);

    std::string toString() const;
};

#endif