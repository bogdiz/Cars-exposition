#ifndef CABRIO_H
#define CABRIO_H

#include "car.h"

class Cabrio : public Car
{
public:
    Cabrio();
    Cabrio(std::string name);
    ~Cabrio();
    Cabrio(const Cabrio& h);

    Cabrio& operator=(const Cabrio& h);
    void print(std::ostream& out);
    void read(std::istream& in);

    friend std::istream& operator>>(std::istream& in, Cabrio& cabrio);
    friend std::ostream& operator<<(std::ostream& out, Cabrio& cabrio);
};


#endif