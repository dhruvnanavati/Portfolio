#include <iostream>
#include "bag10.h"

using namespace std;
int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  bag<int> a(arr, 5);
  for (auto e:a) {
    cout<<e<<" ";
  }
  cout<<endl;
  bag<int>::iterator i;
  for (i = a.begin(); i != a.end(); ++i) {
    cout<<*(i)<<" ";
  }
  cout<<endl;
  return 0;
}
