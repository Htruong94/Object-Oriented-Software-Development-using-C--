/* Citation and Sources...
OOP345 Workshop 3
Section: NAA
Module: Set
Filename: Set.h
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

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template <typename T, int N>
	class Set
	{
		T eleType[N];
		size_t eleCount = 0;
	
	public:

		size_t size() const {
			return eleCount;
		}

		const T& operator[](size_t idx) const {
			return eleType[idx];
		}

		void operator+=(const T& item) {
			if (eleCount < N) {
				eleType[eleCount] = item;
				eleCount++;
			}
		}
	};
}

#endif

