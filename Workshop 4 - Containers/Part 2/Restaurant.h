/* Citation and Sources...
OOP345 Workshop 4
Section: NAA
Module: Resturant
Filename: Resturant.h
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/10/18 Prelimary Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_RESTURANT_H
#define SDDS_RESTURANT_H

#include "Reservation.h"

namespace sdds {
	class Restaurant{
		Reservation* reserv; //dynamically allocates an array of reservations
		size_t count;
	public:
		Restaurant(Reservation* reservations[], size_t cnt); //constructor recieving array of pointers of reservations
		size_t size() const; //returns the number of reservations in the system
		Restaurant(const Restaurant& src); //copy constructor of restaurant class
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src); //move constructor of Restaurant class
		Restaurant& operator=(Restaurant&& src);
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& src); //friend insertion operator queries the content of Resturant Object
	};
}

#endif
