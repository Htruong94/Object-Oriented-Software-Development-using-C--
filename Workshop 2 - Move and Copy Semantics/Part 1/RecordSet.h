#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <cstring>

namespace sdds {
	class RecordSet {
		std::string* reco; //stores an array of elements with each 
		size_t numRec;
	public:
		RecordSet();
		RecordSet(const char* src);
		RecordSet& operator=(const RecordSet& src);
		RecordSet(const RecordSet& src);
		~RecordSet();
		size_t size() const;
		std::string getRecord(size_t index);
	};
}

#endif //SDDS_RECORDET_H

