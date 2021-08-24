/* Citation and Sources...
OOP345 Workshop 3
Section: NAA
Module: Pair
Filename: Pair.h
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

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>
#include <string>

namespace sdds {
	template <typename K, typename V>
	class Pair
	{
		K pair_Key;
		V pair_Value;
	public:
		Pair(): pair_Key{}, pair_Value{}
		{}

		Pair(const K& key, const V& value) : pair_Key(key), pair_Value(value)
		{}

		const K& key() const {
			return pair_Key;
		}

		const V& value() const {
			return pair_Value;
		}

		void display(std::ostream& os) const {
			os << pair_Key << " : " << pair_Value << std::endl;
		}
	};
	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif

