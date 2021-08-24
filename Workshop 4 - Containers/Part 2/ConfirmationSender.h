/* Citation and Sources...
OOP345 Workshop 4
Section: NAA
Module: Confirmation
Filename: Confirmation.h
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

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** c_Reserv; //array of pointers to a reservation object
		size_t count; //holds the current amount of pointers in the array
	public:
		ConfirmationSender(); //default constructor of ConfirmationSender class
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		~ConfirmationSender();
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src);
	};
}

#endif

