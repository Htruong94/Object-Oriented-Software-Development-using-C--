/* Citation and Sources...
OOP345 Workshop 4
Section: NAA
Module: Reservation
Filename: Reservation.cpp
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
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() :r_Id{ "" }, r_Name{ "" }, r_Email{ "" }, num_People{ 0 }, day{ 0 }, hour{ 0 } {
	}

	Reservation::Reservation(const std::string& res) :r_Id{ "" }, r_Name{ "" }, r_Email{ "" }, num_People{ 0 }, day{ 0 }, hour{ 0 } {
		std::string temp = res;
		size_t stPos = { temp.find_first_not_of(" ") };
		size_t itPos = { temp.find(":") };

		//sets r_Id
		r_Id = { temp.substr(stPos, itPos - stPos) };
		temp.erase(0, itPos+1);

		//sets r_Name
		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		r_Name = { temp.substr(stPos, itPos) };
		stPos = { r_Name.find_first_of(" ,") };
		if (stPos > 0 && stPos < r_Name.length()) {
			r_Name.erase(stPos, r_Name.length());
		}
		temp.erase(0, itPos+1);

		//sets r_Email
		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		r_Email = { temp.substr(stPos, itPos) };
		stPos = { r_Email.find_first_of(" ,") };
		if (stPos > 0 && stPos < r_Email.length()) {
			r_Email.erase(stPos, r_Email.length());
		}
		temp.erase(0, itPos+1);

		//sets num_People
		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		num_People = std::stoi(temp, &stPos);
		temp.erase(0, itPos+1);

		//sets day
		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		day = std::stoi(temp, &stPos);
		temp.erase(0, itPos+1);

		//sets hour
		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		hour = std::stoi(temp, &stPos);
		temp.erase(0, itPos+1);	
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& src) {
		std::string email = {"<"+src.r_Email+">"};
	
		os << "Reservation " << src.r_Id << ": ";
		os.width(10);
		os.setf(std::ios::right);
		os << src.r_Name;
		os.unsetf(std::ios::right);
		os << "  ";
		os.width(24);
		os.setf(std::ios::left);
		os << email;
		os.unsetf(std::ios::left);
		
		if (src.hour >= 6 && src.hour <= 9) {
			os << "Breakfast on day ";
		}
		else if (src.hour >= 11 && src.hour <= 15) {
			os << "Lunch on day ";
		}
		else if (src.hour >= 17 && src.hour <= 21) {
			os << "Dinner on day ";
		}
		else {
			os << "Drinks on day ";
		}
		
		os << src.day << " @ " << src.hour << ":00 for " << src.num_People << " people." << std::endl;

		return os;
	}
}