#ifndef _CAR_H
#define _CAR_H
#include <iostream>
#include <string>

using namespace std;

class Car
{
	private:
		
		std::string _license_plate; //ID
		std::string _color;			//Standard car color
		std::string _model;			//model of car(Tesla,Renault...)
		int  _year; 				
		
	public:

		Car();  
		Car( const std::string& _license_plate, const std::string& _model, const std::string& _color,int _year);
		
		~Car()=default; 
		
		/***********methods**********/
		void makeCar(const std::string& license_plate, const std::string& model, const std::string& color,int year);
		void printCarInfo() const;
		
		void setLicense_plate( const std::string& license_plate){_license_plate=license_plate;}
		void setBrand( const std::string& model ){ _model=model; }
		void setYear( int year ){ _year=year; }
		void setColor( const std::string& color ){ _color=color; }

		const std::string& getLicense_plate() const { return _license_plate; }
		int getYear() const { return _year; }
		const std::string& getColor() const { return _color; }
		const std::string& getBrand() const { return _model; }
		
	
};

 void Car::printCarInfo() const
{
	cout  <<" Model:" << _model << "  "<<_year<<"g.   "<<"Color:"<<_color<<"   License plates: "<<_license_plate<<endl; 
}

void Car::makeCar(const std::string& license_plate, const std::string& model, const std::string& color,int year)
{
	_license_plate=license_plate;
	_model=model;
	_color=color;
	_year=year;	
}

Car::Car (const std::string& license_plate, const std::string& model, const std::string& color,int year)
{
	_license_plate=license_plate;
	_model=model;
	_color=color;
	_year=year;	
}

Car::Car()
{
	_license_plate="";
	_model="";
	_color="";
	_year=0;
	
}

#endif
