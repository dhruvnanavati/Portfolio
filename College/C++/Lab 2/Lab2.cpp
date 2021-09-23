#include <iostream>

using namespace std;

class ModInt
{
  int mod;
  int numValue;

public:
  ModInt();
  ModInt(int m, int nv);

  int getMod() {return mod;}
  int getNumValue() {return numValue;}

  void operator +=(ModInt rhs);
};

bool operator ==(ModInt lhs, ModInt rhs);
ModInt operator +(ModInt lhs, ModInt rhs);

int main()
{
  ModInt m1 = ModInt();
  ModInt m2 = ModInt(3, 11);
  ModInt m3 = ModInt(3, 11);
  cout<<m1.getMod()<<","<<m1.getNumValue()<<endl;
  cout<<m2.getMod()<<","<<m2.getNumValue()<<endl;

  if(m2==m3)
    cout<<"equal"<<endl;

  m3 += m2;
  cout<<m3.getNumValue()<<endl;
  cout<<m3.getMod()<<endl;

  m1 = m2 + m3;
  cout<<m1.getNumValue()<<endl;
  cout<<m1.getMod()<<endl;
};

ModInt::ModInt() {mod = 1; numValue = 0;}

ModInt::ModInt(int m, int nv) {
  mod = m;
  numValue = nv;
}

bool operator ==(ModInt lhs, ModInt rhs) {
  if((lhs.getMod() == rhs.getMod()) && (lhs.getNumValue() == rhs.getNumValue()))
    return true;
  return false;
}

void ModInt::operator +=(ModInt rhs) {
  if (mod == rhs.getMod()) {
    numValue += rhs.getNumValue();
    numValue = numValue % mod;
  }
  else {
    numValue = -1;
    mod = -1;
  }
}

ModInt operator +(ModInt lhs, ModInt rhs) {
  if (lhs.getMod() == rhs.getMod()) {
    lhs += rhs;
    return lhs;
  } else {
    ModInt ret = ModInt(-1, -1);
    return ret;
  }
}
