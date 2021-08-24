// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 27, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

LineManager::LineManager(const std::string fname, std::vector<Workstation*>& srcWS, std::vector<CustomerOrder>& srcCO) : m_cntCustomerOrder{ 0 }{
	//std::cout << "linemanager constructor" << std::endl;
	std::fstream file(fname);

	Utilities cusUtil;
	cusUtil.setDelimiter('|');
	bool more{ true };
	size_t nextPos{ 0 };

	std::string line{ "" };
	std::string token{ "" };
	std::vector<std::string> tokenCollection;

	while (!file.eof()) {
		std::getline(file, line);
		while (more) {
			token = cusUtil.extractToken(line, nextPos, more);
			nextPos = line.find(cusUtil.getDelimiter(), nextPos + 1) + 1;
			tokenCollection.push_back(token);
		}
		
		for (auto ws : srcWS) {
			if (ws->getItemName() == tokenCollection.front() && tokenCollection.size() == 2) {
				for (auto nextWS : srcWS) {
					if (nextWS->getItemName() == tokenCollection.back()) {
						ws->setNextStation(*nextWS);
					}
				}
			}
		}

		for (auto i : tokenCollection) { //clears vector containing each token in line
			tokenCollection.pop_back();
		} 

		nextPos = { 0 };
		more = { true };
	}

	std::for_each(srcCO.begin(), srcCO.end(), [&](CustomerOrder& co) {
		ToBeFilled.push_back(std::move(co));
		m_cntCustomerOrder++;
	});

	for (auto ws : srcWS) {
		AssemblyLine.push_back(ws);
	}
}

bool LineManager::run(std::ostream& os) {
	static size_t cnt{ 0 };
	
	std::deque<Workstation*> temp;

	bool first{ true };

	if (temp.empty()) {
		for (auto firstAssem : AssemblyLine) {
			for (auto matching : AssemblyLine) {
				if (firstAssem == matching->getNextStation()) {
					first = { false };
				}
			}
			if (first == true) {
				temp.push_back(std::move(firstAssem));
				break;
			}
			else {
				first = { true };
			}
		}
	} //set temp to the initial station

	os << "Line Manager Iteration: " << ++cnt << std::endl;

	if (!ToBeFilled.empty()) {
			*temp.front() += std::move(ToBeFilled.front());
			ToBeFilled.pop_front();
	}

	for (auto assem : AssemblyLine) {
		assem->runProcess(os);
	}

	for (auto assem : AssemblyLine) {
		assem->moveOrder();
	}

	CustomerOrder comp; //stores move if order is completed and pushed to Completed
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), [&](Workstation* ws) {
		if (ws->getIfCompleted(comp)) {
			Completed.push_back(std::move(comp));
		}
	});

	/*for (auto assem : AssemblyLine) {
		if (assem->getIfCompleted(comp)) {
			Completed.push_back(std::move(comp));
		}
	}*/

	return Completed.size() == m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (auto station : AssemblyLine) {
		station->display(std::cout);
		std::cout << std::endl;
	}
}

void LineManager::displayStationsSorted() const {
	bool first{ true };
	Workstation* temp{ nullptr };
	for (auto firstAssem : AssemblyLine) {
		for(auto matching:AssemblyLine) {
			if (firstAssem == matching->getNextStation()) {
				first = {false};
			}
		}
		if (first == true) {
			firstAssem->display(std::cout);
			std::cout << std::endl;
			temp = firstAssem;
			break;
		}
		else {
			first = { true };
		}
	}
	for (size_t i = 0; i < AssemblyLine.size() - 1; i++) {
		for (auto Assem : AssemblyLine) {
			if (Assem == temp->getNextStation()) {
				Assem->display(std::cout);
				std::cout << std::endl;
				temp = Assem;
			}
		}
	}
}