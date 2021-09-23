#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  vector <string> names;
  ifstream in;
  in.open("lab4.txt");
  if (in.fail()) {
    cout<<"Can't Open"<<endl;
    return 2;
  }
  string temp;
  while (!in.eof()) {
    getline(in, temp);
    names.push_back(temp);
  }
  in.close();
  ofstream out;
  out.open("output3.txt");
  for (auto e:names) {
    out<<e;
    out<<"\n";
  }
  out.close();
  cout<<"How many meals total? ";
  cout<<names.size()<<endl;
  return 0;
}
