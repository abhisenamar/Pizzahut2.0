#ifndef PIZZA_H
#define PIZZA_H
#include "Food.h"

using namespace std;

class Pizza
{
	protected:
		string pizzatype[NUMPIZZA]={"Hawaian","Tuna","Paperoni","Parmesan Cheese","Veggie Lover","Aloha Chicken"};
		double pizzaprice[NUMPIZZA]={10.00,13.60,15.30,14.50,11.60,19.80};
		string pizzasize[NUMSIZE]={"Personal","Regular","Large"};
		double pizzasizeprice[NUMSIZE]={0.00,5.00,15.00};
		
	public:
		
		void display();
		
		void pizzSize();
		
		double getPrice(int);
		
		double getSize(int);
		
		string getpizzatype(int);
		
		string getpizzasize(int);
		
		~Pizza(){}
};

#endif
