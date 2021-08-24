#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Vehicle.h"
namespace sdds
{
	class Car:public Vehicle {
		std::string c_maker; //stores the name of the company that made the car
		std::string c_condition; //store either "new", "used", "broken"
		double c_topSpeed; //store the value of car's top speed
	public:
		Car(std::istream& in); //Extract record in format TAG,MAKER,CONDITION,TO_SPEED
		std::string condition() const; //query the condition of the car
		double topSpeed() const; //query the top speed of the car
		void display(std::ostream& out) const; //displays in the format | MAKER | CONDITION | TOP SPEED |
	};
}

#endif //SDDS_CAR_H