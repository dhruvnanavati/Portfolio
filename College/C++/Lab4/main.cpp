#include <iostream>
#include "dbiguint.h"
using namespace std;

int main(){
  dbiguint temp = dbiguint();
  dbiguint temp2 = dbiguint("17");
  dbiguint temp3 = dbiguint("999");
  cout << temp.size() << endl;
  cout << temp2.size() << endl;
  cout << temp2[0] << endl;
  cout << "========== += operation =========="<<endl;
  cout << temp2 << " + " << temp3 << " = ";
  temp2 +=temp3;
  cout << temp2 << endl;


  return 0;
}
