#include "supersport.h"

Supersport::Supersport() : Car() {};

Supersport::Supersport(std::string name) : Car(name) {};

Supersport::~Supersport() {};

Supersport::Supersport(const Supersport& c) : Car(c) {};

Supersport& Supersport::operator=(const Supersport& c) {
    if (this != &c)
        Car::operator=(c);
    return *this;
}

void Supersport::print(std::ostream& out) {
    out << this->name;
}

void Supersport::read(std::istream& in) {
    std::getline(in, name);
}

std::istream& operator>>(std::istream& in, Supersport& supersport){
    in >> dynamic_cast<Car&>(supersport);
}

std::ostream& operator<<(std::ostream& out, Supersport& supersport){
    out << dynamic_cast<Car&>(supersport);
}