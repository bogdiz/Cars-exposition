#ifndef COUPE_H
#define COUPE_H

#include "car.h"
class Coupe : public Car {
public:
    Coupe();
    Coupe(std::string name);
    ~Coupe();
    Coupe(const Coupe& c);

    Coupe& operator=(const Coupe& c);

    friend std::istream& operator>>(std::istream& in, Coupe& coupe);
    friend std::ostream& operator<<(std::ostream& out, Coupe& coupe);
};

#endif