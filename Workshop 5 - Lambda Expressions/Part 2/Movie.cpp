/* Citation and Sources...
OOP345 Workshop 5
Section: NAA
Module: Movie
Filename: Movie.cpp
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/10/25 Prelimary Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include "Movie.h"
namespace sdds {
	Movie::Movie() : mo_title{ "" }, mo_year{ 0 }, mo_desc{ "" } {
	}

	const std::string& Movie::title() const {
		return mo_title;
	}
	
	Movie::Movie(const std::string& strMovie) : mo_title{ "" }, mo_year{ 0 }, mo_desc{ "" } {
		std::string temp = strMovie;
		size_t stPos = { temp.find_first_not_of(" ") };
		size_t itPos = { temp.find(",") };
		mo_title = { temp.substr(stPos, itPos - stPos) };
		stPos = { mo_title.find_last_of("abcdefghijklmnopqrsuvwxyz.") };
		if (stPos > 0 && stPos < mo_title.length()) {
			mo_title.erase(stPos + 1, mo_title.length());
		}
		temp.erase(0, itPos + 1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		mo_year = std::stod(temp, &stPos);
		temp.erase(0, itPos + 1);

		stPos = { temp.find_first_not_of(" ") };
		mo_desc = { temp.substr(stPos) };
	}

	std::ostream& operator<<(std::ostream& os, const Movie& src) {
		os << std::right << std::setw(40) << src.mo_title << " | ";
		os << std::setw(4) << src.mo_year << " | ";
		os << src.mo_desc << std::endl;

		return os;
	}
}