#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>

#include "item.h"

using namespace std;

Item::Item() {									//Default constructor

	Brand_name = "None";
	Product_type = "None";
	Product_name = "None";
	Product_price = 0;
	Product_stock_max = 0;
	Product_stock = 0;
	Product_number = 0;
}

//Overloading constructor
Item::Item(string Brand_val, string Type_val, string Name_val, double Price_val, int Max_val, int Stock_val, int Number_val) {

	Brand_name = Brand_val;
	Product_type = Type_val;
	Product_name = Name_val;
	Product_price = Price_val;
	Product_stock_max = Max_val;
	Product_stock = Stock_val;
	Product_number = Number_val;
}

void Item::operator=(Item a) {					//"=" copy operator

	Product_type = a.Product_type;

	Brand_name = a.Brand_name;

	Product_name = a.Product_name;

	Product_price = a.Product_price;

	Product_number = a.Product_number;

	Product_stock = a.Product_stock;

	Product_stock_max = a.Product_stock_max;
}

Item::~Item() {

}