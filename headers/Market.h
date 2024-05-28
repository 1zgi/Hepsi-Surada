#pragma once

#include "item.h"
#include "Buying.h"
#include "Sale-List.h"
#include "basket.h"
#include <fstream>
#include <string>

using namespace std;

class Market {

private:
	int index;
	int counter;
	fstream text_file_items;
	string file;
	int wh_item;
	
	int C;
	int Day;
	int Month;

public:

	Item* items;
	int all;					//Market's current item count

	

	int numara;					//Product number system base


	Market();					//Default constructor

	Market(char a);				//Overloading Constructor

	void go_DisplayBasket(int c);

	void display(int day, int month);	//Display all Products

	void display_Brand();		 //Display via Brand

	void display_Name();		//Display via Name

	void display_Type();		//display via Type

	void item_rearrenge();		//rearrenge the stock

	void item_add();			//add Product

	void stock_delete();		//delete Product

	void restock(int code);		//restock one Product

	void display_basket();
	void re_write_itemlist();
	int Return_Count();
	void Read_Item_Info_Text();
	void setInfosfromText();
	Item* get_itemlist();

	~Market();
};
