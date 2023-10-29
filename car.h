#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Car
{
protected:
    std::string name;
public:
    Car();
    Car(std::string name);
    Car(const Car& c);
    virtual ~Car();

    Car& operator=(const Car& c);
    friend std::ostream& operator<<(std::ostream& out, Car& c);
    friend std::istream& operator>>(std::istream& in, Car& c);

};

#endif