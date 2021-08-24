/* Citation and Sources...
OOP345 Workshop 4
Section: NAA
Module: Reservation
Filename: Reservation.h
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

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {
	class Reservation
	{
		std::string r_Id; //holds the id of the reservation
		std::string r_Name; //holds the name of the individual
		std::string r_Email; //holds the individual's email address
		size_t num_People; //current amount of people in the party
		size_t day; //holds the day when the party is expected to be hold
		size_t hour; //holds the hour when the party is expected to be hold
	public:
		Reservation(); //default constructor of reservation class
		Reservation(const std::string& res); //Constructer that passes a string of information in the format ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
		friend std::ostream& operator<<(std::ostream& os, const Reservation& src); //friend insert operator that queries the current object
	};
}

#endif //SDDS_RESERVATION_H

