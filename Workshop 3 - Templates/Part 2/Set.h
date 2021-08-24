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
		T eleType[N]; //statically allocated array of the given template type of size N
		size_t eleCount = 0; //stores the amount of elements that are currently being stored
	
	public:

		size_t size() const { //returns the amount of elements that are stored
			return eleCount;
		}

		const T& operator[](size_t idx) const { //returns the element in the array at the given index
			return eleType[idx];
		}

		void operator+=(const T& item) { //copies an item and store it into the array while incrementing eleCount if eleCount is lower than N
			if (eleCount < N) {
				eleType[eleCount] = item;
				eleCount++;
			}
		}
	};
}

#endif

