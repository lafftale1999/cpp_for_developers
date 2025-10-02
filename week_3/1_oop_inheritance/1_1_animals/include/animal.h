#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

class Animal {
private:
    std::string name;
    std::string sound;
    int age;

public:
    Animal(std::string n, std::string s, int a);

    void makeSound();
    void run();

    void setName(std::string n);
    void setSound(std::string s);
    void setAge(int a);

    const std::string& getName();
    const std::string& getSound();
    int getAge();
};

#endif