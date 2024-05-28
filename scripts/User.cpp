#include <iostream>
#include <stdexcept>
#include <windows.h>
#include <string>
#include <fstream>

#include "User.h"

using namespace std;

//-------------------------------------------------------------------------------------
string User:: hidepassword(const string& prompt = "") // Hiding Password Function While Entering Password
{
	string result;

	// Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleMode(ih, &mode))
		throw runtime_error(
			"hidepassword: You must be connected to a console to use this program.\n"
		);
	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	// Get the password string
	WriteConsoleA(oh, prompt.c_str(), prompt.length(), &count, NULL);
	char c;
	while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
	{
		if (c == '\b')
		{
			if (result.length())
			{
				WriteConsoleA(oh, "\b \b", 3, &count, NULL);
				result.erase(result.end() - 1);
			}
		}
		else
		{
			WriteConsoleA(oh, "*", 1, &count, NULL);
			result.push_back(c);
		}
	}

	// Restore the console mode
	SetConsoleMode(ih, mode);

	return result;
}
//---------------------------------------------------------------------------------------

User::User()
{
	select_role = 0;
	counter = 0;
}

User::User(int r, string n, string Ln, string id)
{
	select_role = r;
	User_Name = n;
	User_LastName = Ln;
	User_ID = id;
}

void User::Control_ID()
{
	Read_HowManyAccount_TextFile();
	for (int i = 0; i < counter; i++)
	{
		if (User_ID == IDcheck[i])
		{
			system("cls");
			cout << "This e-mail has already taken." << endl;
			cout << "Please try to create an account again." << endl;
			Create_AccountCustomer();
		}

	}
}

void User::Read_HowManyAccount_TextFile()//Reading Text file and find how many customer account we have.
{
	counter = 0;
	text_file_Customers.open("Customers.txt", ios::in);//in -> text okumak için

	if (text_file_Customers.is_open() == true)
	{

		while (getline(text_file_Customers, f))
		{

			if (f == "------------------")
			{
				f = '\0';
				counter++;
			}

			//cout << file << endl;//seing account list 

		}
	}

	//cout << counter << endl;//Test counter


	IDcheck = new string[counter];


	text_file_Customers.close();
	setInfosfromText();
}


void User::setInfosfromText()//Filling Account infos from text file.
{
	int c = 0;
	int i = 0;
	int j = 0;
	int id = 0;
	int* controler;
	controler = new int[counter];

	text_file_Customers.open("Customers.txt", ios::in);
	if (text_file_Customers.is_open() == true)
	{
		while (getline(text_file_Customers, f))
		{
			i++;
			if (f == "------------------")
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
		while (getline(text_file_Customers, f))
		{
			j++;
		
			if (j == (controler[c] - 2))
			{

				IDcheck[id] = f;
				// cout << IDcheck[id] << endl;//Test ID
				id++;
				c++;
			}

			
		}
	}
	text_file_Customers.close();
	delete[] controler;
}



//-------------------Creating Customer Account--------------------------
void User::Create_AccountCustomer()
{
	string yesno;
	
	cout << "----------Hello Customer--------" << endl;
	cout << "Please Create a Costumer Account" << endl;
	cout << "Please contiue with entering your name: ";
	cin >> User_Name;
	cout << "Please contiue with entering your last name: ";
	cin >> User_LastName;
	cout << "Please contiue with entering your e-mail: ";
	cin >> User_ID;
	Control_ID();
	cout << "Now please contiue with setting your Password: ";

	// Taking PassWord with hiding
	try {

		Password = hidepassword("");
		cout << endl;
		cout << "Do you want to see your Password enter YES or NO: ";
		cin >> yesno;
		if (yesno == "YES")
		{
			cout << "\nYour password is " << Password << endl; // Test for Password hiding is work
			system("pause");
		}
		

	}
	catch (exception& e)
	{
		cerr << e.what();

	}

	WriteCustomersInfo_Text();
}


void User::WriteCustomersInfo_Text()//Writing Customer's info in Text File 
{
	text_file_Customers.open("Customers.txt", ios::in | ios::out | ios::ate);// Bu þekilde dosyamýz her seferin de yeniden oluþturulmuyor(in i eklememizin sebebi) in ->dosyayý okumak için açar, out -> text yazma modu, ate -> sonuna eklemek için açar

	if (text_file_Customers.is_open() == true)
	{
		text_file_Customers << User_Name << endl;
		text_file_Customers <<User_LastName << endl;
		text_file_Customers << User_ID << endl;
		text_file_Customers << Password << endl;
		text_file_Customers << "------------------" << endl;
	}

	text_file_Customers.close();

}



int User::getRole()
{
	return select_role;
}



string User::getName()
{
	return User_Name;
}


string User::getLast_Name()
{
	return User_LastName;
}


string User::getID()
{
	return User_ID;
}

string User::getPassword()
{
	return Password;
}

User::~User()
{
	delete[] IDcheck;
}
