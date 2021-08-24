#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in), m_booster{ 0 } {
		std::string temp{ "" };
		std::string booster{ "" };
		size_t pos{ 0 };

		/*pos = temp.find_last_of(',');
		booster = temp.substr(pos+1);
		in >> temp;*/
	}

	void Racecar::display(std::ostream& out) const{
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return m_booster + Car::topSpeed();
	}
}