#include "biguint.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  biguint a = biguint();
  biguint b = biguint("1234");
  biguint c = biguint("1239");
  b = c + c;
  cout<<b<<endl;
  cout<<c.compare(c)<<endl;
  bool check;
  check = b > c;
  cout<<check<<endl;
  check = b < c;
  cout<<check<<endl;
  check = b == c;
  cout<<check<<endl;
  check = b <= c;
  cout<<check<<endl;
  check = c >= c;
  cout<<check<<endl;
  check = b != c;
  cout<<check<<endl;
  b -= c;
  b = c - b;
  cout<<b<<endl;
  cout<<c.toString()<<endl;
}
