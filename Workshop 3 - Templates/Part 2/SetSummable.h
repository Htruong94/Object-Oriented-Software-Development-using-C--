/* Citation and Sources...
OOP345 Workshop 3
Section: NAA
Module: SetSummable
Filename: SetSummable.h
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/10/11 Prelimary Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"

namespace sdds {
	template<typename T, int N>
	class SetSummable : public Set<T, N> {
	public:
		T accumulate(const std::string& filter) const { //accumulation function that uses a string provided to filter information and add
			T obj;

			for (size_t i = 0; i < this->size(); i++) {
				if ((*this)[i] == filter) {
					obj += (*this)[i];
				}
			}
			return obj;
		}
	};
}

#endif
