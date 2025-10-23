#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>

class Animal {
private:
    std::string name;
    std::string sound;
    int age;

public:
    Animal() = default;
    Animal(std::string n, std::string s, int a);

    void makeSound();

    void setName(std::string n);
    void setSound(std::string s);
    void setAge(int a);

    std::string getName();
    std::string getSound();
    int getAge() const;
};

#endif