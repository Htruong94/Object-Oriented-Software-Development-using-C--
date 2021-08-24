/* Citation and Sources...
OOP345 Workshop 3
Section: NAA
Module: PairSummable
Filename: PairSummable.h
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

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include <iomanip>
#include "Pair.h"


namespace sdds {
	template <typename K, typename V>
	class PairSummable : public Pair<K, V> {
		static V iniSum; //initial value for summation
		static size_t minFW; //minimum field width
	public:
		PairSummable() { //defualt constructor of PairSummable class
			minFW = 0; 
			iniSum = {};
		}

		PairSummable(const K& key, const V& value = { 0 }) : Pair<K, V>(key, value) { //custom constructor that passes values to base class
			//std::cout << "called";
			//std::cout << "(" << minFW << ")" << "<" << key.length() << ">";
			if (minFW < key.length()) { //sets minimum field width to the length of the key
				minFW = key.length();
			}
			//std::cout << Pair<K, V>::key();
			//std::cout << "[" << minFW << "]" << std::endl;
		}

		bool operator == (const std::string& src) const{ //returns true if the key value matches the string value, false otherwise
			return Pair<K,V>::key() == src;
		}

		PairSummable& operator += (const PairSummable& src) { //+= overload
			if ((*this).key() != src.key()) {
				*this = PairSummable(Pair<K, V>::key(),
					Pair<K, V>::value() + src.value());
			}
			return *this;
		}

		void display(std::ostream& os) const { //returns a query and passes format to base display
			//std::cout << "(" << minFW << ")" << std::endl;
			os.width(minFW);
			os.setf(std::ios::left);
			Pair<K,V>:: display(os);
			os.unsetf(std::ios::left);
		}
	};

	//static declaration
	template<typename K, typename V>
	size_t PairSummable<K, V>::minFW = { 0 };
	//specialization
	template<> std::string PairSummable<std::string, std::string>::iniSum = { "" };
	template<> int PairSummable<std::string, int>::iniSum = { 0 };

	template <>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+= (const PairSummable& src) {
		std::string comma = ", ";
		//std::cout << src.value();
		if ((*this).key() != src.key() && this != &src) {
			if ((*this).value() == "") {
				*this = PairSummable(Pair<std::string, std::string>::key(),
					src.value());
			}
			else {
				*this = PairSummable(Pair<std::string, std::string>::key(),
					(Pair<std::string, std::string>::value()) + comma + src.value());
			}
		}

		return *this;
	}
}
#endif

