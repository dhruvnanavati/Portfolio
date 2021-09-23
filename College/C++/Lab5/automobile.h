#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
class Automobile
{
public:
    Automobile();
    Automobile(std::string imake, std::string imodel, int iyear, double iprice, int istall);
    bool park(bool lot[], int size);
    std::string make(){return make_;}
    std::string model(){return model_;}
    int year(){return year_;}
    double price(){return price_;}
    int stall(){return stall_;}
    void set_stall(int s){stall_ = s;}
private:
    std::string make_;
    std::string model_;
    int year_;
    double price_;
    int stall_;
};




#endif // AUTOMOBILE_H
