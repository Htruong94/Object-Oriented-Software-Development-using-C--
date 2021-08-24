/* Citation and Sources...
OOP345 Workshop 5
Section: NAA
Module: Book
Filename: Book.cpp
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

#include "Book.h"

namespace sdds {
	//Book::Book() : m_author{ "" }, m_title{ "" }, m_countryPub{ "" }, m_yearPub{ 0 }, m_price{ 0 }, m_desc{ "" } {
	//}

	const std::string& Book::title() const {
		return m_title;
	}

	const std::string& Book::country() const {
		return m_countryPub;
	}

	const size_t& Book::year() const {
		return m_yearPub;
	}

	double& Book::price(double i = 0) {
		m_price *= i;
		return m_price;
	}

	Book::Book(const std::string& strBook) : m_author{ "" }, m_title{ "" }, m_countryPub{ "" }, m_yearPub{ 0 }, m_price{ 0 }, m_desc{ "" } {
		std::string temp = strBook;
		size_t stPos = { temp.find_first_not_of(" ") };
		size_t itPos = { temp.find(",") };
		m_author = { temp.substr(stPos, itPos-stPos) };
		stPos = { m_author.find_last_of("abcdefghijklmnopqrsuvwxyz.") };
		if (stPos > 0 && stPos < m_author.length()) {
			m_author.erase(stPos + 1, m_author.length());
		}
		temp.erase(0, itPos + 1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		m_title = { temp.substr(stPos, itPos) };
		stPos = { m_title.find_last_of("abcdefghijklmnopqrsuvwxyz.") };
		if (stPos > 0 && stPos < m_title.length()) {
			m_title.erase(stPos+1, m_title.length());
		}
		temp.erase(0, itPos + 1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		m_countryPub = { temp.substr(stPos, itPos) };
		stPos = { m_countryPub.find_first_of(", ") };
		if (stPos > 0 && stPos < m_countryPub.length()) {
			m_countryPub.erase(stPos, m_countryPub.length());
		}
		temp.erase(0, itPos + 1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		m_price = std::stod(temp, &stPos);
		temp.erase(0, itPos + 1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		m_yearPub = std::stoi(temp, &stPos);
		temp.erase(0, itPos + 1);

		stPos = { temp.find_first_not_of(" ") };
		m_desc = { temp.substr(stPos) };
	}

	std::ostream& operator<<(std::ostream& os, const Book& src) {
		os << std::setw(20) << std::right << src.m_author << " | ";
		os << std::setw(22) << src.m_title << " | ";
		os << std::setw(5) << src.m_countryPub << " | ";
		os << std::setw(4) << src.m_yearPub << " | ";
		os << std::setw(6) << std::setprecision(2) << std::fixed << src.m_price << " | ";
		os << src.m_desc << std::endl;

		return os;
	}
}