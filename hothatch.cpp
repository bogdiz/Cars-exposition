#include "hothatch.h"

Hothatch::Hothatch() : Car() {};


Hothatch::Hothatch(std::string name) : Car(name) {};

Hothatch::~Hothatch() {};

Hothatch::Hothatch(const Hothatch& h) : Car(h) {};

Hothatch& Hothatch::operator=(const Hothatch& h) {
    if (this != &h)
        Car::operator=(h);
    return *this;
}

void Hothatch::print(std::ostream& out) {
    out << this->name;
}

void Hothatch::read(std::istream& in) {
    std::getline(in, name);

}

std::istream& operator>>(std::istream& in, Hothatch& hothatch){
    in >> dynamic_cast<Car&>(hothatch);
}

std::ostream& operator<<(std::ostream& out, Hothatch& hothatch){
    out << dynamic_cast<Car&>(hothatch);
}