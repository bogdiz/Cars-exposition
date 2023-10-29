#include "coupe.h"

Coupe::Coupe() : Car() {};

Coupe::Coupe(std::string name) : Car(name) {};

Coupe::~Coupe() {};

Coupe::Coupe(const Coupe& c) : Car(c) {};

Coupe& Coupe::operator=(const Coupe& c) {
    if (this != &c)
        Car::operator=(c);
    return *this;
}

std::istream& operator>>(std::istream& in, Coupe& coupe){
    in >> dynamic_cast<Car&>(coupe);
    return in;
}

std::ostream& operator<<(std::ostream& out, Coupe& coupe){
    out << dynamic_cast<Car&>(coupe);
    return out;
}