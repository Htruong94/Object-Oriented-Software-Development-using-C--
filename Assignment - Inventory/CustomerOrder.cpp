// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 27, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = { 0 };

CustomerOrder::CustomerOrder() : m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem{ nullptr } {
}

CustomerOrder::CustomerOrder(std::string src) : m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem{ nullptr } {
	Utilities cusUtil;
	bool more{ true };
	size_t nextPos{ 0 };
	size_t tempPos{ 0 };
	size_t cnt{ 0 };
	std::string temp{ "" };
	std::string tempsrc{ "" };

	m_name = cusUtil.extractToken(src, nextPos, more);
	nextPos = src.find(cusUtil.getDelimiter(), nextPos + 1) + 1;
	if (m_widthField < cusUtil.getFieldWidth()) {
		m_widthField = cusUtil.getFieldWidth();
	}

	m_product = cusUtil.extractToken(src, nextPos, more);
	nextPos = src.find(cusUtil.getDelimiter(), nextPos + 1) + 1;
	if (m_widthField < cusUtil.getFieldWidth()) {
		m_widthField = cusUtil.getFieldWidth();
	}

	tempsrc = src; //temp copies for counting purpose
	tempPos = nextPos;

	while (more) { //obtains the amount of items in data
		temp = cusUtil.extractToken(tempsrc, tempPos, more);
		m_cntItem++;
		tempPos = tempsrc.find(cusUtil.getDelimiter(), tempPos + 1) + 1;
	}
	more = { true };

	m_lstItem = new Item * [m_cntItem];

	while (more) { //points a newly created item object to an element in the array of pointers
		temp = cusUtil.extractToken(src, nextPos, more);
		m_lstItem[cnt] = new Item(temp);
		if (m_widthField < cusUtil.getFieldWidth()) {
			m_widthField = cusUtil.getFieldWidth();
		}
		nextPos = src.find(cusUtil.getDelimiter(), nextPos + 1) + 1;
		cnt++;
	}
}

CustomerOrder::CustomerOrder(CustomerOrder& co) : m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem{ nullptr } {
	/*try {
		std::string noCopy{ "Cannot make copies." };
		throw noCopy;
	}
	catch (std::string err) {
		//std::cerr << err << std::endl;
	}*/
	std::string noCopy{ "Cannot make copies." };
	throw noCopy;
}

CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept : m_name{ "" }, m_product{ "" }, m_cntItem{ 0 }, m_lstItem{ nullptr } {
	//std::cout << "move const" << std::endl;
	*this = std::move(co);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept {
	//std::cout << "move assign" << std::endl;
	if (this != &co) {

		if (m_lstItem != nullptr) { //deletes contents within array of pointers if there is data 
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
		}
		
		m_name = { co.m_name };
		m_product = { co.m_product };
		m_cntItem = { co.m_cntItem };
		m_lstItem = { co.m_lstItem };
		
		co.m_name = { "" };
		co.m_product = { "" };
		co.m_cntItem = { 0 };
	
		co.m_lstItem = { nullptr };
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const {
	//std::cout << "isorderfilled" << std::endl;
	if (m_lstItem != nullptr) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				//std::cout << "false";
				return m_lstItem[i]->m_isFilled;
			}
		}
	}

	return true;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			return m_lstItem[i]->m_isFilled;
		}
	}
	return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = { true };

				os << "    Filled " << m_name << ", ";
				os << m_product << " [";
				os << station.getItemName() << "]" << std::endl;
			}
			else {
				os << "    Unable to fill " << m_name << ", ";
				os << m_product << " [";
				os << station.getItemName() << "]" << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - ";
	os << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] ";
		os << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName;
		os << " - " <<(m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
	}
}