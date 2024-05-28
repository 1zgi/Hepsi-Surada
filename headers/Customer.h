#pragma once
#include "User.h"

using namespace std;


class Customer: public User {

private:
	string Name;
	string Last_N;
	string Customer_ID;//It is hold e-mails
	string Customer_Password;
	string file;
	string* Accounts_Name;
	string* Accounts_L;
	string* Accounts_ID;
	string* Accounts_PassW;
	
	int* Customer_Basket;//Holding Customer's items ID's in Basket
	int index;
	int counter;//for how many customer account exists.
	int Day;
	int Month;
	int c;


public:
	Customer();
	Customer(int a);

	void Entrance_CustomerInfo(string n, string L_N, string id, string pw);
	void ReadCustomerInfo_TextFile();
	void set_time(int day, int month);
	void operator=(const Customer& obj);
	void setInfosfromText();
	void Log_in_Customer();
	void check_Customer();
	void Confirm_PassW();


	int Return_interface();
	int Main_Customer();


	~Customer();
	

};
