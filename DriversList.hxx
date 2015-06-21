#ifndef _DriversList_hxx_
#define _DriversList_hxx_
#include <iostream>
#include <string>
#include "driver.hxx"
#include "ArrayList.h"

class DriversList: public ArrayList<Driver>
{
	
	public:
			void InsertByAvailability(Driver A);
			void PrintDriversList();
	
	

	
	};
void DriversList::PrintDriversList(){
	cout<<"List of drivers:"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	for(int i=0;i<ArrayList.Size(); i++)
	{
	 printDriverInfo();
		}
	
	
	
	
	
	}
	
void DriversList::InsertByAvailability(Driver A)
{
	if (A.getAvailability()=="Yes")
	insertAtLocation(0,const &A);
	else 
	if (A.getAvailability()=="No")
	insertLast(const& A);
	
	return;
	
	}

#endif
