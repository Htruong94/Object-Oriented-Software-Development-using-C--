/* Citation and Sources...
OOP345 Workshop 2
Section: NAA
Module: RecordSet
Filename: RecordSet.cpp
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

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "RecordSet.h"

namespace sdds {

	RecordSet::RecordSet() {
		numRec = 0;
		reco = nullptr;
	}

	RecordSet::RecordSet(const char* fname) {
		std::string temp{};
		std::ifstream file;

		reco = nullptr;

		file.open(fname);

		if (file.is_open()) {
			for (numRec = 0; std::getline(file, temp, ' '); numRec++) {
			}
			file.close();
			file.open(fname);
			reco = new std::string[numRec];
			for (size_t i = 0; std::getline(file, temp, ' '); i++) {
				reco[i] = temp;
			}
		}
		else { //error if file is not open
			std::cout << "ERROR, FILE NOT FOUND" << std::endl;
		}
	}

	RecordSet& RecordSet::operator=(const RecordSet& src) {
		numRec = src.numRec;
		reco = new std::string[numRec];
		for (size_t i = 0; i < numRec; i++) {
			reco[i] = src.reco[i];
		}
		return *this;
	}

	RecordSet::RecordSet(const RecordSet& src) {
		reco = nullptr;
		numRec = 0;
		*this = src;
	}

	RecordSet::~RecordSet() {
		delete[] reco;
		reco = nullptr;
	}

	std::size_t RecordSet::size() const {
		return numRec;
	}

	std::string RecordSet::getRecord(size_t index) {
		if (reco != nullptr) {
			return reco[index];
		}
		else {
			return "\0"; //return a null if record is empty
		}
	}

	RecordSet::RecordSet(RecordSet&& src) noexcept{
		reco = nullptr;
		numRec = 0;
		*this = std::move(src);
	}

	RecordSet& RecordSet::operator=(RecordSet&& src) noexcept{
		if (this != &src) {
			delete[] reco; //deallocate current object's array
			reco = nullptr;

			reco = src.reco; //set address to the array of the src object

			numRec = src.numRec;
			src.numRec = 0;

			src.reco = nullptr;

		}
		return *this;
	}

}