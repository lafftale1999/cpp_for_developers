#include <iostream>
#include <vector>

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual void move(float distance) = 0;
};

class Motor {
public:
    virtual ~Motor() = default;
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
};

class Car : public Vehicle, public Motor {
public:
    void startEngine() override {
        // Engine starts
    }

    void stopEngine() override {
        // Engine stops
    }

    void move(float distance) override {
        // Moves a certain distance
    }
};

class Bicycle : public Vehicle {
public:
    void move(float distance) override {
        // Bicycle moves
    }
};

int main(void) {

    // Creating Car object
    Car car = Car();
    car.startEngine();
    car.move(250);
    car.stopEngine();
    
    // Creating Bicycle object
    Bicycle bike = Bicycle();
    bike.move(250);

    // Display of polymorphic behaviour
    std::vector<Vehicle*> vehicles = {&car, &bike};
    for (const auto& v : vehicles) {
        v->move(250);
    }

    return 0;
}

