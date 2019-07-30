#include <iostream>
#include <string>
#include "LocationGps.h"
using namespace std;

LocationGps::LocationGps(){}

LocationGps::LocationGps(string name){locName=name;}
    
string LocationGps::getLocation(){return locName;}
    
void LocationGps::setLocation(string loc) {locName=loc;}
    
string LocationGps::printloc(LocationGps g)
{
       string loc;
       cout<<"Insert your pick up location: ";
       getline(cin,loc);
       g.setLocation(loc);
       
       return loc;
}
