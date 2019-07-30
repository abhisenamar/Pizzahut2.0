#ifndef SIDEDISH_H
#define SIDEDISH_H
#include "Food.h"

using namespace std;

class Sidedish
{
		protected:
		string sdtype[NUMSIDEDISH]={"Salad","Mashpotato","Wedges"};
		double sdprice[NUMSIDEDISH]={5.39,4.35,6.73};
		
	public:
		void display();
		
		double getPrice (int);
		
		string getsdtype(int);
		
		~Sidedish(){}
};

#endif
