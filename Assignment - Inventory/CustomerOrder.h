// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 27, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

struct Item //given in ms2 instruction
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name; //name of customer
	std::string m_product; //name of product assembled
	unsigned int m_cntItem; //number of item in customer's order
	Item** m_lstItem; //dynamically allocated aray of pointers to the object type Item

	static size_t m_widthField; //max width of field for display
public:
	CustomerOrder(); //default constructor of CustomerOrder class
	CustomerOrder(std::string src); //custom constructor of CustomerOrder class using data in string
	
	CustomerOrder(CustomerOrder& co); //throws exception when copy constructor is called
	CustomerOrder& operator = (CustomerOrder&) = delete; //delete when copy assignment is called
	CustomerOrder(CustomerOrder&& co) noexcept; //move constructor that does not throw exception
	CustomerOrder& operator = (CustomerOrder&& co) noexcept; //move assignment that does not throw exceptions
	~CustomerOrder();

	bool isOrderFilled() const; //returns true if all items in order have been filled, false otherwise
	bool isItemFilled(const std::string& itemName) const; // returns m_fillState, if item doesnt exist, return true
	void fillItem(Station& station, std::ostream& os); //fills item in current order
	void display(std::ostream& os) const; //displays state of current customer order
};

#endif //CUSTOMERORDER_H

