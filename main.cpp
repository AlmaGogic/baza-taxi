#include <iostream>
#include <string>
#include "DriversList.hxx"
#include <fstream>
#include <sstream>

using namespace std;

int getFileSize();
int printMenu();
void loadFromFile(DriversList& base);
void addNewItem(DriversList& base);
void saveInFile(DriversList& base);
void saveIDs(DriversList& base);
void moveFromBase(DriversList& base);

int main(){
  DriversList base;
  ArrayList<int> *base_search = new ArrayList<int>();
  bool added_new = false, already_loaded = false, saved_in_file = false;
  int file_size;
  int option;
  string file = "base.txt";
  
  do{
    option = printMenu();
    
    if(option == 1){
      loadFromFile(base);
      already_loaded = true;
      cout << "The data has been loaded." << endl;	
    }
    
    if(option == 2){
    //adding the driver
    file_size = getFileSize();
    if(file_size > 0 && !already_loaded){
      cout<<"Something is already stored in file. Do you want to load it? Y/N:";
      char answer;
      cin>>answer;
      if(answer == 'Y') {
        loadFromFile(base);
      }
    }

    already_loaded = true;									
    added_new = true;
    saved_in_file = false;
    addNewItem(base);

    cout << "The driver has been added to base." << endl;	
    }

    if(option == 3){
      //moving driver from a base
      moveFromBase(base);
    }
    
    if(option == 4){
      //changing availability of a driver
      int ID;
      cout << "Enter ID of driver you want to change availability: " ;
      cin>>ID;
      base.changingAvailability(ID);
      cout << "Availability is changed. " << endl;
    }
    
    if(option == 5){
      //printing the base
      base.PrintDriversList();
    }
    
    if(option == 6){
      //saving the data
      saveInFile(base);
      saveIDs(base);

      saved_in_file = true;
      cout << "The data has been saved." << endl;
    }

    if(option == 7){
      cout << "Ending program..." << endl;
    }
  }while(option != 7);
  
  if(added_new && !saved_in_file){
    cout << "Do you want to save unsaved changes? (Y, N)" << endl;
    char save;
    cin >> save;
    if(save == 'Y'){
      saveInFile(base);

      saved_in_file = true;
      
      cout << "The data has been saved." << endl;
    }
    
    cout << "Goodbye. " << endl;
    
    return 0;
  }
}

int getFileSize() {	
	std::ifstream is ("phonebook.txt", std::ifstream::binary);
	int length = 0;
	if (is) {	    
	    is.seekg (0, is.end);
	    length = is.tellg();	   
	    is.close();
	}
	return length;
}

int printMenu(){
  cout << "Like administrator you have next option's to chose:" << endl;
  int option;
  cout << "If you want to load data from file, chose option 1." << endl;
  cout << "If you want to add new driver to the Base, you chose option 2." << endl;
  cout << "If you want to remove driver from base, use option 3." << endl;
  cout << "If you want to change availability of a driver chose option 4. " << endl;
  cout << "If you want to print the base, chose option 5." << endl;
  cout << "If you want to save the changes, chose option 6." << endl;
  cout << "If you want to close the program chose option 7. " << endl;
  cin >> option;
  
  return option;
}

void loadFromFile(DriversList& base){
	
	ifstream file("base.txt");
	
	if (file.is_open())
	{
		base.LoadFromFile(file);
		file.close();
	}
	else{
		cout<<"Cannot opet file...Maybe file does not exist yet?"<<endl;
	}

}

void addNewItem(DriversList& base){
  int ID, age, year;
  string name, surname, availability, license_plate, color, model;
  Driver driver;
  Car car; 

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

void saveInFile(DriversList& base){
	
	base.sortByName();
	ofstream file("base.txt");

	if (file.is_open())
	{
		base.LoadInFile(file);
		file.close();
	}
	else{
		cout<<"Cannot open file..."<<endl;
	}
}

void saveIDs(DriversList& base)
{
  base.sort();
  ofstream file("ID_base.txt");
  if(file.is_open())
  {
    base.SaveIDs(file);
    file.close();
  }
  else
  {
    cout << "Cannot open file..." << endl;
  }
  
}

void moveFromBase(DriversList& base){
  cout << "Type ID of a driver you want to move from base." << endl;
  int ID;
  cin >> ID;
  if( !(base.empty()) ){
    for(auto i=0; i<base.Size(); i++){
      if(base.grabElement(i).getID() == ID){
          base.removeFromLocation(i);
          cout << "The Driver: " << base.grabElement(i).getName() << " " << base.grabElement(i).getSurname() << " has been deleted from base." << endl;
      }
      else
        cout << "There is no driver with this ID in base. " << endl;
    }
  }
  else cout << "The base is empty." << endl;
}
