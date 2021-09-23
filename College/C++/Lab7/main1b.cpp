#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
  map <string, int> names;
  ifstream in;
  in.open("lab4.txt");
  if (in.fail()) {
    cout<<"Can't Open"<<endl;
    return 2;
  }
  string temp;
  while (!in.eof()) {
    getline(in, temp);
    ++names[temp];
  }
  in.close();
  ofstream out;
  out.open("output2.txt");
  for (auto e:names) {
    out<<e.first;
    out<<", ";
    out<<e.second;
    out<<endl;
  }
  out.close();
  double avgMeals;
  for(auto e:names) {
    avgMeals += e.second;
  }
  avgMeals /= names.size();
  cout<<"Average Meals per Person: ";
  cout<<avgMeals<<endl;
  return 0;
}
