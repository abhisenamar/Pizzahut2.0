#include <iostream>
#include <string>
using namespace std;

class LocationGps
{
private:
    string locName;
    
public:
    LocationGps(){}
    LocationGps(string name){locName=name;}
    
    string getLocation(){return locName;}
    
    void setLocation(string loc) {locName=loc;}
    
    void printloc(LocationGps g)
    {
        string loc;
        cout<<"Insert your location: ";
        getline(cin, loc);
        g.setLocation(loc);
        
        cout<<"We will get your order from our store in "<< g.getLocation()<<endl<<endl;
    }
};


class Promocode
{
private:
    string pcode;
    
public:
    Promocode(){}
    Promocode (string pc){pcode=pc;}
    string getPromocode() {return pcode;}
    
    void setPromoCode(string pc){pcode=pc;}
    
    void printCode(Promocode p)
    {
        string pc;
        cout<<"Enter your Promo Code: ";
        getline(cin, pc);
        if((pc=="A123")||(pc=="B123")||(pc=="C123")) // promo code are set to: A123, B123, C123
        {
            p.setPromoCode(pc);
            cout<<"Congratulation! You get 50% OFF!!!"<<endl;
        }
        else{
            cout<<"Your Promo Code is INVALID :( "<<endl<<endl;
        }
        
    }
};

int main()
{
    //for GPS*********************************
    LocationGps loc;
    int ansGps;
    
    do{
        cout<<"Allow GPS? (1- yes/2- no): ";
        cin>>ansGps;
        cin.ignore();
    
        if (ansGps==1)
        {
            loc.printloc(loc);
        }
        else if (ansGps==2)
        {
        
        }
        else{
            cout<<endl<<"INVALID"<<endl<<endl;
        }
    }while (ansGps>2);
    
    //for promo code*************************
    
    Promocode pc;
    int ansCode;
    
    do{
        cout<<"Do you have a promo code? (1-yes/2-no): ";
        cin>>ansCode;
        cin.ignore();
        
        if (ansCode==1)
        {
            pc.printCode(pc);
        }
        else if (ansCode==2)
        {
            
        }
        else{
            cout<<endl<<"INVALID"<<endl<<endl;
        }
    }while (ansCode>2);
    
    
   
    return 0;
    
}
