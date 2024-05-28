#include <iostream>
#include <string>
#include <fstream>
#include "Customer.h"


using namespace std;

Customer::Customer()
{
	index = 0;
	counter = 0;
	
}



Customer::Customer(int a) {

	Customer_Basket[index] = a;//Holding Customer's items ID's in Basket
	index++;
}


void Customer::Entrance_CustomerInfo(string n, string L_N, string id, string pw)//After Creating account (Sign Up)
{
	ReadCustomerInfo_TextFile();

	User_Name = n;
	User_LastName = L_N;
	User_ID = id;
	Password = pw;
	

	system("cls");

	cout << "Hello " << User_Name << " " << User_LastName << endl;
	cout << "Your account has successfully created." << endl;

	Confirm_PassW();
}

void Customer::Confirm_PassW()
{
	string yesno;
	int c = 0;
	while (c == 0)
	{
		cout << "Please Enter your Password again to confirm and continue: ";
		Customer_Password = hidepassword("");
		cout << endl;
		

		if (Customer_Password == Password)
		{
			c = 1;
			Main_Customer();
		}

		else
		{
			system("cls");
			cout << "You entered wrong password try again..." << endl;
			c = 0;
			
		}

	}
}

void Customer::set_time(int day, int month)
{
	Day = day;
	Month = month;
}

int Customer::Main_Customer()
{
	cout <<"Date: "<< Day << " / " << Month << endl;
	Sale_List s;
	double indirim = 0;
	int ch;
	ch = s.check(Day, Month);

	if (!(ch == -1)) {
		cout << endl << "We are in " << s.saledays[ch] << "! %" << s.saleper[ch] << " amount of dicount is active!" << endl;
	}

	int check = 0,action = 0,oper;
	
	Market market;
	
	
	while (action == 0)
	{
		
		cout << "\n----Welcome to Hepsi Surada----" << endl
			<< "1-SHOP: Catalog of the Products" << endl
			<< "2-Special sales" << endl
			<< "3-Return to main interface" << endl
			<< "4-Exit " << endl
			<< "Please choose your action: ";
		cin >> oper;

		cout << endl;
		switch (oper)
		{

		case 1: {	//Displaying products and shopping
			market.display(Day,Month);	
			break;
		}

		
		case 2: {	 
			c = 1;//Displaying sales 
			Return_interface();
			return 0;
			break;
		}

		case 3: {			//Returning the main interface
			c = 3;
			Return_interface();
			return 0;
			break;
		}

		case 4: {			//Exiting the program

			cout << "Thank you for choosing Hepsi Surada as your retailer...Come back again." << endl;
			exit(0);
			check = 1;
			break;
		}

		default: {			//Error option

			cout << "Unfortunetly we don't know what this action is...." << endl;
			break;
		}
		}
	}

	if ((action < 0) || (3 <= action)) {			//Error option

		cout << "Unfortunetly we dont know this action please try again." << endl;
	}


return 0;
}

int Customer::Return_interface()
{
	return c;
}


int User::getAction(int action)
{
	return action;
}

//-----------------------------------------------------------------------------------------------------------
//  --------------------------Reading Text File and Filling infos------------------------------------

void Customer::ReadCustomerInfo_TextFile()//Reading Text file and find how many customer account we have.
{
	index = 0;
	counter = 0;
	text_file_Customers.open("Customers.txt", ios::in);//in -> text okumak için

	if (text_file_Customers.is_open() == true)
	{

		while (getline(text_file_Customers, file))
		{
			if (file != "\0")
				index++;//Satýr sayýsý

				if (file == "------------------")
				{
					file = '\0';
					counter++;
				}
		}			
	}

	//counter is number of account .
	Accounts_Name = new string[counter];
	Accounts_L = new string[counter];
	Accounts_ID = new string[counter];
	Accounts_PassW = new string[counter];
	//

	text_file_Customers.close();

	setInfosfromText();
}


void Customer::setInfosfromText()//Filling Account infos from text file.
{
	int c = 0;
	int i = 0;
	int j = 0;
	int name = 0, sur = 0, id = 0, passw = 0;
	int *controler;
	controler = new int[counter];

	text_file_Customers.open("Customers.txt", ios::in);
	if (text_file_Customers.is_open() == true)
	{
		while (getline(text_file_Customers, file))
		{
			i++;
			if (file == "------------------")
			{
				controler[c] = i;//Leaving check points where the line is  "------------------" .
				                 //So we can track every single customer position in text file.
				c++;
				
			}
		}
	}
	text_file_Customers.close();

	text_file_Customers.open("Customers.txt", ios::in);

	if (text_file_Customers.is_open() == true)
	{
		c = 0;
		while (getline(text_file_Customers, file))
		{
			j++;
			if (j == (controler[c] - 4))
			{
				
				Accounts_Name[name] = file;
				//cout << Accounts_Name[name] << endl;//Test Name
				name++;
				
			}

			if (j == (controler[c] - 3))
			{

				Accounts_L[sur] = file;
				//cout << Accounts_L[sur] << endl;//Test Last Name
				sur++;
				
			}

			if (j == (controler[c] - 2))
			{

				Accounts_ID[id] = file;
				//cout << Accounts_ID[id] << endl;//Test ID
				id++;
				
			}

			if (j == (controler[c] - 1))
			{

				Accounts_PassW[passw] = file;
				//cout << Accounts_PassW[passw] << endl;//Test Password
				passw++;
				c++;
			}
		}
	}
	text_file_Customers.close();
	delete[] controler;
}


//------------------------------------------------------------------------------------------


//        -------------------------LOGIN CUSTOMER---------------------------------

void Customer::Log_in_Customer()//Login Customer (Sign in)
{
	
	string yesno;
	cout << "Please contiue with entering your e-mail: ";
	cin >> Customer_ID;

	cout << "Now please contiue with setting your Password: ";

	// Taking PassWord with hiding
	
		Password = hidepassword("");
		cout << endl;

	check_Customer();

}


void Customer::check_Customer()//Checking Customer after login (after sign in)
{
	int element;
	int check = 0;

	ReadCustomerInfo_TextFile();

	for (int i = 0; i < counter; i++)
	{
		if ( Accounts_ID[i] == Customer_ID)
		{
	
			if (Accounts_PassW[i] == Password )
			{
				element = i;
				check = 1;
			}
			
		}

	}

	if (check == 1)
	{
		system("cls");
		cout << "Hello " << Accounts_Name[element] << " " << Accounts_L[element] << endl;
		Main_Customer();
	}

	if (check == 0)
	{
		cout << "WARNING: Your account couldn't find please try again..." << endl;
		Log_in_Customer();
	}
}


//-------------------------------------------------------------------------------------------------------


void Customer::operator= (const Customer& obj)
{
	this->User_Name = obj.User_Name;
	//cout << User_Name << endl;
}



Customer::~Customer()
{
	delete[] Accounts_Name;
	delete[] Accounts_L;
	delete[] Accounts_ID;
	delete[] Accounts_PassW;

	//cout << "Free Accounts" << endl;//For Test

}


