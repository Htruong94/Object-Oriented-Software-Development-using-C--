// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 6, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Utilities.h"

class Station { //encapsulates information about given station on assembly line that fills custom orders
	unsigned int m_id; //id of the station
	std::string m_name; //name of the item in station
	std::string m_desc; //description of station
	unsigned int m_serialNumber; //next serial number assigned to an item in station
	unsigned int m_quantity; //number of current items in stock
	
	static unsigned int m_widthField; //max char required to print to screen of any object type station including all non static variables
	static unsigned int id_generator; //generate IDs for new instance created
public:
	Station(std::string& src); //custom constructor of Station class that parse the string to correct data
	const std::string& getItemName() const; //returns the name of the item
	unsigned int getNextSerialNumber(); //returns the current serial number while iterating m_serialnumber
	unsigned int getQuantity() const; //returns m_quantity
	void updateQuantity(); //decriment m_quantity if m_quantity is not equal to 0
	void display(std::ostream& os, bool full) const; //display partial or all non-static information of the class
};


#endif //STATION_H

