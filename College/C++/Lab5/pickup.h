#ifndef PICKUP_H
#define PICKUP_H
#include "automobile.h"

class Pickup: public Automobile
{
public:
    Pickup();
    Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int h, bool ec);

    bool park(bool lot[], int size);

    int haulingCapacity();
    bool extendedCab();


private:
    int haulingCapacity_;
    bool extendedCab_;
};

#endif
