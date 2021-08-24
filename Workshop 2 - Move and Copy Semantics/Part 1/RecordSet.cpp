#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "RecordSet.h"

using namespace sdds;

RecordSet::RecordSet() {
	size_t numRec = 0;
	reco = nullptr;
}

RecordSet::RecordSet(const char* fname) {
	std::string temp{};
	std::ifstream file;

	file.open(fname);

	if (file.is_open()) {
		if (reco != nullptr) {
			delete[] reco;
			reco = nullptr;
		}
		for (numRec = 0; std::getline(file, temp, ' '); numRec++) {
		}
		file.close();
		file.open(fname);
		reco = new std::string[numRec];
		for (size_t i = 0; std::getline(file, temp, ' '); i++) {
			reco[i] = temp;
		}
	}
	else {
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
		return " ";
	}
}