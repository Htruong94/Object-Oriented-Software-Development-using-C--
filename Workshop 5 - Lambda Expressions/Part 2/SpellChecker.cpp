/* Citation and Sources...
OOP345 Workshop 5
Section: NAA
Module: SpellChecker
Filename: SpellChecker.cpp
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

#include "SpellChecker.h"

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) : m_badWords{ {""} }, m_goodWords{ {""} } {
		std::ifstream file(filename);
		std::string line;
		size_t count = { 0 };
		size_t firstSpace = { 0 };
		size_t lastSpace = { 0 };
		try {
			if (file.is_open()) {
				do {
					std::getline(file, line);
					if (file) {
						firstSpace = { line.find_first_of(" ") };
						lastSpace = { line.find_last_of(" ") };

						m_badWords[count] = { line.substr(0,firstSpace) };
						m_goodWords[count] = { line.substr(lastSpace+1) };
						count++;
					}
				} while (file);
				file.close();
			}
			else {
				throw "Bad file name!";
			}
		}
		catch (const char* err) {
			std::cerr << "EXCEPTION: " << err << std::endl;
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		size_t n = { 0 };
		for (size_t i = 0; i < wordCollectionSize; i++) {
			do {
				n = text.find(m_badWords[i]);
				if (n != std::string::npos) {
					text.replace(n, m_badWords[i].length(), m_goodWords[i]);
				}
			} while (n != 0 && n != std::string::npos);
		}
	}
}