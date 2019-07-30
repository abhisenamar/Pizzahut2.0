#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "Pizza.h"

using namespace std;

		void Pizza::display()
		{
			cout<<endl<<"=========================================="<<endl;
			cout<<"||\t\tPizza Choice \t\t||"<<endl;
			cout<<"=========================================="<<endl;
			
			for(int n=0;n<NUMPIZZA;n++)
			{
				cout<<left<<setw(3)<<n+1<<"- "<<setw(17)<<pizzatype[n]<<right<<setw(4)<<"RM"<<fixed<<setprecision(2)<<pizzaprice[n]<<endl;
			}
			
		}
		
		void Pizza::pizzSize()
		{
			cout<<"=========================================="<<endl;
			cout<<"||\t\tPizza Size \t\t||"<<endl;
			cout<<"=========================================="<<endl;
			for(int x=0;x<NUMSIZE;x++)
			{
				cout<<left<<setw(3)<<x+1<<" - "<<setw(10)<<pizzasize[x]<<right<<setw(4)<<"- RM "<<fixed<<setprecision(2)<<pizzasizeprice[x]<<endl;
			}
		}
		double Pizza::getPrice(int n)
		{
			return pizzaprice[n-1];
		}
		double Pizza::getSize(int x)
		{
			return pizzasizeprice[x-1];
		}
		
		string Pizza::getpizzatype(int n)
		{
			return pizzatype[n-1];
		}
		
		string Pizza::getpizzasize(int n)
		{
			return pizzasize[n-1];
		}
