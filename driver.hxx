#ifndef _driver_hxx_
#define _driver_hxx_

#include "car.hxx"


#include <iostream>


class Driver {

	private:
		int _ID;
		int _age;
		std::string _name;
		std::string _surname;
		Car _automobile;
		std::string _availability; // "yes" for available & "not" unavailable

	public:
		
		
		void makeDriver(int ID,int age, const std::string& name,const std::string& surname,const std::string& license_plate, const std::string& model, const std::string& color,int year, const std::string& availability);
		void printDriverInfo() const;
		
		void setID( int ID ) { _ID = ID ;}
		void setAge( int age ) { _age = age ;}
		void setAutomobile( const std::string& license_plate, const std::string& model, const std::string& color,int year ) { _automobile.makeCar(license_plate, model, color, year);}
		void setName(const std::string& name){_name=name;}
		void setSurname(const std::string& surname){_surname=surname;}
		void setAvailability(const std::string availability){_availability=availability;}
    		void changeAvailability();
		
		
		int getID() const { return _ID ; }
		int getAge() const { return _age; }
		const Car& getAutomobile() const { return _automobile; }
		std::string getName() const { return _name; }
		std::string getSurname() const { return _surname; }
		std::string getAvailability() const {return _availability;}
		
		bool operator==( const Driver& other){ return this->_ID==other.getID(); }
		bool operator!=( const Driver& other){ return this->_ID!=other.getID(); }
		bool operator>( const  Driver& other){ return this->_availability>other.getAvailability();  }
		friend ostream& operator<<(ostream&, const Driver&);
		
		~Driver()=default;
		
		Driver(){ _ID =0 ,_age=0 ,_name="",_surname="",_automobile=Car() , _availability="";};
		Driver( int ID, int age, const std::string& name, const std::string& surname,const std::string& license_plate, const std::string& model, const std::string& color,int year,const std::string& availability)
		{ _ID = ID , _age=age, _name=name, _surname=surname,_automobile.makeCar( license_plate, model, color, year ) , _availability=availability; }
	

};


ostream& operator<<(ostream & out,const Driver&)
{ 	       
            
            return out;
}

void Driver::makeDriver(int ID,int age, const std::string& name,const std::string& surname,const std::string& license_plate, const std::string& model, const std::string& color,int year, const std::string& availability)
{ 
	_ID=ID;
	_age=age;
	_name=name;
	_surname=surname;
	_automobile.makeCar( license_plate, model, color, year );
	_availability=availability;
}


void Driver::printDriverInfo() const
{
	cout << "Driver: " << _surname << " " << _name <<endl;

	cout << "Car: " << endl;
  _automobile.printCarInfo();


	cout << "Availability: " << _availability << endl;
	
}

void Driver::changeAvailability()
{
  if(this->_availability == "Yes")
    _availability = "No";
  else if(_availability == "No")
    _availability = "Yes";
}
#endif
