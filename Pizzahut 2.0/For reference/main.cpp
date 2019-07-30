#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
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
		
	return 0;
}

