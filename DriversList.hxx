#ifndef _DriversList_hxx_
#define _DriversList_hxx_
#include <iostream>
#include <string>
#include <sstream>
#include "driver.hxx"
#include "ArrayList.h"

class DriversList: public ArrayList<Driver>
{
	
	public:
			void InsertByAvailability(const Driver& A);
			void PrintDriversList();
            void LoadFromFile(std::istream&);
            void LoadInFile(std::ostream&);	
            void changingAvailability(int Id);
};
void DriversList::changingAvailability(int Id){
	for(auto i=0; i<(*this).Size(); i++)
    if((*this).grabElement(i).getID()==Id){
	if((*this).grabElement(i).getAvailability()=="Yes")
	(*this).grabElement(i).setAvailability("No");
	else
	(*this).grabElement(i).setAvailability("Yes");
	}
}
	
	
	

void DriversList::PrintDriversList(){
	cout<<"List of drivers:"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	
for(auto i=0; i<(*this).Size(); i++)
    (*this).grabElement(i).printDriverInfo();
	cout << endl; 
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

void DriversList::LoadFromFile(std::istream& file)
{
        if(!empty()) deleteList();

	int ID, age, year;
        string name, surname, availability, license_plate, color, model;
        Driver driver;
        Car car; 

	while(file >> ID >> age >> name >> surname >> license_plate >> color >> model >> year >> availability ){
		 driver.setID(ID);
                 driver.setAge(age);
                 driver.setName(name);
                 driver.setSurname(surname);
                 driver.setAutomobile(license_plate, model, color, year);
                 driver.setAvailability(availability);
                 
                 (*this).InsertByAvailability(driver);
       }
}

void DriversList::LoadInFile(std::ostream& file)
{
  int ID, age, year;
  std::string name, surname, availability, license_plate, color, model;
  Driver driver;
  Car car;

  if(empty()) cout<<"Nothing to save..."<<endl;
  else{
  file << "ID\t" << "Name:\t" << "Surname:\t" << "Age:\t" << "License plate: " << "Model:\t" << "Color:\t" << "Year:\t" << "Availability:"<< "\n";
  for(auto i=0; i<Size(); i++){
    ID = grabElement(i).getID();
    name = grabElement(i).getName();
    surname = grabElement(i).getSurname();
    age = grabElement(i).getAge();
    car = grabElement(i).getAutomobile();
    license_plate = car.getLicense_plate();
    model = car.getBrand();
    color = car.getColor();
    year = car.getYear();
    availability = grabElement(i).getAvailability();
    file << ID << "\t " << name << "  " << surname << "\t  " << age << "\t " << license_plate << "\t  " << model << "\t " << color << "\t " << year << "\t\t " << availability << "\n";
   }
  }	
}

#endif
