// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 6, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>

	class Utilities {//support parsing of input files to setup and configure assembly line simulation
		size_t m_widthField; //length of token extracted, default value 1
		static char m_delimiter; //seperation token shared between all Utilities object
	public:
		void setFieldWidth(size_t newWidth); //sets field width to value of parameter
		size_t getFieldWidth() const; //returns the field width value
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more); //extract tokens from first parameter
		static void setDelimiter(char newDelimiter); //sets delimiter of class to parameter
		static char getDelimiter(); //returns delimiter of class
	};


#endif //ULTILITES_H
