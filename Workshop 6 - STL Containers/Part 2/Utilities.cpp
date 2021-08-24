#include "Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {

		std::string tag = { "" };
		size_t pos = { 0 };
	
		std::getline(in, tag, ',');
		std::cout << "x";
		pos = tag.find_first_not_of(' ');
		tag = tag.substr(pos);
		if (tag.empty()) {
			return nullptr;
		}

		if (tag[0] == 'c' || tag[0] == 'C') {
			Car* inst = new Car(in);
			return inst;
		}
		else if (tag[0] == 'r' || tag[0] == 'R'){
			Racecar* inst = new Racecar(in);
			return inst;
		}
		else {
			char err = tag[0];
			throw err;
			//return nullptr;
		}
	}
}