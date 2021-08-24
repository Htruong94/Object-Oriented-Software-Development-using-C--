/* Citation and Sources...
OOP345 Workshop 5
Section: NAA
Module: Collection
Filename: Collection.h
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/10/25 Prelimary Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <iostream>

namespace sdds {
	template<typename T>
	class Collection{
		std::string c_Name; //stores the name of the collection
		T* c_Items; //dynamically allocated array of templated items 
		size_t c_numItem; //number of items in the collection
		void(*ptr_Observer)(const Collection<T>&, const T&); //pointer to the observer function
	public:

		//custom constructor of Collection class nullptr
		Collection(std::string name) : c_Name{ "" }, c_Items{ nullptr }, c_numItem{ 0 }, ptr_Observer{nullptr } {
			c_Name = name;
		}

		//destructor of Collection class
		~Collection() {
			delete[] c_Items;
		}

		//returns the name of the collection
		const std::string& name() const {
			return c_Name;
		}

		//returns the size of the collection
		size_t size() const {
			return c_numItem;
		}

		//sets the observer pointer to the observer function
		void setObserver(void(*observer)(const Collection<T>&, const T&)) {
			ptr_Observer = observer;
		}

		//adds item to the collection if valid and calls callback function if observer is set
		Collection<T>& operator+=(const T& item) {
			bool valid{ true };
			for (size_t i = 0; i < c_numItem; i++) {
				if (c_Items[i].title() == item.title()) {
					valid = false;
				}
			}
			if (valid) {
				T* temp = { nullptr };
				if (c_Items != nullptr) {
					temp = new T[c_numItem + 1];
					for (size_t i = 0; i < c_numItem; i++) {
						temp[i] = c_Items[i];
					}
					temp[c_numItem] = item;

					delete[] c_Items;
					c_Items = new T[c_numItem + 1];
					for (size_t i = 0; i <= c_numItem; i++) {
						c_Items[i] = temp[i];
					}
				}
				else {
					c_Items = new T[c_numItem + 1];
					c_Items[c_numItem] = item;
				}
				c_numItem++;
				delete[] temp;
				if (ptr_Observer != nullptr) {
					ptr_Observer(*this, item);
				}
			}
			return *this;
		}

		//returns item of index provided if condition is met
		T& operator[](size_t idx) const {
			if (idx < 0 || idx >= c_numItem) {
				throw "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_numItem) + "] items.";
			}
			return c_Items[idx];
		}

		//returns matching item if found
		T* operator[](std::string title) const {
			for (size_t i = 0; i < c_numItem; i++) {
				if (c_Items[i].title() == title) {
					return &c_Items[i];
				}
			}
			return nullptr;
		}
		
		//no copy/move functions
		Collection(const Collection&) = delete;
		Collection& operator = (const Collection&) = delete;
		Collection(const Collection&&) = delete;
		Collection& operator = (const Collection&&) = delete;
	};

	//free helper function to overload insertion operator to query over the elements
	template<typename T>	
	std::ostream& operator<<(std::ostream& os, const Collection<T>& src) {
		for (size_t i = 0; i < src.size(); i++) {
			os << src[i];
		}
		return os;
	}
}

#endif //SDDS_COLLECTION_H
