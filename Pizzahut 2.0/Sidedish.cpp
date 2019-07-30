#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "Sidedish.h"

using namespace std;

void Sidedish::display()
		{
			cout<<"=================================="<<endl;
			cout<<"||\t   Side Dish  \t\t||"<<endl;
			cout<<"=================================="<<endl;
			
			for(int i=0;i<NUMSIDEDISH;i++)
			{
				cout<<i+1<<". "<<sdtype[i]<<"\t\tRM"<<fixed<<setprecision(2)<<sdprice[i]<<endl;
			}
		}
double Sidedish::getPrice (int n){
			return sdprice[n-1];
		}
		
string Sidedish::getsdtype(int n)
		{
			return sdtype[n-1];
		}
		
