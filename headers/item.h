#pragma once
using namespace std;


class Item {

public:

	
	string Brand_name;
	string Product_name;
	string Product_type;
	double Product_price;
	int Product_stock_max;
	int Product_stock;
	int Product_number;

	Item();								//Default constructor

	//Overloading constructor
	Item(string Brand_val, string Type_val, string Name_val, double Price_val, int Max_val, int Stock_val, int Number_val);

	void operator=(Item a);				//"=" copy operator

	~Item();								//Destroyer
};