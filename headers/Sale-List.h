#pragma once

#include <vector>
using namespace std;

class Sale_List {

public:

	int all;						//number of sales
	
	double saleper[5];
	string saledays[5];
	string type[6]; //product types
	int startday[5];
	int startmonth[5];
	int endday[5];
	int endmonth[5];

	int day;
	int month;

	Sale_List();

	Sale_List(int a);

	void sale_display();
	int check(int day, int month);


	~Sale_List();
};
