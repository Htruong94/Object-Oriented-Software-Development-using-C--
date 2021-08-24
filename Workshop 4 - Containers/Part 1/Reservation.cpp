#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() :r_Id{ "" }, r_Name{ "" }, r_Email{ "" }, num_People{ 0 }, day{ 0 }, hour{ 0 } {
	}

	/*Reservation::Reservation(const std::string& res) :r_Id{ "" }, r_Name{ "" }, r_Email{ "" }, num_People{ 0 }, day{ 0 }, hour{ 0 } {

		std::string temp = res;

		size_t tempPos = temp.find_first_not_of(' '); //find position of instance
		size_t sepPos = temp.find(':'); //find position of seperator
		r_Id = temp.substr(tempPos, sepPos - tempPos);


		if (r_Id.size() > 0) {
			temp.erase(0, sepPos+1);
			//r_Name
			tempPos = temp.find_first_not_of(' ');
			sepPos = temp.find(',');
			if (tempPos > 0) {
				temp.erase(0, tempPos);
			}
			tempPos = temp.find(' ');
			if (tempPos < sepPos) {
				r_Name = temp.substr(0, tempPos);
				temp.erase(0, sepPos);
			}
			else {
				r_Name = temp.substr(0, sepPos-1);
				temp.erase(0, sepPos);
			}

			//r_Email
			tempPos = temp.find_first_not_of(' ');
			sepPos = temp.find(',');
			if (tempPos > 0) {
				temp.erase(0,tempPos);
			}
			tempPos = temp.find(' ');
			if (tempPos < sepPos) {
				r_Email = temp.substr(0, tempPos);
				temp.erase(0, sepPos);
			}
			else {
				std::cout << 'b' << sepPos;
				r_Email = temp.substr(0, sepPos);
				temp.erase(0, sepPos);
			}
			//std::cout << r_Email;

			//num_People
			std::cout << 'c';
			tempPos = temp.find("1234567890");
			sepPos = temp.find(',');
			num_People = std::stoi(temp, &tempPos);
			temp.erase(0, sepPos+1);

			//day
			std::cout << 'd';
			tempPos = temp.find("1234567890");
			sepPos = temp.find(',');
			day = std::stoi(temp, &tempPos);
			temp.erase(0, sepPos+1);

			//hour
			std::cout << 'e';
			tempPos = temp.find("1234567890");
			sepPos = temp.find(',');
			hour = std::stoi(temp, &tempPos);

			std::cout << *this;
		}
	}*/

	Reservation::Reservation(const std::string& res) :r_Id{ "" }, r_Name{ "" }, r_Email{ "" }, num_People{ 0 }, day{ 0 }, hour{ 0 } {
		std::string temp = res;
		size_t stPos = { temp.find_first_not_of(" ") };
		size_t itPos = { temp.find(":") };

		r_Id = { temp.substr(stPos, itPos - stPos) };
		temp.erase(0, itPos+1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		r_Name = { temp.substr(stPos, itPos) };
		stPos = { r_Name.find_first_of(" ,") };
		if (stPos > 0 && stPos < r_Name.length()) {
			r_Name.erase(stPos, r_Name.length());
		}
		temp.erase(0, itPos+1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		r_Email = { temp.substr(stPos, itPos) };
		stPos = { r_Email.find_first_of(" ,") };
		if (stPos > 0 && stPos < r_Email.length()) {
			r_Email.erase(stPos, r_Email.length());
		}
		temp.erase(0, itPos+1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		num_People = std::stoi(temp, &stPos);
		temp.erase(0, itPos+1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		day = std::stoi(temp, &stPos);
		temp.erase(0, itPos+1);

		stPos = { temp.find_first_not_of(" ") };
		itPos = { temp.find(",") };
		hour = std::stoi(temp, &stPos);
		temp.erase(0, itPos+1);	
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& src) {
		std::string email = {"<"+src.r_Email+">"};
	
		os << "Reservation " << src.r_Id << ": ";
		os.width(10);
		os.setf(std::ios::right);
		os << src.r_Name;
		os.unsetf(std::ios::right);
		os << "  ";
		os.width(24);
		os.setf(std::ios::left);
		os << email;
		os.unsetf(std::ios::left);
		
		if (src.hour >= 6 && src.hour <= 9) {
			os << "Breakfast on day ";
		}
		else if (src.hour >= 11 && src.hour <= 15) {
			os << "Lunch on day ";
		}
		else if (src.hour >= 17 && src.hour <= 21) {
			os << "Dinner on day ";
		}
		else {
			os << "Drinks on day ";
		}
		
		os << src.day << " @ " << src.hour << ":00 for " << src.num_People << " people." << std::endl;

		return os;
	}
}