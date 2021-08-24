// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 27, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

Workstation::Workstation(std::string src) : Station(src), m_pNextStation{ nullptr } {
	//std::cout << "workstation constructor" << std::endl;
}

void Workstation::runProcess(std::ostream& os) {
	//os << "runprocess" << std::endl;
	if (!m_orders.empty()) {
		if (!m_orders.front().isItemFilled(getItemName())) {
			//os << "process success" << std::endl;
			m_orders.front().fillItem(*this, os);
		}
	}
}

bool Workstation::moveOrder() {
	
	//std::cout << "moveOrder" << std::endl;
	if (m_pNextStation != nullptr && !m_orders.empty() && m_orders.front().isItemFilled(getItemName())) {
		*(static_cast<Workstation*>(m_pNextStation)) += std::move(m_orders.front());
		m_orders.pop_front();

		return true;
	}
	return false;
}

void Workstation::setNextStation(Station& station) {
	//std::cout << "nextStation" << std::endl;
	m_pNextStation = &station;
}

const Workstation* Workstation::getNextStation() const {
	return static_cast<Workstation*>(m_pNextStation); //casts base class pointer, station, to derived class pointer, workstation
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	//std::cout << "ifcompleted" << std::endl;
	if (!m_orders.empty()) {
		if (m_orders.front().isOrderFilled()) {
			order = std::move(m_orders.front());
			m_orders.pop_front();

			return true;
		}
	}
	return false;
}

void Workstation::display(std::ostream& os) {
	os << getItemName() << " --> ";
	if (m_pNextStation == nullptr) {
		os << "END OF LINE";
	}
	else {
		os << m_pNextStation->getItemName();
	}
}

Workstation& Workstation::operator+=(CustomerOrder&& src) {
	//std::cout << "+=" << std::endl;
	m_orders.push_back(std::move(src));
	return *this;
}