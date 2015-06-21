#include <iostream>
#include "DriversList.hxx"
#include <fstream>

using namespace std;

int main(){

DriversList base;
ArrayList<int> *base_search = new ArrayList<int>();

int ID, age, year;
string name, surname, availability, license_plate, color, model;
Driver driver;
Car car; 
/* ifstream myfile ("base.txt");
if (myfile.is_open())
{
  while (myfile != "\n"){
    myfile >> ID;
     driver.setID(ID);
    myfile >> age;
     driver.setAge(age);
    myfile >> name;
     driver.setName(name);
    myfile >> surname;
    driver.setSurname(surname);
    myfile >> availability;
   driver.setAvailability(availability);
    myfile >> license_plate;
    myfile >> color;
    myfile >> model;
    myfile >> year;
   
      driver.setAutomobile(license_plate, model, color, year);
       base.InsertByAvailability(driver);
  }
  myfile.close();
} 
else { 
cout << "There is no file to open." << endl;
}
*/
cout << "Like administrator you have next option's to chose:" << endl;
int option;
for(int i=0; i<50; i++){
cout << "If you want to add new driver to the Base, you chose option 1." << endl;
cout << "If you want to remove driver from base, use option 2." << endl;
cout << "If you want to change availability of a driver chose option 3. " << endl;
cout << "If you want to print the base, chose option 4." << endl;
cout << "If you want to save the changes, chose option 5." << endl;
cout << "If you want to close the program chose option 6. " << endl;
cin >> option;

if(option == 1){
//adding the driver

cout << "Type name of new driver: " << endl;
cin >> name;
cout << "Type surname of new driver: " << endl;
cin >> surname;
cout << "Type ID for new driver: " << endl;
cin >> ID;
cout << "Type age of new driver: " << endl;
cin >> age;
cin.ignore();
cout << "Type the number of license plate: " << endl;
cin >> license_plate;
cout << "Type model of a car: " << endl;
cin >> model;
cout << "Type color of a car: " << endl;
cin >> color;
cin.ignore();
cout << "Type year of built: " << endl;
cin >> year;
cout << "Type availability for a new driver: " << endl;
cin >> availability;
driver.makeDriver(ID, age, name, surname, license_plate, model, color, year, availability);
base.InsertByAvailability(driver);
cout << "The driver has been added to the base." << endl;
cout << endl;
}

if(option == 2){
//moving driver from a base
cout << "Type ID of a driver you want to move from base." << endl;
cin >> ID;
for(auto i=0; i<base.Size(); i++){
   if(base.grabElement(i).getID() == ID){
      base.removeFromLocation(i);
      cout << "The Driver: " << base.grabElement(i).getName() << " " << base.grabElement(i).getSurname() << " has been deleted from base." << endl;
    }
  }
}
/*
if(option == 3){
//changing availability of a driver
base->top().changeAvailability();
base->rePRDown(0, base->Size());
cout << "Availability is changed. " << endl;
}
*/
if(option == 4){
//printing the base
base.PrintDriversList();
}


if(option == 5){
//saving the data
ofstream myfile;
  myfile.open ("base.txt");
  if(myfile.is_open()){
  myfile << "ID\t" << "Name:\t" << "Surname\t" << "Age:\t" << "License plate: " << "Model:\t" << "Color:\t" << "Year:\t" << "Availability:"<< "\n";
  for(auto i=0; i<base.Size(); i++){
    ID = base.grabElement(i).getID();
    name = base.grabElement(i).getName();
    surname = base.grabElement(i).getSurname();
    age = base.grabElement(i).getAge();
    car = base.grabElement(i).getAutomobile();
    license_plate = car.getLicense_plate();
    model = car.getBrand();
    color = car.getColor();
    year = car.getYear();
    availability = base.grabElement(i).getAvailability();
    myfile << ID << " " << name << " " << surname << " " << age << " " << license_plate << " " << model << " " << color << " " << year << " " << availability << "\n";
  }
 // "Writing informations to a file.
  myfile.close();
}
}

if(option == 6){
cout << "Do you want to save unsaved changes? (Y, N)" << endl;
string save;
cin >> save;
if(save == "Y"){
ofstream myfile;
  myfile.open ("base.txt");
  if(myfile.is_open()){
  myfile << "ID\t" << "Name:\t" << "Surname:\t" << "Age:\t" << "License plate: " << "Model:\t" << "Color:\t" << "Year:\t" << "Availability:"<< "\n";
  for(auto i=0; i<base.Size(); i++){
    ID = base.grabElement(i).getID();
    name = base.grabElement(i).getName();
    surname = base.grabElement(i).getSurname();
    age = base.grabElement(i).getAge();
    car = base.grabElement(i).getAutomobile();
    license_plate = car.getLicense_plate();
    model = car.getBrand();
    color = car.getColor();
    year = car.getYear();
    availability = base.grabElement(i).getAvailability();
    myfile << ID << "\t " << name << "  " << surname << "\t  " << age << "\t " << license_plate << "\t  " << model << "\t " << color << "\t " << year << "\t\t " << availability << "\n";
  }
 }
 // "Writing informations to a file.
  myfile.close();
return 0;
}

else if(save == "N")
return 0;
}
}
}
