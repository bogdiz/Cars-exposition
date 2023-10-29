#ifndef HOTHATCH_H
#define HOTHATCH_H

#include "car.h"

class Hothatch : public Car
{
public:
    Hothatch();
    Hothatch(std::string name);
    ~Hothatch();
    Hothatch(const Hothatch& h);

    Hothatch& operator=(const Hothatch& h);
    void print(std::ostream& out);
    void read(std::istream& in);

    friend std::istream& operator>>(std::istream& in, Hothatch& hothatch);
    friend std::ostream& operator<<(std::ostream& out, Hothatch& hothatch);
};


#endif