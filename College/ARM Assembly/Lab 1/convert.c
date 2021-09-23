#include <stdint.h>

#include <math.h>

int32_t	Bits2Signed(int8_t bits[8])
{
  int32_t ret = 0;
  //checks whether the furthermost bit is zero, indicating if its positive
  //if it is, each value is multiplied 2^i and added to the signed int
  if (bits[7] == 0) {
    int32_t ret = 0;
    for (int i = 7; i >= 0; --i) {
      ret += bits[i]*(pow(2, i));
    }
    return ret;
  }
  //if not, the furthermost value is negatively added to the signed int,
  //and the rest of the values are added to it
  else {
    ret = -1*(pow(2,7));
    for (int i = 6; i >= 0; --i) {
      ret += bits[i]*(pow(2, i));
    }
    return ret;
  }
}

uint32_t Bits2Unsigned(int8_t bits[8])
{
  uint32_t ret = 0;
  //each value is multiplied 2^i and added to the unsigned int
  for (int i = 7; i >= 0; --i) {
    ret += bits[i]*(pow(2, i));
  }
  return ret;
}

void Increment(int8_t bits[8]) {
  //checks if the value of the nearest number equals 1
  //if so, sets value to 0 and moves on to the next number
  //if not, sets that value to 1 and breaks out of loop
  for (int i = 0; i < 8; ++i) {
    if (bits[i] == 1) {
      bits[i] = 0;
    }
    else {
      bits[i] = 1;
      break;
    }
  }
}

void Unsigned2Bits(uint32_t n, int8_t bits[8]) {
  int counter = 0;
  //uses repeated division of 2, and goes through the entire array starting at 0
  //sets the sets each value to the remainder of n/2, then sets n to n/2
  while (counter <= 7) {
    bits[counter] = n % 2;
    n = n / 2;
    ++counter;
  }
}
