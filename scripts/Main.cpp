#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "Customer.h"
#include "manager1.h"
#include "User.h"
#include "Time.h"

using namespace std;

int Account(int action)
{
	action = 0;
	int c = 0;
	cout << "WELCOME TO HEPSI SURADA!" << endl<<endl;
	cout << "1-Customer account" << endl
		<< "2-Manager account" << endl
		<< "Please choose the type of the account: ";
	cin >> action;
	c = action;
	cout << endl;
	return c;
}


int main() {

	Market market;

	int check = 0, action = 0, oper;
	int sign = 0;
	int p=0;
	int counter = 0;
	int r = 0; // bridge val
	int a;
	int Day;
	int Month;
	int c = 0;

	string name;
	string l_name;
	string id;
	string pw;
	string idcheck;
	srand(time(NULL));

	Time t;
	Customer c1;
	Manager m1;
	User nav;//User navigation
	Sale_List s_l;

	Day = t.timer_day();
	Month = t.timer_month();
	c1.set_time(Day, Month);
	m1.set_time(Day, Month);

	while (check == 0) {
		
		action = Account(action);

		if (action == 1)
		{
			cout << "1-Sign up" << endl;
			cout << "2-Sign in" << endl;
			cout << "3-Return account selection interface" << endl;
			cout << "Please choose the type of the sign: ";
			cin >> sign;
			cout << endl;
		}

		//Action Connection
		switch (action)
		{
		case 1://Customer
			if (sign == 1)
			{
				nav.Create_AccountCustomer();
				name = nav.getName();
				l_name = nav.getLast_Name();
				id = nav.getID();
				pw = nav.getPassword();
				c1.Entrance_CustomerInfo(name, l_name, id, pw);
				t.Time_Bar();

				while (c == 0)
				{
					a = c1.Return_interface();
					if (a == 1)
					{
						s_l.sale_display();
						c1.Main_Customer();
					}

					if (a == 3)
					{
						break;
					}
				}

			}
		
			if (sign == 2)
			{
				t.Time_Bar();
				c1.Log_in_Customer();

				while (c == 0)
				{
					a = c1.Return_interface();
					if (a == 1)
					{
						s_l.sale_display();
						c1.Main_Customer();
					}

					if (a == 3)
					{
						break;
					}


				}

			}

			if (sign == 3)
			{
				action = 0;
			}

			nav.getAction(p);
			action = p;
			if (action == 4)
			{
				Account(action);
			}

			break;


		case 2://Manager
			m1.TakeInfo_Manager();
			cout << endl;
			t.Time_Bar();
			m1.Main_Manager();
			r = 0;
			
			
			while (c == 0)
			{
				r = m1.return_interface();
				if (r == 1)
				{
					int d;
					int m;
					t.Menu_Time();
					d = t.get_newDay();
					m = t.get_newMonth();
					c1.set_time(d, m);
					m1.Main_Manager();
	
				}

				if (r == 5)
				{
					s_l.sale_display();
					m1.Main_Manager();
				}

				if (r == 7)
				{
					break;
				}

			}
			break;

		default:
			break;
		}
	}

	return 0;
}