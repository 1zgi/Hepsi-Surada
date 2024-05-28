#include <iostream>
#include <string>
#include <iomanip>


#include "Sale-List.h"


using namespace std;

Sale_List::Sale_List()
{
	type[0] = "clothing";
	type[1] = "technology";
	type[2] = "food";
	type[3] = "sport";
	type[4] = "pet";
	type[5] = "beauty";

	saledays[0] = "New year";       // 0.7, 25, 12, 5, 1 //sport clothing food technology 
	saledays[1] = "Halloween";     //0.8, 31, 10, 7, 11 //food clothing
	saledays[2] = "Kurban Bayrami";//  0.8, 20, 7, 27, 7 // food 
	saledays[3] = "Nevruz Bayrami"; // 0.8, 21, 3, 28, 3 // sport clothing
	saledays[4] = "Summer break";   //0.7, 19, 6, 26, 6 // tecnology sport
	
	saleper[0] = 0.8; 
	saleper[1] = 0.7;   
	saleper[2] = 0.5;  
	saleper[3] = 0.4;
	saleper[4] = 0.6;
	
	startday[0] = 25;  
	startday[1] = 31;
	startday[2] = 20;
	startday[3] = 21;
	startday[4] = 19;


	startmonth[0] = 12;
	startmonth[1] = 10;
	startmonth[2] = 7;
	startmonth[3] = 3;
	startmonth[4] = 6;


	endday[0] = 5;
	endday[1] = 7;
	endday[2] = 27;
	endday[3] = 28;
	endday[4] = 26;

	
	endmonth[0] = 1;
	endmonth[1] = 11;
	endmonth[2] = 7;
	endmonth[3] = 3;
	endmonth[4] = 6;

}

int Sale_List::check(int day, int month) {

	if ((day >= 25 && month == 12) || (day <= 5 && month == 1))
		return 0;

	if ((day == 31 && month == 10) || day <= 7 && month == 11)
		return 1;

	if ((day <= 27 && day >= 20 && month == 7))
		return 2;

	if ((day <= 28 && day >= 21 && month == 3))
		return 3;

	if ((day <= 26 && day >= 19 && month == 6))
		return 4;

	return -1;

}


void Sale_List::sale_display() {

	cout << endl << std::left << setw(15) << "Name:" << setw(15) << "Start Date:" << setw(15) << "End Date:" << setw(15) <<"Percentage:"<< endl;

	for (int i = 0; i < 5; i++) {

		cout << std::left << setw(15) << saledays[i] << setw(2) << startday[i] << "." << setw(12) << startmonth[i] << endday[i] << "." << setw(13) << endmonth[i] << setw(15) << saleper[i]<<endl;
		
	}

	
}


Sale_List::~Sale_List() {

}

