/* Citation and Sources...
OOP345 Workshop 2
Section: NAA
Module: RecordSet
Filename: RecordSet.h
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/10/3 Prelimary Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <cstring>

namespace sdds {
	class RecordSet {
		std::string* reco; //stores an array of elements as a record 
		size_t numRec;
	public:
		RecordSet(); //default constructor of RecordSet class
		RecordSet(const char* src); //custom constructor of RecordSet class
		RecordSet& operator=(const RecordSet& src); //copy assignment
		RecordSet(const RecordSet& src); //copy function
		~RecordSet(); //destructor of RecordSet class
		size_t size() const; //query numRec
		std::string getRecord(size_t index); //query a record of the given index
		RecordSet(RecordSet&& src) noexcept; //move constructor 
		RecordSet& operator=(RecordSet&& src) noexcept; //move assignment
	};
}

#endif //SDDS_RECORDET_H

