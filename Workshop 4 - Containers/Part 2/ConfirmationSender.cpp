/* Citation and Sources...
OOP345 Workshop 4
Section: NAA
Module: Confirmation
Filename: Confirmation.cpp
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

#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() : c_Reserv{ nullptr }, count{ 0 } {
	}
	
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool valid = { true };
		
		for (size_t i = 0; i < count; i++) {
			if (c_Reserv[i] == &res) {
				valid = false;
			}
		}
		if (valid) {
			const Reservation** tmp = new const Reservation * [count + 1];
			if (count > 0) {
				for (size_t i = 0; i < count; ++i) {
					tmp[i] = c_Reserv[i];
				}
			}
			tmp[count] = &res;

			++count;

			delete[] c_Reserv;
			c_Reserv = tmp;
			tmp = { nullptr };
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool valid = { false };
		size_t match = { 0 };

		for (size_t i = 0; i < count; ++i) {
			if (c_Reserv[i] == &res) {
				match = i;
				valid = { true };
			}
		}
		if (valid) {
			for (size_t i = match; i < count; i++) {
				if(count){
					c_Reserv[count-1] = nullptr;
					count--;
				}
				else {
					c_Reserv[i] = c_Reserv[i + 1];
				}
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) : c_Reserv{ nullptr }, count{ 0 } {
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this != &src) {
			delete[] c_Reserv;
			c_Reserv = src.c_Reserv;
			count = src.count;
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) : c_Reserv{ nullptr }, count{ 0 } {
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) {
		if (this != &src) {
			delete[] c_Reserv;
			c_Reserv = src.c_Reserv;
			count = src.count;
			src.count = { 0 };
			src.c_Reserv = { nullptr };
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] c_Reserv;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (src.count > 0 || src.c_Reserv != nullptr) {
			for (size_t i = 0; i < src.count; ++i) {
				os << *src.c_Reserv[i];
			}
		}
		else {
			os << "The object is empty!" << std::endl;
		}
		os << "--------------------------" << std::endl; 

		return os;
	}
}