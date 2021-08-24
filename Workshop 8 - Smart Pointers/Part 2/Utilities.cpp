// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// 2020/11/20 - Hung Truong - 147779193 - htruong19@myseneca.ca - OOP345NAA Workshop 8

/*---------------------------------------------------------
I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t a = 0; a < price.size(); a++) {
				if (desc[i].code == price[a].code) { //all products of matching code
					Product* prod = new Product(desc[i].desc, price[a].price);
					try {
						prod->validate();
						priceList += prod;
						delete prod;
					}
					catch (std::string err) { // allowing for prod to be deleted while throwing the exception given
						Product::Trace = false; //disallowing message to be displayed when calling deleting product
						delete prod;
						Product::Trace = true; //reallowiong messages to be displayed after product is deleted
						throw err;
					}
				}
			}
		}


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t a = 0; a < price.size(); a++) {
				if (desc[i].code == price[a].code) { 
					std::unique_ptr<Product> prod( new Product(desc[i].desc, price[a].price));
					prod->validate();
					priceList += prod;
				}
			}
		}

		return priceList;
	}
}