#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include "User.h"
using namespace std;


class Time {

private:
	int Day;
	int Month;

public:

	Time();

	void get_Timebuying(int day, int month);
	void Time_Bar();
	int timer_day();
	int timer_month();
	void Menu_Time();
	int get_newDay();
	int get_newMonth();

	~Time();

};


