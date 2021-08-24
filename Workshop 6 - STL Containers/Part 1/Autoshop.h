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
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator += (Vehicle* theVehicle);
		void display(std::ostream& out);
		~Autoshop();
	};
}

#endif //SDDS_AUTOSHOP_H