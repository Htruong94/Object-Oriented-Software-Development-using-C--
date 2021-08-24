#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in); //creates an instance of a vehicle that is either a Car or Racecar
}

#endif //SDDS_UTILITIES_H