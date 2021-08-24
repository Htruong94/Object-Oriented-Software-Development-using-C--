#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop{
		std::vector<Vehicle*> m_vehicles; //holds a vector of vehicle objects
	public:
		Autoshop& operator += (Vehicle* theVehicle); //adds a vehicle object to the Autoshop class
		void display(std::ostream& out); //display all vehicles in autoshop information
		~Autoshop(); //destructor of the Autoshop class
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) { //template function that adds a vehicle in the vector to another Autoshop if the vehicle satisfies the lambda condition
			for (auto& i : m_vehicles) {
				if (test(i)) {
					vehicles.push_back(i);
				}
			}
		}
	};
}

#endif //SDDS_AUTOSHOP_H