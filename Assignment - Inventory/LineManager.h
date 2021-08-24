// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 27, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Workstation.h"

class LineManager {
	std::vector<Workstation*> AssemblyLine; //Container containing all references of Workshop objects
	std::deque<CustomerOrder> ToBeFilled; //queue of customer orders to be filled
	std::deque<CustomerOrder> Completed; //queue of customer orders completed
	unsigned int m_cntCustomerOrder; //Number of CustomerOrder objects initially in assembly line

	//Workstation* nextStation;
public:
	LineManager(const std::string fname, std::vector<Workstation*>&, std::vector<CustomerOrder>&); //Custom constructor taking a string of the filename used to link assembly line objects
	bool run(std::ostream& os); //runs one cycle of operation of assemblyline
	void displayCompletedOrders(std::ostream& os) const; //display all completed orders
	void displayStations() const; //displays all stations on assembly line recieved from client
	void displayStationsSorted() const; //displays all linked stations on assembly line
};

#endif //LINEMANAGER_H

