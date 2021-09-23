#include "pickup.h"

Pickup::Pickup():Automobile() {
  haulingCapacity_ = 0;
  extendedCab_ = false;
}

Pickup::Pickup(std::string imake, std::string imodel, int iyear, double iprice,
              int istall, int h, bool ec):Automobile(imake, imodel, iyear, iprice, istall) {
  haulingCapacity_ = h;
  extendedCab_ = ec;
}

bool Pickup::park(bool lot[], int size) {
  int spot = size;
  for (int i = 0; i < size; ++i) {
    if((i != size - 1) && (!lot[i] && !lot[i+1]))
      spot = i;
  }
  if (spot >= size - 1) {
    return false;
  }
  else {
    lot[spot] = true;
    lot[spot + 1] = true;
    set_stall(spot);
    return true;
  }
}

int Pickup::haulingCapacity() {
  return haulingCapacity_;
}

bool Pickup::extendedCab() {
  return extendedCab_;
}
