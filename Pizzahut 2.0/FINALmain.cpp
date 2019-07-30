#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>

#include "Food.h"
#include "Promocode.h"
#include "LocationGps.h"
#include "Pizza.h"
#include "Drink.h"
#include "Pasta.h"
#include "Sidedish.h"

using namespace std;

class FoodEx {};

int AccountSystem()
{
	string username;
	string password;
	ifstream in;
	ofstream out;
	char ans,ans1;
	int trigger=0;
	int returnval;
	
	in.open("database.txt");
	
	cout<<"Do you have Member Card?(Y/N) ==> ";
	cin>>ans;
	
	string arru[1000];
	string arrp[1000];
	int count;
	
	in>>count;
	
		if(ans=='Y'||ans=='y')
		{
			cout<<endl<<"Enter your data below!"<<endl;
			
			while(trigger==0)
			{
				cout<<"Username= ";
				cin>>username;
				//u.setUsername(username);
				
				cout<<"Password= ";
				cin>>password;
				
				for(int i=0;i<count;i++)
				{
					in>>arru[i];
					in>>arrp[i];
					
					if((username==arru[i])&&(password==arrp[i]))
					{
						trigger=1;
					}
				}
				
				if(trigger==0)
				{
					cout<<endl<<"*Incorrect password,try again!!*"<<endl<<endl;
				}
			}
			
			in.close();
			
			cout<<endl<<"Welcome "<<username<<",let's proceed to your order."<<endl;
				
			returnval=1;
				
			return returnval;
		}
		
		else
		{	
			cout<<"Would you like to create a member account for a special discount? (Y/N) ==> ";
			cin>>ans1;
			
			cout<<endl;
			
			for(int i=0;i<count;i++)
			{
				in>>arru[i];
				in>>arrp[i];
			}
			
			in.close();
			
			out.open("database.txt");
			cout<<endl;
			string newuser="";
			string newpass="";
			
			if(ans1=='y'||ans1=='Y')
			{	
				cout<<"****************************************************"<<endl;
				cout<<"*          Welcome to Our Registration Page        *"<<endl;
				cout<<"****************************************************"<<endl<<endl;
			
				cout<<"Please enter your: "<<endl<<"New username ==> ";
				cin>>newuser;
				
				cout<<"New Password ==> ";
				cin>>newpass;
				
				cout<<endl;
				
				out<<count+1<<endl;
				
				for(int n=0;n<count;n++)
				{
					out<<arru[n]<<endl;
					out<<arrp[n]<<endl;
				}
				out<<newuser<<endl;
				out<<newpass<<endl;
				
				out.close();
				
				cout<<"****************************************************"<<endl;
				cout<<"CONGRATULATION!!Your registration has completed!"<<endl;
				cout<<"****************************************************"<<endl<<endl;
							
				cout<<"Welcome "<<newuser<<",let's proceed to your order."<<endl;
				
				returnval=1;
				
				return returnval;
			}
			
			else
			{
				returnval=2;
				
				cout<<"Welcome GUEST,let's proceed to your order."<<endl;
				return returnval;
			}
		}
}

string delivery()
{
	LocationGps loc;
    int ansGps;
    string location="a";
    
    do{
        cout<<"Allow GPS? (1- yes/ 2- No): ";
        cin>>ansGps;
        cin.ignore();
    
        if (ansGps==1)
        {
        	location=loc.printloc(loc);
            return location;
        }
        else if (ansGps==2)
        {
        	cout<<endl;
        	cout<<"*WARNING*";
        	cout<<endl<<"You have to allow GPS for delivery service!"<<endl;
        	location=loc.printloc(loc);
        	return location;
        }
        else{
            cout<<endl<<"INVALID"<<endl<<endl;
        }
    }while (ansGps>2||ansGps<=0);
}

int main()
{	
	int discounttrigger;
	int promotrigger;
	int deliverytrigger;
	int promochoice;
	string receivername;
	string address="";
	string temppc;
	//Usern u;
	
	cout<<"--------------------------";
	cout<<"\n||\t Welcome!\t||";
	cout<<"\n||\tEZAFA PIZZA\t||";
	cout<<"\n--------------------------";
	cout<<endl<<endl;
	
	B:
		cout<<"Would you like delivery or not?(1-Yes,2-no) ==> ";
		cin>>deliverytrigger;
		
		try {
			if (deliverytrigger!=1 && deliverytrigger!=2)
			throw FoodEx();
		}
	
		catch (FoodEx){
			cout<<"\nChoice entered is not accepted!"<<endl<<endl;
			goto B;
		}
		
		if(deliverytrigger==1)
		{
			cout<<"Enter the receiver's name: ";
			
			cin.ignore();
			getline(cin,receivername);
		}

		
	
	discounttrigger=AccountSystem();
	
	if(discounttrigger==1)
	{
		cout<<"Do you have a promo code? (1-Yes/2-No) ==>";
		cin>>promochoice;
		
		if(promochoice==1)
		{
			cout<<"Enter a promocode ==> ";
			cin.ignore();
			cin>>temppc;
		
			cout<<endl;
		
			Promocode promo(temppc);
		
			promotrigger=promo.printCode(temppc);
		}
		else
		{
			promotrigger=3;
		}
		
	}
	else
	{
		promotrigger=3;
	}
	
	ofstream out;
	out.open("Receipt.txt");
	int choice;
	char opt;
	double total=0.0;
	char again;
	
	int countP,countS,countD,countPa,countSD;
	
	countP=0;
	countS=0;
	countD=0;
	countPa=0;
	countSD=0;
	
	Pizza p;
	Drink d;
	Pasta pst;
	Sidedish sd;
	
	double orderP[countP];
	double orderS[countS];
	double orderD[countD];
	double orderPa[countPa];
	double orderSD[countSD];
	
	do
	{
	
		X:
				
		double tot=0.0;
		
		cout<<"\n\nWould you like to order?\n";
	
		cout<<"1. Pizza\n2. Drinks\n3. Pasta\n4. Side dish\n5. Exit"<<endl<<endl;
		cout<<"Order : ";
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			{
				Y:
				
				p.display();
				cout<<endl<<"0  - BACK"<<endl;
				
				int pizz, size;
				
				cout<<endl<<"Your Choice ==> ";
				cin>>pizz;
				
				while(pizz>NUMPIZZA||pizz<0)
				{
					cout<<"Such Pizza doesnt exist!!"<<endl;
					cout<<endl<<"Your Choice ==> ";
					cin>>pizz;
				}
				
				if(pizz==0)
				{
					goto X;
				}
				
				tot+=p.getPrice(pizz);
				
				p.pizzSize();
				cout<<endl<<"9  - BACK TO PIZZA"<<endl;
				cout<<"0  - BACK"<<endl;
				
				cout<<endl<<"Your Choice ==> ";
				cin>>size;
				
				if(size==9)
				{
					goto Y;
				}
				
				while(size>NUMSIZE||size<0)
				{
					cout<<"Such Pizza size doesnt exist!!"<<endl;
					cout<<endl<<"Your Choice ==> ";
					cin>>size;
				}
				
				if(size==0)
				{
					goto X;
				}
				else
				{
					tot+=p.getSize(size);
				
					total+=tot;
				
					countP+=1;
					countS+=1;
				
					orderP[countP-1]=pizz;
					orderS[countS-1]=size;
				}
				
				break;			
			}
		case 2:
			{
				d.display();
				cout<<endl<<"0  - BACK"<<endl;
				int dr;
				
				cout<<endl<<"Your Choice ==> ";
				cin>>dr;
				
				while(dr>NUMDRINKS||dr<0)
				{
					cout<<"Such Drink doesnt exist!!"<<endl;
					cout<<endl<<"Your Choice ==> ";
					cin>>dr;
				}
				
				if(dr==0)
				{
					goto X;
				}
				
				tot+=d.getPrice(dr);
				total+=tot;
				
				countD+=1;
				
				orderD[countD-1]=dr;
				
				break;
			}
		case 3:
			{
				pst.display();
				cout<<endl<<"0  - BACK"<<endl;
				int pta;
				
				cout<<endl<<"Your Choice ==> ";
				cin>>pta;
				
				while(pta>NUMPASTA||pta<0)
				{
					cout<<"Such Pasta doesnt exist!!"<<endl;
					cout<<endl<<"Your Choice ==> ";
					cin>>pta;
				}
				
				if(pta==0)
				{
					goto X;
				}
				
				tot+=pst.getPrice(pta);
				total+=tot;
				
				countPa+=1;
				
				orderPa[countPa-1]=pta;
				
				break;
			}
		case 4:
			{
				sd.display();
				cout<<endl<<"0  - BACK"<<endl;
				int s;
				
				cout<<endl<<"Your Choice ==> ";
				cin>>s;
				
				while(s>NUMSIDEDISH||s<0)
				{
					cout<<"Such Side Dish doesnt exist!!"<<endl;
					cout<<endl<<"Your Choice ==> ";
					cin >>s;
				}
				
				if(s==0)
				{
					goto X;
				}
				
				tot+=sd.getPrice(s);
				total+=tot;
				
				countSD+=1;
				
				orderSD[countSD-1]=s;
				
				break;
			}
		case 5:
			{
				A:
				
				cout<<endl<<endl;
				out<<"\tPRINTED RECEIPT\n\n";
				out<<"\tEZAFA PIZZA\n\t0761,Jalan Payung Tembus,\n\tSkudai,81310\n\tJohor Bharu\n\n";
				out<<"\twww.ezafapizzaawesome.com\n\n";	
				out<<"CUSTOMER INFORMATION : "<<endl;
				out<<"Name : "<<receivername;
				out<<endl<<endl;
				cout<<"========================================"<<endl;
				out<<"========================================"<<endl;
				cout<<"||             Your Order             ||"<<endl;
				out<<"||             Your Order            ||"<<endl;
				cout<<"========================================"<<endl;
				out<<"========================================"<<endl;
				
				if(countP>0)
				{
					cout<<endl<<"The Pizza: "<<endl;
					out<<endl<<"The Pizza: "<<endl;
				}
				
				for(int n=0;n<countP;n++)
				{
					cout<<n+1<<". "<<p.getpizzatype(orderP[n])<<" - "<<p.getpizzasize(orderS[n])<<
					" - RM "<<fixed<<setprecision(2)<<p.getPrice(orderP[n])+p.getSize(orderS[n])<<endl;
					
					out<<n+1<<". "<<p.getpizzatype(orderP[n])<<" - "<<p.getpizzasize(orderS[n])<<
					" - RM "<<fixed<<setprecision(2)<<p.getPrice(orderP[n])+p.getSize(orderS[n])<<endl;
				}
				
				if(countD>0)
				{
					cout<<endl<<"The Drink: "<<endl;
					out<<endl<<"The Drink: "<<endl;
				}
				
				for(int i=0;i<countD;i++)
				{
					cout<<i+1<<". "<<d.getdrinktype(orderD[i])<<" - RM "<<fixed<<setprecision(2)<<d.getPrice(orderD[i])<<endl;
					out<<i+1<<". "<<d.getdrinktype(orderD[i])<<" - RM "<<fixed<<setprecision(2)<<d.getPrice(orderD[i])<<endl;
				}
				
				if(countPa>0)
				{
					cout<<endl<<"The Pasta: "<<endl;
					out<<endl<<"The Pasta: "<<endl;
				}
				
				for(int j=0;j<countPa;j++)
				{
					cout<<j+1<<". "<<pst.getpastatype(orderPa[j])<<" - RM "<<fixed<<setprecision(2)<<pst.getPrice(orderPa[j])<<endl;
					out<<j+1<<". "<<pst.getpastatype(orderPa[j])<<" - RM "<<fixed<<setprecision(2)<<pst.getPrice(orderPa[j])<<endl;
				}
				
				if(countSD>0)
				{
					cout<<endl<<"The Side Dish: "<<endl;
					out<<endl<<"The Side Dish: "<<endl;
				}
				
				for(int k=0;k<countSD;k++)
				{
					cout<<k+1<<". "<<sd.getsdtype(orderSD[k])<<" - RM "<<fixed<<setprecision(2)<<sd.getPrice(orderSD[k])<<endl;
					out<<k+1<<". "<<sd.getsdtype(orderSD[k])<<" - RM "<<fixed<<setprecision(2)<<sd.getPrice(orderSD[k])<<endl;
				}
				
				if(discounttrigger==2)
				{
					cout<<endl<<"Total = RM "<<fixed<<setprecision(2)<<total<<endl<<endl;
					out<<endl<<"Total = RM "<<fixed<<setprecision(2)<<total<<endl<<endl;
				}
				
				else
				{
					cout<<endl<<"Being a member, enjoy a 15% discount on the total price!"<<endl;
					out<<endl<<"Being a member, enjoy a 15% discount on the total price!"<<endl;
					
					cout<<endl<<"Total = RM "<<fixed<<setprecision(2)<<total*0.85<<endl<<endl;
					out<<endl<<"Total = RM "<<fixed<<setprecision(2)<<total*0.85<<endl<<endl;
					
					if(promotrigger==1)
					{
						cout<<endl<<"Being a member with promo, enjoy a 15%+20% discount on the total price!"<<endl;
						out<<endl<<"Being a member with promo, enjoy a 15%+20% discount on the total price!"<<endl;
					
						cout<<endl<<"Total = RM "<<fixed<<setprecision(2)<<(total*0.85)*0.80<<endl<<endl;
						out<<endl<<"Total = RM "<<fixed<<setprecision(2)<<(total*0.85)*0.80<<endl<<endl;
					}
				}
				
				if(deliverytrigger==1)
				{
					address=delivery();
					cout<<endl<<endl<<"The items above will be delivered to "<<address<<" expect us the food in 30 minutes!"<<endl<<" An additional RM2.50 will be charged for the delivery service."<<endl;
					out<<endl<<endl<<"The items above will be delivered to "<<address<<" expect us the food in 30 minutes!"<<endl<<" An additional RM2.50 will be charged for the delivery service."<<endl;
				}
				out<<endl<<"Thanks for purchasing our product!\nYou are welcome to come again!";
				return 0;
				
				break;
		}
		default:
			{
				cout<<"\nOops! number is not in the menu. try again";
				cout<<"\nwould you like to order?\n";
				cout<<"1. Pizza\n2. Drinks\n3. Pasta\n4. Side dish\n5. Exit"<<endl;
				cin>>choice;
				switch(choice);
			}
		}	
		cout<<"Total = RM "<<total<<endl<<endl;
		cout<<"You want to order anything else? (Y/N)"<<endl;
		cout<<"Choice ==> ";
		
		try 
		{
			cin>>again;
			if (again!='Y'&& again!='y' && again!='N'&& again!='n')
				throw FoodEx();
		}
		
		catch (FoodEx)
		{
			cout <<"\nChoice entered is not accepted"<<endl;
		}
		
		
		if(again=='n'||again=='N')
		{
			goto A;
		}
		
	}while (again=='Y'||again=='y');
	
	out.close();
	
	return 0;
}


