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
		K pair_Key; //stores the value of the key
		V pair_Value; //stores the value of the value
	public:
		Pair(): pair_Key{}, pair_Value{} {} //default constructor that initializes the private variables to an empty value

		Pair(const K& key, const V& value) : pair_Key(key), pair_Value(value) {} //custom constructor passing the values to the key and value

		const K& key() const { //returns the value of the key
			return pair_Key;
		}

		const V& value() const { //returns the value of the value
			return pair_Value;
		}

		virtual void display(std::ostream& os) const { //query of the values of the private members of the class
			os << pair_Key << " : " << pair_Value << std::endl;
		}
	};
	template <typename K, typename V> //free helper that passes to the display function
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif

