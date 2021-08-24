// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 6, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"

unsigned int Station::m_widthField = { 0 };
unsigned int Station::id_generator = { 0 };

Station::Station(std::string& src) :m_id{ 0 }, m_name{ "" }, m_desc{ "" }, m_serialNumber{ 0 }, m_quantity{ 0 } {
	Utilities locUtil;
	bool more{ true };
	size_t nextPos{ 0 };
	std::string temp{ "" };
	
	Station::id_generator++;
	m_id = Station::id_generator;

	m_name = locUtil.extractToken(src, nextPos, more);
	nextPos = src.find(locUtil.getDelimiter(), nextPos + 1) + 1;
	//if field width of utilities is greater than station, set station field width to utility
	if (locUtil.getFieldWidth() > Station::m_widthField) {
		Station::m_widthField = locUtil.getFieldWidth() + 1;
	}

	temp = locUtil.extractToken(src, nextPos, more);
	m_serialNumber = std::stoi(temp);
	
	nextPos = src.find(locUtil.getDelimiter(), nextPos + 1) + 1;
	temp = locUtil.extractToken(src, nextPos, more);
	m_quantity = std::stoi(temp);

	nextPos = src.find(locUtil.getDelimiter(), nextPos + 1) + 1;
	m_desc = locUtil.extractToken(src, nextPos, more);
}

const std::string& Station::getItemName() const {
	return m_name;
}

unsigned int Station::getNextSerialNumber() {
	m_serialNumber++;
	return m_serialNumber-1;
}

unsigned int Station::getQuantity() const {
	return m_quantity;
}

void Station::updateQuantity() {
	if (m_quantity != 0) {
		m_quantity--; 
	}
}

void Station::display(std::ostream& os, bool full) const {
	os << "[" << std::setfill('0') << std::setw(3) << std::right << m_id;
	os << "] Item: " << std::setfill (' ') << std::setw(Station::m_widthField) <<std::left << m_name;
	os << "[" << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << std::setfill(' ') << "]";
	if (full) {
		os << " Quantity: " << std::setw(13) << std::left << m_quantity;
		os << "Description: " << m_desc << std::endl;
	}
	else {
		os << std::endl;
	}
}
