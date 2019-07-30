#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int NUMPIZZA=6;
const int NUMPASTA=3;
const int NUMDRINKS=3;
const int NUMSIDEDISH=3;
const int NUMSIZE=3;

class Food
{
protected :
	int Foodtype;
	double price;
	
public:
	Food(int _Foodtype=0,double _price=0.0){
		Foodtype=_Foodtype;
		price=_price;
	}
	void setFoodtype(string ft)
	{

	}
	
	virtual void display()=0;
    ~Food(){};
};

class Pizza:public Food
{
	protected:
		string pizzatype[NUMPIZZA]={"Hawaian","Tuna","Paperoni","Parmesan Cheese","Veggie Lover","Aloha Chicken"};
		double pizzaprice[NUMPIZZA]={10.00,13.60,15.30,14.50,11.60,19.80};
		string pizzasize[NUMSIZE]={"Personal","Regular","Large"};
		double pizzasizeprice[NUMSIZE]={0.00,5.00,15.00};
		
	public:
//		Pizza(string type=" ",double prc=0.0){
//			pizzatype[3]=type;
//			pizzaprice[3]=prc;
//		}
		
		void display()
		{
			cout<<endl<<"=========================================="<<endl;
			cout<<"||\t\tPizza Choice \t\t||"<<endl;
			cout<<"=========================================="<<endl;
			
			for(int n=0;n<NUMPIZZA;n++)
			{
				cout<<left<<setw(3)<<n+1<<"- "<<setw(17)<<pizzatype[n]<<right<<setw(4)<<"RM"<<fixed<<setprecision(2)<<pizzaprice[n]<<endl;
			}
			
		}
		
		void pizzSize()
		{
			cout<<"=========================================="<<endl;
			cout<<"||\t\tPizza Size \t\t||"<<endl;
			cout<<"=========================================="<<endl;
			for(int x=0;x<NUMSIZE;x++)
			{
				cout<<left<<setw(3)<<x+1<<" - "<<setw(10)<<pizzasize[x]<<right<<setw(4)<<"- RM "<<fixed<<setprecision(2)<<pizzasizeprice[x]<<endl;
			}
		}
		double getPrice(int n)
		{
			return pizzaprice[n-1];
		}
		double getSize(int x)
		{
			return pizzasizeprice[x-1];
		}
		
		string getpizzatype(int n)
		{
			return pizzatype[n-1];
		}
		
		string getpizzasize(int n)
		{
			return pizzasize[n-1];
		}
		
		~Pizza(){}
};

class Drink:public Food
{
		protected:
		string drinktype[NUMDRINKS]={"Coca-cola","Mountain Dew","Heaven & Earth"};
		double drinkprice[NUMDRINKS]={43.8,32.4,89.6};
		
	public:
//		Drink(string type=" ",double prc=0.0){
//			drinktype[3]=type;
//			drinkprice[3]=prc;
//		}
		
		void display()
		{
			cout<<"=================================="<<endl;
			cout<<"||\t     Drinks    \t\t||"<<endl;
			cout<<"=================================="<<endl;
			for(int i=0;i<NUMDRINKS;i++)
			{
				cout<<i+1<<". "<<left<<setw(15)<<drinktype[i]<<setw(5)<<"\tRM"<<fixed<<setprecision(2)<<drinkprice[i]<<endl;
			}
		}
		double getPrice (int n){
			return drinkprice[n-1];
		}
		
		string getdrinktype(int n)
		{
			return drinktype[n-1];
		}
		~Drink(){}
};

class Pasta:public Food
{
		protected:
		string pastatype[NUMPASTA]={"Carbonara","Bolognese","Aglio Olio"};
		double pastaprice[NUMPASTA]={30.5,45.0,33.5};
		
	public:
/*		Pasta(string type=" ",double prc=0.0);
			pastatype[3]=type;
			pastaprice[3]=prc;
		}*/
		void display()
		{
			cout<<"=================================="<<endl;
			cout<<"||\t     Pasta    \t\t||"<<endl;
			cout<<"=================================="<<endl;
			for(int i=0;i<NUMPASTA;i++)
			{
				cout<<i+1<<". "<<left<<setw(10)<<pastatype[i]<<setw(5)<<"\t\tRM"<<fixed<<setprecision(2)<<pastaprice[i]<<endl;
			}
		}
		double getPrice (int n){
			return pastaprice[n-1];
		}
		
		string getpastatype(int n)
		{
			return pastatype[n-1];
		}
		~Pasta(){	}
};

class Sidedish:public Food
{
		protected:
		string sdtype[NUMSIDEDISH]={"Salad","Mashpotato","Wedges"};
		double sdprice[NUMSIDEDISH]={5.39,4.35,6.73};
		
	public:
/*		Sidedish(string type=" ",double prc=0.0){
			sdtype[3]=type;
			sdprice[3]=prc;
		}*/
		void display()
		{
			cout<<"=================================="<<endl;
			cout<<"||\t   Side Dish  \t\t||"<<endl;
			cout<<"=================================="<<endl;
			
			for(int i=0;i<NUMSIDEDISH;i++)
			{
				cout<<i+1<<". "<<sdtype[i]<<"\t\tRM"<<fixed<<setprecision(2)<<sdprice[i]<<endl;
			}
		}
		double getPrice (int n){
			return sdprice[n-1];
		}
		
		string getsdtype(int n)
		{
			return sdtype[n-1];
		}
		
		~Sidedish(){	}
};

int main()
{	
	ofstream out;
	out.open("Receipt.txt");
	int choice;
	char opt;
	double total=0.0;
	char again;
	cout<<"--------------------------";
	cout<<"\n||\t Welcome!\t||";
	cout<<"\n||\tEZAFA PIZZA\t||";
	cout<<"\n--------------------------";
	
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
		double tot=0.0;
		
		cout<<"\n\nWould you like to order?\n";
	
		cout<<"1. Pizza\n2. Drinks\n3. Pasta\n4. Side dish\n5. Exit"<<endl<<endl;
		cout<<"Order : ";
		cin>>choice;
		
		switch(choice)
		{
		case 1:
			{
				p.display();
				
				int pizz, size;
				
				cout<<endl<<"Your Choice ==> ";
				cin>>pizz;
				
				tot+=p.getPrice(pizz);
				p.pizzSize();
				
				cout<<endl<<"Your Choice ==> ";
				cin>>size;
				
				tot+=p.getSize(size);
				
				total+=tot;
				
				countP+=1;
				countS+=1;
				
				orderP[countP-1]=pizz;
				orderS[countS-1]=size;
				
				break;			
			}
		case 2:
			{
				d.display();
				int dr;
				cout<<endl<<"Your Choice ==> ";
				cin>>dr;
				tot+=d.getPrice(dr);
				total+=tot;
				
				countD+=1;
				
				orderD[countD-1]=dr;
				
				break;
			}
		case 3:
			{
				pst.display();
				int pta;
				cout<<endl<<"Your Choice ==> ";
				cin>>pta;
				tot+=pst.getPrice(pta);
				total+=tot;
				
				countPa+=1;
				
				orderPa[countPa-1]=pta;
				
				break;
			}
		case 4:
			{
				sd.display();
				int s;
				cout<<endl<<"Your Choice ==> ";
				cin >>s;
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
				
				cout<<endl<<"Total = RM "<<fixed<<setprecision(2)<<total<<endl<<endl;
				out<<endl<<"Total = RM "<<fixed<<setprecision(2)<<total<<endl<<endl;
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
		cin>>again;
		
		if(again=='n'||again=='N')
		{
			goto A;
		}
		
	}while (again=='Y'||again=='y');
	
	out.close();
	
	return 0;
}


