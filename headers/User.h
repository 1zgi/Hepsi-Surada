#pragma once
#include "Market.h"


#include <fstream>

using namespace std;

class User {

protected:
	int select_role;
	string User_Name;
	string User_LastName;
	string User_ID;
    string Password;
	string f;// For read text for User class
	fstream text_file_Customers;
	string *IDcheck;
	int counter;
	
public:
	
	User();

	User(int r, string n, string Ln, string id);

	int getRole();
	string getName();
	string getLast_Name();
	string getID();
	string getPassword();
	string hidepassword(const string& prompt);
	

	int getAction(int action);
	void WriteCustomersInfo_Text();//Writing Customer's info in Text File
	void Create_AccountCustomer();
	void TakeInfo_Manager();
	void Control_ID();
	void Read_HowManyAccount_TextFile();
	void setInfosfromText();
	
	~User();
};
