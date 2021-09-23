#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
  set <string> names;
  ifstream in;
  in.open("lab4.txt");
  if (in.fail()) {
    cout<<"Can't Open"<<endl;
    return 2;
  }
  string temp;
  while (!in.eof()) {
    getline(in, temp);
    names.insert(temp);
  }
  in.close();
  ofstream out;
  out.open("output1.txt");
  for (auto e:names) {
    out<<e;
    out<<endl;
  }
  out.close();
  cout<<"How many different people? ";
  cout<<names.size()<<endl;
  return 0;
}
