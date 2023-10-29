#include "car.h"

Car::Car() {};

Car::Car(std::string name) : name(name) {};

Car::~Car() {};

Car::Car(const Car& c) {
    this->name = c.name;
}

Car& Car::operator=(const Car& c) {
    if (this != &c) {
        this->name = c.name;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, Car& c) {
    out << c.name;
    return out;
}

std::istream& operator>>(std::istream& in, Car& c) {
    in >> c.name;
    return in;
}