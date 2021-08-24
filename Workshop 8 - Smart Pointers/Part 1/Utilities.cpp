// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


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
						Product::Trace = { false }; //disallowing message to be displayed when calling deleting product
						delete prod;
						Product::Trace = { true }; //reallowiong messages to be displayed after product is deleted
						throw err;
					}
				}
			}
		}


		return priceList;
	}
}