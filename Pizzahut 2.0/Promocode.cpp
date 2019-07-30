#include <iostream>
#include <string>
#include "Promocode.h"
using namespace std;

Promocode::Promocode (string pc){pcode=pc;}
string Promocode::getPromocode() {return pcode;}
    
void Promocode::setPromoCode(string pc){pcode=pc;}
    
int Promocode::printCode(string pc)
{
	pcode=pc;
	
       if((pcode=="A123")||(pcode=="B123")||(pcode=="C123")) // promo code are set to: A123, B123, C123
       {
           cout<<"Congratulation! You get an extra 20% OFF!!!"<<endl;
           return 1;
       }
       else{
           cout<<"Your Promo Code is INVALID :( "<<endl<<endl;
           return 2;
       }
       
}
