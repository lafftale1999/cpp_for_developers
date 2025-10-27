#include "People.hpp"
#include <regex>
#include <string>
#include <stdexcept>

static const std::regex pattern(R"(^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");

People::People(int id, std::string fn, std::string ln, std::string email, std::string gender)
: id(id), firstName(fn), lastName(ln), email(email), gender(gender) {
    validatePeople(*this);
}

void People::setId(int id) {
    validateId(id);
    this->id = id;
}

void People::setFirstName(std::string fn) {
    validateName(fn);
    firstName = fn;
}

void People::setLastName(std::string ln) {
    validateName(ln);
    lastName = ln;
}

void People::setEmail(std::string email) {
    validateEmail(email);
    this->email = email;
}

void People::setGender(std::string gender) {
    validateGender(gender);
    this->gender = gender;
}

int People::getId() const {
    return id;
}

const std::string& People::getFirstName() const {
    return firstName;
}

const std::string& People::getLastName() const {
    return lastName;
}

std::string People::getFullName() const {
    return firstName + " " + lastName;
}

const std::string& People::getEmail() const {
    return email;
}

const std::string& People::getGender() const {
    return gender;
}

static void validatePeople(const People& people) {
    validateId(people.getId());
    validateName(people.getFirstName());
    validateName(people.getLastName());
    validateEmail(people.getEmail());
    validateGender(people.getGender());
}

static void validateId(int id) {
    if (id < 0) throw std::invalid_argument("Id must be bigger than 0");
}

static void validateName(const std::string& name) {
    if (name.empty()) throw std::invalid_argument("Name can't be empty!");
}

static void validateEmail(const std::string& email) {
    if (!std::regex_match(email, pattern)) {
        throw std::invalid_argument("Not a valid email!");
    }
}

static void validateGender(const std::string& gender) {
    if (gender.compare("Male") || gender.compare("Female") || gender.compare("Non-binary")) {
        return;
    }

    throw std::invalid_argument("Gender not valid");
}