#include <iostream>
#include <string>
#include "manager1.h"

using namespace std;

Manager::Manager()
{
	manager_ID = "12345";
	manager_passW = "123";
	 stock_num = 0;
	 offers = 0;
	 deals = 0;
	 c = 0;
}

Manager::Manager(int Snumber, double off, double d,int r)
{
	stock_num = Snumber;
	offers = off;
	deals = d;
	c = r;
}

void Manager::TakeInfo_Manager()
{
	system("cls");
	int check = 1;
	cout << "----------Hello Manager--------" << endl;
	while (check)
	{


		cout << "Please contiue with entering your ID: ";
		cin >> User_ID;
		
		
		cout << "Now please contiue with setting your Password: ";

		// Taking PassWord with hiding


		Password = hidepassword("");
		//cout << "Your password is " << Password << endl; // Test for Password hiding is work

		if (!(User_ID == manager_ID && Password == manager_passW))
		{
			cout << "\nWrong Input" << endl;
		}

		else
			check = 0;


	}
}

void Manager::set_time(int day, int month)
{
	Day = day;
	Month = month;
}

int Manager::Main_Manager()
{
	
	//Sale_List indirim(1);
	Market market('a');
	int check = 0, action = 0, oper, item_number;
	string answer;
	//Sale_List indirim;

   while (action == 0)
   {
	   cout << "\n----Welcome to Hepsi Surada----" << endl
		   << "1-Checking the products" << endl
		   << "2-Re-arrenge the products" << endl
		   << "3-Re-stocking the items" << endl
		   << "4-Add product" << endl
		   << "5-Display the sales" << endl
		   << "6-Control Time" << endl
		   << "7-Return to main interface" << endl
		   << "8-Exit " << endl
		   << "Please choose your action: ";
	   cin >> oper;

	   switch (oper) {

	   case 1: {			//Displaying the Products
		   market.display(Day,Month);
		   break;
	   }

	   case 2: {			//Managing the Products

		   market.item_rearrenge();
		   break;
	   }

	   case 3: {			//Re-stocking the products

		   cout << "Please enter the Products Number which you want to re-stock: ";
		   cin >> item_number;

		  market.restock(item_number);
		   break;
	   }

	   case 4: {			//Add product

		   market.item_add();
		   break;
	   }

	   case 5: {			//Display the Sales
		   c = 5;
		   return_interface();
		   return 0;
		   break;
	   }

	   case 6: {	
		   c = 1;
		   return_interface();
		   return 0;
		   break;
	   }

	   case 7: {			//Returning the main interface
		   system("cls");
		   cout << endl << "Returning the main interface..." << endl;
		   cout << endl;
		   c = 7;
		   return_interface();
		   return 0;
		   break;
	   }


	   case 8:            // Exiting the program
		   cout << "Thank you for your hard work today." << endl;
		   exit(0);
		   return 0;
		   break;

	   default: {			//Error situation

		   cout << "Unfortunetly we don't know what this action is...." << endl;
		   break;
	   }
	   }

		
   }

}


int Manager::return_interface()
{
	return c;
}

