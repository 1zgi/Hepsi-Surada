#pragma once
#include"Market.h"
#include <fstream>
#include <string>

class Basket{
private:
	string Brand_N[30];
	string Product_N[30];
	string Product_T[30];
	double Product_price[30];
	int amount[30];
	int kalan;
	int indx;
	double total;
	int in[30];
	int same[30];
	fstream textBasket;
	string fileB;
	double tot;
	int DAY;
	int MONTH;
	static int counter;
	Item *stock;
	int index;
	int count;

public:
	
	Basket() {
		indx = 0;
		index = 0;
		count = 0;
	}

	
	
	void empty_array();
	void Basket_add(int day, int month);
	void Basket_display(int day, int month);
	int get_amount();
	int get_i();

	~Basket();

};

