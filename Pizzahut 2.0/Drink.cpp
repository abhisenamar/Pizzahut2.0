#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "Drink.h"

using namespace std;

void Drink::display()
		{
			cout<<"=================================="<<endl;
			cout<<"||\t     Drinks    \t\t||"<<endl;
			cout<<"=================================="<<endl;
			for(int i=0;i<NUMDRINKS;i++)
			{
				cout<<i+1<<". "<<left<<setw(15)<<drinktype[i]<<setw(5)<<"\tRM"<<fixed<<setprecision(2)<<drinkprice[i]<<endl;
			}
		}

double Drink::getPrice (int n){
			return drinkprice[n-1];
		}
		
string Drink::getdrinktype(int n)
		{
			return drinktype[n-1];
		}
