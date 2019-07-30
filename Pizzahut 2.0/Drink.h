#ifndef DRINK_H
#define DRINK_H
#include "Food.h"

class Drink
{
		protected:
		string drinktype[NUMDRINKS]={"Coca-cola","Mountain Dew","Heaven & Earth","Pepsi","Mango Juice","Apple Juice"};
		double drinkprice[NUMDRINKS]={3.00,3.50,4.50,3.50,5.00,5.00};
		
	public:
		
		void display();
		double getPrice (int);
		
		string getdrinktype(int);
		~Drink(){}
};

#endif
