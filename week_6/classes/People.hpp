#ifndef PEOPLE_EXAMPLE_HPP_
#define PEOPLE_EXAMPLE_HPP_

#include <iostream>

class People {
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string gender;

public:
    People() = default;
    People(int id, std::string fn, std::string ln, std::string email, std::string gender);

    void setId(int id);
    void setFirstName(std::string fn);
    void setLastName(std::string ln);
    void setEmail(std::string email);
    void setGender(std::string gender);

    int getId() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    std::string getFullName() const;
    const std::string& getEmail() const;
    const std::string& getGender() const;
};

#endif