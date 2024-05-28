#pragma once

#include "Market.h"


class Buying {

private:
	int index[30];
	int count;
	double* price;
	double total;
	string *Bname;
	string* Pname;
	string* Ptype;
	int *amount;
	int a;
	int miktar[30];
	int DAY;
	int MONTH;

public:
	Buying();
	void set_TimeVal(int day, int month);
	void set_index(int a, int* amo, int* indx);
	void set_basket(int a,int *amo,int *indx);
	void buying(int day, int month);
	~Buying();
};

