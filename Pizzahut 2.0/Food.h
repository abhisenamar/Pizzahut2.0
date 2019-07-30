#ifndef FOOD_H
#define FOOD_H

using namespace std;

const int NUMPIZZA=6;
const int NUMPASTA=6;
const int NUMDRINKS=6;
const int NUMSIDEDISH=3;
const int NUMSIZE=3;

class Food
{
protected :
	int Foodtype;
	double price;
	
public:
	
	Food(int,double);
	
	void setFoodtype(string ft);
	
	virtual void display()=0;
	
    ~Food(){};
};

#endif
