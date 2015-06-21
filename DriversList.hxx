#ifndef _DriversList_hxx_
#define _DriversList_hxx_
#include <iostream>
#include <string>
#include "driver.hxx"
#include "ArrayList.h"

class DriversList: public ArrayList<Driver>
{
	
	public:
			void InsertByAvailability(const Driver& A);
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
	
void DriversList::InsertByAvailability(const Driver& A)
{
	if (A.getAvailability()=="Yes")
	insertAtLocation(0,A);
	else 
	if (A.getAvailability()=="No")
	insertAtEnd(A);
	
	return;
	
}

#endif
