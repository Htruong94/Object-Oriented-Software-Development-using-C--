// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 27, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
#include "Utilities.h"

class Workstation: public Station{
	std::deque<CustomerOrder> m_orders; //double ended queue with CustomerOrder comes in and out when a new one enters
	Station* m_pNextStation; //points to the next station of the assembly line
public:
	Workstation(std::string src); //custom constructor of workstation class 

	//deletes any instances of move or copy
	Workstation(Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator = (Workstation&) = delete;
	Workstation& operator = (Workstation&&) = delete;

	void runProcess(std::ostream& os); //runs single cycle of assembly line to the current station, fills order if order is in queue
	bool moveOrder(); //if order at front of queue does not require service at current station, move order to the next station or is empty and return true, else false
	void setNextStation(Station& station); //store station referenced to m_pNextStation
	const Workstation* getNextStation() const; //return m_pNextStation
	bool getIfCompleted(CustomerOrder& order); //check order is completed and remove from queue if completed then return true, otherwise return false. 
	void display(std::ostream& os); //displays contents of the workstation class
	Workstation& operator+=(CustomerOrder&& src); //moves parameter to the back of CustomerOrder queue
};

#endif //WORKSTATION_H

