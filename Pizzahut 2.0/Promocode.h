#include <iostream>
#include <string>
using namespace std;

#ifndef PROMOCODE_H
#define PROMOCODE_H

class Promocode
{
private:
    string pcode;
    
public:
    Promocode (string pc);
    string getPromocode();
    
    void setPromoCode(string pc);
    
    int printCode(string pc);
};

#endif
