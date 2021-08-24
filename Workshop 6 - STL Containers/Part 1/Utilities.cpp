#include "Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string tag = { "" };
		size_t pos = { 0 };
		std::getline(in, tag, ',');
		pos = tag.find_first_not_of(' ');
		std::cout << tag;
		if (pos == std::string::npos) {
			return nullptr;
		}

		tag = tag.substr(pos);

		if (tag[0] == 'c' || tag[0] == 'C') {
			Car* inst = new Car(in);
			return inst;
		}
		else {
			return nullptr;
		}
	}
}