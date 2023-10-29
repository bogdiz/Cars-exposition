#include "cabrio.h"

Cabrio::Cabrio() : Car() {};

Cabrio::Cabrio(std::string name) : Car(name) {};

Cabrio::~Cabrio() {};

Cabrio::Cabrio(const Cabrio& c) : Car(c) {};

Cabrio& Cabrio::operator=(const Cabrio& c) {
    if (this != &c)
        Car::operator=(c);
    return *this;
}

void Cabrio::print(std::ostream& out) {
    out << this->name;
}

void Cabrio::read(std::istream& in) {
    std::getline(in, name);

}

std::istream& operator>>(std::istream& in, Cabrio& cabrio){
    in >> dynamic_cast<Car&>(cabrio);
    return in;
}

std::ostream& operator<<(std::ostream& out, Cabrio& cabrio){
    out << dynamic_cast<Car&>(cabrio);
    return out;
}
