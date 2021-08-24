// Name: Hung Truong
// Seneca Student ID: 147779193
// Seneca email: htruong19@myseneca.ca
// Date of completion: November 6, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	if (more) {
		std::string extract{ "" };
		size_t delPos;
		delPos = str.find(m_delimiter, next_pos);
		try {
			if (delPos != std::string::npos) {
				more = true;
				extract = str.substr(next_pos, delPos - next_pos);
				if (extract.size() > 0 && extract.size() < str.size() - next_pos) {
					setFieldWidth(extract.size());
				}
				else {
					std::string err{ "No token" };
					throw err;
				}
			}
			else {
				more = false;
				extract = str.substr(next_pos);
			}
		}
		catch (std::string err) {
			std::cerr << "EXCEPTION: " << err << std::endl;
		}
		return extract;
	}
	else {
		return "";
	}
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}
