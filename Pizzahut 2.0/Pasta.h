#ifndef PASTA_H
#define PASTA_H
#include "Food.h"

class Pasta
{
		protected:
		string pastatype[NUMPASTA]={"Carbonara","Bolognese","Aglio Olio","Marina","Alfredo","Brown Butter"};
		double pastaprice[NUMPASTA]={10.30,11.80,13.50,12.40,10.30,12.50};
		
	public:

		void display();
		double getPrice (int);
		string getpastatype(int);
		~Pasta(){	}
};

#endif
