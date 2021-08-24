/* Citation and Sources...
OOP345 Workshop 4
Section: NAA
Module: Resturant
Filename: Resturant.cpp
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

#include "Restaurant.h"

namespace sdds {

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) : reserv{ nullptr }, count { 0 } {
		delete[] reserv;
		count = cnt;
		reserv = new Reservation[count];
		for (size_t i = { 0 }; i < count; i++) {
			reserv[i] = *reservations[i];
		}
	}

	size_t Restaurant::size() const {
		/*size_t cnt = { 0 };
		if (reserv != nullptr) {
			for (cnt = 0; reserv[cnt] != nullptr; cnt++) {
			}
		}*/
		return count;
	}

	Restaurant::Restaurant(const Restaurant& src) : reserv{ nullptr }, count{ 0 } {
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			//delete[] reserv;
			reserv = new Reservation [src.size()];
			for (size_t i = 0; i < src.size(); i++) {
				reserv[i] = src.reserv[i];
			}
			count = src.count;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) : reserv{ nullptr }, count{ 0 } {
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) {
		if (this != &src) {
			delete[] reserv;
			reserv = src.reserv;
			count = src.count;

			src.reserv = { nullptr };
			src.count = 0;
		}
		return *this;
	}

	Restaurant::~Restaurant() {
		delete[] reserv;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& src) {
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant" <<std::endl;
		os << "--------------------------" << std::endl;
		if (src.reserv != nullptr) {
			for (size_t i = 0; i < src.size(); i++) {
				os << src.reserv[i];
			}
		}
		else {
			os << "The object is empty!" << std::endl;
		}
		os << "--------------------------" << std::endl;

		return os;
	}
}