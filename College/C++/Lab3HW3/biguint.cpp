#include "biguint.h"
#include <iostream>

biguint::biguint() {
  for (size_type i = 0; i < CAPACITY; ++i) {
    data_[i] = 0;
  }
}

biguint::biguint(const std::string & s) { //213 string 2 = int 2
  std::string temp = "";
  for (size_type i = 0; i < s.length(); ++i) {
    temp = s[s.length() - 1 - i];
    data_[i] = std::stoi(temp);
  }
  for (size_type i = s.length(); i < CAPACITY; ++i)
    data_[i] = 0;
}

unsigned short biguint::operator [](std::size_t pos) const {
  return data_[pos];
}

std::ostream& operator <<(std::ostream& out, const biguint& b) {
  for (biguint::size_type i = 0; i < b.CAPACITY; ++i) {
    out<<b[b.CAPACITY - 1 - i];
  }
  return out;
}

void biguint::operator += (const biguint & b) {
  for (size_type i = 0; i < CAPACITY; ++i) {
    data_[i] += b[i];
    if (data_[i] > 9) {
      ++data_[i + 1];
      data_[i] %= 10;
    }
  }
}

biguint operator +(const biguint & lhs, const biguint & rhs) {
  biguint ret = lhs;
  ret += rhs;
  return ret;
}

int biguint::compare(const biguint & b) const {
  size_type i = CAPACITY - 1;
  while (i > 0 && data_[i] == b[i]) {
    --i;
  }
  if (data_[i] > b[i]) {
    return 1;
  }
  else if (data_[i] < b[i])
  {
    return -1;
  }
  else {
    return 0;
  }
}

bool operator < (const biguint & lhs, const biguint & rhs) {
  if (lhs.compare(rhs) == -1)
    return true;
  return false;
}

bool operator <= (const biguint & lhs, const biguint & rhs) {
  if (lhs.compare(rhs) <= 0)
    return true;
  return false;
}

bool operator > (const biguint & lhs, const biguint & rhs) {
  if (lhs.compare(rhs) == 1)
    return true;
  return false;
}

bool operator >= (const biguint & lhs, const biguint & rhs) {
  if (lhs.compare(rhs) >= 0)
    return true;
  return false;
}

bool operator == (const biguint & lhs, const biguint & rhs) {
  if (lhs.compare(rhs) == 0)
    return true;
  return false;
}

bool operator != (const biguint & lhs, const biguint & rhs) {
  if (lhs.compare(rhs) != 0)
    return true;
  return false;
}

void biguint::operator -= (const biguint & b) {
  int temp = 0;
  for (size_type i = 0; i < CAPACITY; i++) {
    temp = data_[i];
    temp -= b[i];
    if (temp < 0) {
      data_[i] = (data_[i] + 10) - b[i];
      --data_[i + 1];
    }
    else {
      data_[i] -= b[i];
    }
  }
}

biguint operator - (const biguint & lhs, const biguint & rhs) {
  biguint ret = lhs;
  ret -= rhs;
  return ret;
}

std::string biguint::toString() {
  std::string ret;
  size_type i = CAPACITY - 1;
  while (data_[i] == 0) {
    --i;
  }
  char temp = '0';
  for (; i > 0; --i) {
    temp += data_[i];
    ret += temp;
    temp = '0';
  }
  temp += data_[i];
  ret += temp;
  return ret;
}
