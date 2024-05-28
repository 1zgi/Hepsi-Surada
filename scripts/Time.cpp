
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

#include "Time.h"

using namespace std;

Time::Time()
{

}

int Time :: timer_day() {

	int day;

	day = rand() % 32;			//randomly choosen day

	if (day == 0) {				//Error sitaution

		day++;
	}

	Day = day;

	return day;
}

int Time :: timer_month() {

	int month;

	month = rand() % 8;			//modified random cause of our sale raito

	if (month == 0) {			//Error sitaution

		month++;
	}

	switch (month)
	{

	case 2: {

		month = 3;
		Month = month;
		break;
	}

	case 3: {

		month = 6;
		Month = month;
		break;
	}

	case 4: {

		month = 7;
		Month = month;
		break;
	}

	case 5: {

		month = 10;
		Month = month;
		break;
	}

	case 6: {

		month = 11;
		Month = month;
		break;
	}

	case 7: {

		month = 12;
		Month = month;
		break;
	}
		  
	default:
		 Month = month;
	     break;
	}

	return month;
}

void Time::Time_Bar()
{
	
	cout << "Date: " << Day << "/" << Month << endl;

	get_Timebuying(Day, Month);
}


void Time::get_Timebuying(int day,int month)
{
	
	day = Day;
	month = Month;
}

int Time::get_newDay()
{
	return Day;
}

int Time::get_newMonth()
{
	return Month;
}


void Time::Menu_Time()
{
	int order, dayVal, monthVal, a = 1;

	while (a == 1)
	{
		system("cls");
		//cout << "Date: " << Day << "/" << Month << endl;
		Time_Bar();

		cout <<"---BACK TO THE FUTURE---\n"
			<< "1-Random date\n"
			<< "2-Next Day\n"
			<< "3-Choose Date\n"
			<< "4-Return Menu" << endl;
		cout << "Please choose your action: ";
		cin >> order;

		switch (order)
		{
		case 1:
			Day = timer_day();
			Month = timer_month();
			break;

		case 2:
			if (Day == 31)
			{
				Day = 1;
				if (Month == 12)
				{
					Month = 1;
					get_newMonth();
				}

				else
				{
					Month++;
					get_newMonth();
				}
					

			}

			else
			{
				Day++;
				get_newDay();
			}

			break;

		case 3:
			cout << "Please choose day and month: ";
			cin >> dayVal >> monthVal;

			if ((dayVal > 31) || (monthVal > 12))
			{
				cout << "ERROR..." << endl;
			}

			else
			{
				Day = dayVal;
				Month = monthVal;
				get_newDay();
				get_newMonth();
			}
			break;

		case 4:
			return;
			break;

		default:
			cout << "This kind of action is unreadable." << endl;
			break;
		}

	}

}


Time::~Time()
{

}