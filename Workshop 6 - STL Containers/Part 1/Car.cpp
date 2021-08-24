#include "Car.h"

namespace sdds {
	Car::Car(std::istream& in) : c_maker{ "" }, c_condition{ "" }, c_topSpeed{ 0 } {
		std::string line{ "" };
		size_t stPos{ 0 };
		size_t edPos{ 0 };

		std::getline(in, c_maker, ',');
		stPos = { c_maker.find_first_not_of(" ") };
		edPos = { c_maker.find_last_of("abcdefghijklmnopqrsuvwxyz") };
		c_maker = { c_maker.substr(stPos, edPos) };

		std::getline(in, c_condition, ',');
		if (c_condition == "") {
			c_condition = 'n';
		}
		else {
			stPos = { c_condition.find_first_not_of(" ") };
			edPos = { c_condition.find_last_of("abcdefghijklmnopqrsuvwxyz") };
			c_condition = { c_condition.substr(stPos, edPos) };
			if (c_condition[0] != 'n' && c_condition[0] != 'u' && c_condition[0] != 'b') {
				char invalid = c_condition[0];
				throw invalid;
			}
		}

		std::getline(in, line);
		stPos = { line.find_first_not_of(" ") };
		try {
			c_topSpeed = std::stod(line, &stPos);
		}
		catch (std::exception & inv) {
			std::string invReco = "Invalid Record!";
		}
	}

	std::string Car::condition() const {
		if (c_condition == "n") {
			return "new";
		}
		else if (c_condition == "b") {
			return "broken";
		}
		else {
			return "used";
		}
	}

	double Car::topSpeed() const {
		return c_topSpeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << std::right << c_maker;
		out << " | " << std::left << std::setw(6) << condition();
		out << " | " << std::setw(6) << std::setprecision(2) << std::fixed << c_topSpeed << " |" << std::endl;
	}
}