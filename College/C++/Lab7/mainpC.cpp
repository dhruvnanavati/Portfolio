#include <iostream>

using namespace std;

int salary(int n) {
  if (n == 1) {
    return 50;
  }
  else if (n < 1) {
    return 0;
  }
  else {
    return (salary(n - 1) * 1.1 + 5);
  }
}

int main() {
  cout<<salary(2)<<endl;
  return 0;
}
