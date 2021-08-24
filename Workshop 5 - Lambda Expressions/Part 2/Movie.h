/* Citation and Sources...
OOP345 Workshop 5
Section: NAA
Module: Movie
Filename: Movie.h
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

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
#include <iomanip>

namespace sdds {
	class Movie{
		std::string mo_title; //stores the name of the movie
		size_t mo_year; //stores the year where movie was released
		std::string mo_desc; //stores the description of the movie
	public:
		Movie(); //default constructor for Movie
		const std::string& title() const; //returns the title of the movie
		Movie(const std::string& strMovie); //custom constructor that sets variables with the string provided
		friend std::ostream& operator<<(std::ostream& os, const Movie& src); //friend insertion operator to query the information of the movie
		template<typename T>
		void fixSpelling(T spellChecker) { //fixes any spelling mistakes within the title or description
			spellChecker(mo_title);
			spellChecker(mo_desc);
		}
	};
}

#endif //SDDS_MOVIE_H

