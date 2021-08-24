/* Citation and Sources...
OOP345 Workshop 5
Section: NAA
Module: Book
Filename: Book.h
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>
#include <iomanip>

namespace sdds {
	class Book{
		std::string m_author; //stores the name of the author
		std::string m_title; //stores the name of the book
		std::string m_countryPub; //stores the country where the book was published
		size_t m_yearPub; //stores the year when the book was published
		double m_price; //stores the price of the book
		std::string m_desc; //stores the description of the book
	public:
		Book(); //default constructor of book class
		const std::string& title() const; //returns the title of the book
		const std::string& country() const; //returns the country where book was published
		const size_t& year() const; //returns the year when the book was published
		double& price(double i); //returns the price of the book and allows for price adjustments
		Book(const std::string& strBook); //custom constructor taking a string and populate the variables of the book
		friend std::ostream& operator<<(std::ostream& os, const Book& src); //displays the information of the book
		template<typename T>
		void fixSpelling(T spellChecker) {  //fixes any spelling mistakes within the title or description
			spellChecker(m_title);
			spellChecker(m_desc);
		}
	};
}

#endif //SDDS_BOOK_H

