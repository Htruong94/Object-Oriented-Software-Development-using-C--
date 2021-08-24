/* Citation and Sources...
OOP345 Workshop 5
Section: NAA
Module: SpellChecker
Filename: SpellChecker.h
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

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>
#include <fstream>
#include <iostream>

namespace sdds {
	const size_t wordCollectionSize = 5;

	class SpellChecker {
		std::string m_badWords[wordCollectionSize]; //stores the incorrectly spelt word
		std::string m_goodWords[wordCollectionSize]; //stores the correctly spelt word
	public:
		SpellChecker(const char* filename); //custom constructor that takes the data from the file to populate the variables
		void operator()(std::string& text) const; //replaces the wrong spelling in the given string with right spelling
	};
}

#endif //SDDS_SPELLCHECKER_H

