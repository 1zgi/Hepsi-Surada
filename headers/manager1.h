#pragma once
using namespace std;
#include "User.h"

class Manager:public User {

private:
	string manager_ID;
	User info;
	int stock_num;
	double offers;
	double deals;
	Item infoS;
	int c;
	
	string manager_passW;

	int Day;
	int Month;

public:
	string check;//check for some interface questions YES or NO
	

	Manager();

	Manager(int Snumber, double off, double d,int r);

	void set_time(int day, int month);
	int return_interface();
	void TakeInfo_Manager();
	int Main_Manager();

};

