#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>
#include <iomanip>

namespace sdds {
	class Book{
		std::string m_author;
		std::string m_title;
		std::string m_countryPub;
		size_t m_yearPub;
		double m_price;
		std::string m_desc;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price(double i);
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& src);
	};
}

#endif //SDDS_BOOK_H

