#include <iostream>
#include <string>
using namespace std;

#ifndef LOCATIONGPS_H
#define LOCATIONGPS_H

class LocationGps
{
private:
    string locName;
    
public:
	
    LocationGps();
    LocationGps(string name);
    string getLocation();
    
    void setLocation(string loc);
    
    string printloc(LocationGps g);
};


#endif
