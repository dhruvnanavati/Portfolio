#include "dbiguint.h"
#include <iostream>

dbiguint::dbiguint(){
  capacity_ = 1;
  data_ = new unsigned short[capacity_];
  data_[0] = 0;
}

dbiguint::dbiguint(const std::string &s){
  int temp = 0;
  capacity_ = s.length();
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++){
    if(i < s.length()){
      temp = s[(s.length() - 1 - i)] - '0';
      data_[i] = temp;
    }
  }
}
  std::ostream& operator <<(std::ostream& out, const dbiguint& b){
    for (size_t i = b.size(); i > 0; i--){
      out << b[i-1];
    }
    return out;
}


  std::size_t dbiguint::size() const{
    return capacity_;
}

  unsigned short dbiguint::operator [](std::size_t pos) const{
    if(pos < capacity_){
      return data_[pos];
    }
    else{
      return 0;
    }
  }

  void dbiguint::reserve(std::size_t newcapacity_){

    if(newcapacity_ > capacity_){
      unsigned short *temp = new unsigned short[newcapacity_];
      for(std::size_t i = 0; i < newcapacity_; i++){
        if(i < capacity_){
          temp[i] = data_[i];
        }
        else{
          temp[i] = 0;
        }
      }
      delete [] data_;
      data_ = temp;
      temp = nullptr;
      capacity_ = newcapacity_;
    }
  }




  void dbiguint::operator += (const dbiguint &b){
    if(b.size() > capacity_){
      reserve(b.size());
    }

     for(std::size_t i = 0; i < capacity_; i++){

      if(data_[i] + b[i] > 9){
        if(i == capacity_ -1){
          reserve(capacity_ + 1);
        }
        data_[i+1] = data_[i+1] +1;
      }
      data_[i] = (data_[i] + b[i]) % 10;
    }
  }

  dbiguint::~dbiguint(){
      delete [] data_;
      data_ = nullptr;
      capacity_ = 0;
  }
  /*

    // std::ostream& operator <<(std::ostream& out, const dbiguint& b){
    //   for(std::size_t i = 0; i < dbiguint::CAPACITY ; i++){
    //     out << b[dbiguint::CAPACITY - 1 -i];
    //   }
    //   return out;
    // }
  //problem #8 of lab3: Overload + as a non-member function
  dbiguint operator + (const dbiguint &lhs, const dbiguint &rhs){
    std::string temp = "";
    for(std::size_t i = 0; i < dbiguint::CAPACITY; i++){
      if((lhs[i] + rhs[i]) > 9){
        if(i == dbiguint::CAPACITY - 1){
          std::cout << "ERROR" << std::endl;
          exit(1);
        }
        temp += ((lhs[i] + rhs[i])%10);
        temp += lhs[i+1] + 1;
      }
      else{
        temp += (lhs[i] +rhs[i]);
      }
    }
    dbiguint returns = dbiguint(temp);
    return returns;
  }

  bool operator < (const dbiguint &lhs, const dbiguint &rhs){
    std::size_t i = dbiguint::CAPACITY;
    if(lhs[(dbiguint::CAPACITY)-1] > rhs[dbiguint::CAPACITY -1]){
      return false;
      }
    else if(lhs[i-1] < rhs[i-1]){
      return true;
    }
    else {
      if(lhs == rhs){
        return false;
      }
      else{
        while(lhs[i-1] == rhs[i-1] && i > 0){
            i--;
            if(lhs[i-1] > rhs[i-1]){
              return false;
              }
            else if(lhs[i-1] == rhs[i-1]){

            }
          }
        }
      }
      return true;
    }

  bool operator <= (const dbiguint &lhs, const dbiguint &rhs){
    std::size_t i = dbiguint::CAPACITY;
    if(lhs[(dbiguint::CAPACITY)-1] > rhs[dbiguint::CAPACITY -1]){
      return false;
      }
    else if(lhs[i-1] < rhs[i-1]){
      return true;
    }
    else {
      while(lhs[i-1] == rhs[i-1] && i > 0){
          i--;
          if(lhs[i-1] > rhs[i-1]){
            return false;
            }
        }
      }
      return true;
  }

  bool operator != (const dbiguint &lhs, const dbiguint &rhs){
    int counter = 0;
    for(std::size_t i = dbiguint::CAPACITY; i>0; i--){
      if(lhs[i-1] == rhs[i-1]){
        counter++;
      }
    }
    if(counter == 20){
      return false;
    }
      return true;
  }

  bool operator == (const dbiguint &lhs, const dbiguint &rhs){
    int counter = 0;
    for(std::size_t i = dbiguint::CAPACITY; i>0; i--){
      if(lhs[i-1] == rhs[i-1]){
        counter++;
      }
    }
    if(counter == 20){
      return true;
    }
    else{
      return false;
    }
  }

  bool operator >= (const dbiguint &lhs, const dbiguint &rhs){
    std::size_t i = dbiguint::CAPACITY;
    if(lhs[(dbiguint::CAPACITY)-1] < rhs[dbiguint::CAPACITY -1]){
      return false;
      }
    else if(lhs[i-1] > rhs[i-1]){
      return true;
    }
    else {
      while(lhs[i-1] == rhs[i-1] && i > 0){
          i--;
          if(lhs[i-1] > rhs[i-1]){
            return false;
            }
        }
      }
      return true;
  }

  bool operator > (const dbiguint &lhs, const dbiguint &rhs){
    std::size_t i = dbiguint::CAPACITY;
    if(lhs[(dbiguint::CAPACITY)-1] < rhs[dbiguint::CAPACITY -1]){
      return false;
      }
    else if(lhs[i-1] > rhs[i-1]){
      return true;
    }
    else {
      if(lhs == rhs){
        return false;
      }
      else{
        while(lhs[i-1] == rhs[i-1] && i > 0){
            i--;
            if(lhs[i-1] < rhs[i-1]){
              return false;
              }
          }
        }
      }
      return true;
  }

  void dbiguint::operator -= (const dbiguint & b){
    for(std::size_t i = 0 ;i <dbiguint::CAPACITY; i++){
      if((data_[i] - b[i])<0 ){
        if(i == CAPACITY -1){
          std::cout << "ERROR" << std::endl;
          exit(1);
        }
        data_[i+1] = data_[i+1] -1;
        data_[i] = data_[i] +10;
        data_[i] = data_[i] - b[i];
      }
      data_[i] = data_[i] -b[i];
    }
  }
  dbiguint operator - (const dbiguint &lhs, const dbiguint &rhs){
    string temp;
    for(std::size_t i = 0 ;i <dbiguint::CAPACITY; i++){
      if((lhs[i] - rhs[i])<0 ){
        if(i == CAPACITY -1){
          std::cout << "ERROR" << std::endl;
          exit(1);
        }
        lhs[i+1] = lhs[i+1] -1;
        lhs[i] = lhs[i] +10;
        lhs[i] = lhs[i] - rhs[i];
      }
      lhs[i] = lhs[i] -rhs[i];
    }
  }
*/
