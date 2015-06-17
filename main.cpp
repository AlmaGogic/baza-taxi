#include <iostream>
#include "priority_queue.hxx"
#include "driver.hxx"
#include <fstream>

using namespace std;

int main(){

priority_queue<Driver> *base = new priority_queue<Driver>();
priority_queue<int> *base_search = new priority_queue<int>();

int ID, age, year;
string name, surname, availability, licence_plate, color, model;
Driver driver;
Car car;
ifstream myfile ("base.txt");
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
    myfile >> licence_plate;
    myfile >> color;
    myfile >> model;
    myfile >> year;
   
      driver.setAutomobile(licence_plate, model, color, year);
       base->push(driver);
    }
  myfile.close();
}

cout << "Like administrator you have next option's to chose:" << endl;
int option;
for(int i=0; i<50; i++){
cout << "If you want to add new driver to the Base, you chose option 1." << endl;
cout << "If you want to remove driver from base, use option 2." << endl;
cout << "If you want to change availability of a driver chose option 3. " << endl;
cout << "If you want to print the base, chose option 4." << endl;
cin >> option;
}
if(option == 1){
//dodavanje vozaca
/*
cout << "Type name of new driver: " << endl;
cin >> name;
cout << "Type surname of new driver: " << endl;
cin >> surname;
cout << "Type ID for new driver: " << endl;
cin >> ID;
cout << "Type age of nrw driver: " << endl;
cin >> age;
cout << "Type the number od licence plate: " << endl;
cin >> licence_plate;
cout << "Type model of a car: " << endl;
cin >> model;
cout << "Type color of a car: " << endl;
cin >> color;
cout << "Type year of built: " << endl;
cin >> year;
cout << "Type availability for a new driver: " << endl;
cin >> availability;
driver(ID, age, name, surname, license_plate, model, color, year, availability);
base->push(driver);
*/
}

if(option == 2){
//moving driver from a base
cout << "Type ID of a driver you want to move from base." << endl;
int ID;
cin >> ID;
/*for(auto i=0; i<base->Size(); i++){
   if(base->at(i).getID() == ID)
  */    //I need option to delete element from base
 }

if(option == 3){
//changing availability of a driver
base->top().changeAvailability();
base->rePRDown(0, base->Size());
cout << "Availability is changed. " << endl;
}

if(option == 4){
//printing the base
for(auto i=0; i<base->Size(); i++)
   base->at(i).printDriverInfo();
cout << endl;
}

if(option == 5){
//saving the data

}

if(option == 6){
return 0;
}
}
