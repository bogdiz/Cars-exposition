#ifndef SUPERSPORT_H
#define SUPERSPORT_H

#include "car.h"

class Supersport : public Car
{
public:
    Supersport();
    Supersport(std::string name);
    ~Supersport();
    Supersport(const Supersport& h);

    Supersport& operator=(const Supersport& h);
    void print(std::ostream& out);
    void read(std::istream& in);

    friend std::istream& operator>>(std::istream& in, Supersport& supersport);
    friend std::ostream& operator<<(std::ostream& out, Supersport& supersport);
};


#endif