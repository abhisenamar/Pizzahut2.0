#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "Pasta.h"

using namespace std;

void Pasta::display()
		{
			cout<<"=================================="<<endl;
			cout<<"||\t     Pasta    \t\t||"<<endl;
			cout<<"=================================="<<endl;
			for(int i=0;i<NUMPASTA;i++)
			{
				cout<<i+1<<". "<<left<<setw(10)<<pastatype[i]<<setw(5)<<"\t\tRM"<<fixed<<setprecision(2)<<pastaprice[i]<<endl;
			}
		}
double Pasta::getPrice (int n){
			return pastaprice[n-1];
		}
		
string Pasta::getpastatype(int n)
		{
			return pastatype[n-1];
		}
