#include "van.h"

Van::Van():Automobile() {
  numSeats_ = 0;
}

Van::Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int s):Automobile(imake, imodel, iyear, iprice, istall) {
  numSeats_ = s;
}

bool Van::park(bool lot[], int size) {
  if (numSeats_ <= 7) {
    return Automobile::park(lot, size);
  }
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
