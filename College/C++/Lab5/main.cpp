#include "automobile.h"
#include "pickup.h"
#include "van.h"
#include <iostream>
using namespace std;

int main() {
  bool cars1[4];
  Automobile a = Automobile("Honda", "CRV", 2020, 3.00, 1);
  a.park(cars1, 4);
  cout<<cars1[0]<<endl;

  Pickup p = Pickup("Honda", "CRV", 2019, 4.00, 1, 10, false);
  Pickup p2 = Pickup();
  cout<<p.park(cars1, 4)<<endl;

  bool cars2[4];
  Van v = Van();
  Van v2 = Van("Honda", "CRV", 2000, 5.00, 1, 5);
  cout<<v2.park(cars2, 4)<<endl;


}
