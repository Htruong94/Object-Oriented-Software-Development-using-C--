#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include "Car.h"

namespace sdds {
	class Racecar: public Car {
		double m_booster; //stores percentage between 0 and 1
	public:
		Racecar(std::istream& in); //custom constructor of the Racecar class
		void display(std::ostream& out) const; //displays information of the racecar
		double topSpeed() const; //returns the value of m_booster
	};
}

#endif //SDDS_RACECAR_H