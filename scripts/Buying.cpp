#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

#include "Buying.h"

Buying::Buying()
{
	 total = 0;
	 a = 0;
	 count = 0;
}

void Buying::set_index(int a, int* amo, int* indx)
{
	
	
	count = a;
	
	for (int i = 0; i < count; i++)
	{
		miktar[i] = amo[i];
		index[i] = indx[i];
	}
	
}


void Buying::set_basket(int a, int* amo, int* indx)
{
	set_index(a,amo,indx);
	Market m;
	

	Bname = new string[count];
	Pname = new string[count];
	Ptype = new string[count];
	amount = new int[count];
	price = new double[count];
	
	for (int i = 0; i < count; i++)
	{
		Bname[i] = m.items[index[i]-1].Brand_name;
		Pname[i] = m.items[index[i]-1].Product_name;
		Ptype[i] = m.items[index[i]-1].Product_type;
		price[i] = m.items[index[i]-1].Product_price;
		
		amount[i] = miktar[i]; 
	}
	



	for (int i = 0; i < count; i++)
	{
		total += (price[i]* amount[i]);
	}

}


void Buying::buying(int day,int month) {

	Sale_List s;
	double indirim = 0;

	int check;
	check = s.check(day, month);

	if (!(check == -1)) {

		indirim = s.saleper[check];
		total = total - (indirim * total);
	}
	

	ofstream fatura;

	fatura.open("Fee.txt");

	fatura << "       ***   ***  *********  *********  *********  ****" << endl;
	fatura << "       ***   ***  *********  *********  *********  ****" << endl;
	fatura << "       ***   ***  ***        ***   ***  ***        ****" << endl;
	fatura << "       *********  ***        ***   ***  ***        ****" << endl;
	fatura << "       *********  *********  *********  *********  ****" << endl;
	fatura << "       *********  *********  *********  *********  ****" << endl;
	fatura << "       ***   ***  ***        ***              ***  ****" << endl;
	fatura << "       ***   ***  *********  ***        *********  ****" << endl;
	fatura << "       ***   ***  *********  ***        *********  ****" << endl;
	fatura << endl;
	fatura << "*********  ***   ***  *********  *********  *****        *********" << endl;
	fatura << "*********  ***   ***  *********  *********  *******      *********" << endl;
	fatura << "***        ***   ***  ***   ***  ***   ***  ***   ***    ***   ***" << endl;
	fatura << "***        ***   ***  ***   ***  ***   ***  ***     ***  ***   ***" << endl;
	fatura << "*********  ***   ***  *********  ***   ***  ***     ***  ***   ***" << endl;
	fatura << "*********  ***   ***  *********  *********  ***     ***  *********" << endl;
	fatura << "      ***  ***   ***  ******     *********  ***   ***    *********" << endl;
	fatura << "*********  *********  ***  ***   ***   ***  *******      ***   ***" << endl;
	fatura << "*********  *********  ***    **  ***   ***  *****        ***   ***" << endl << endl;

	fatura <<"Date: "<< day << " / " << month << endl;

	for (int i = 0; i < count; i++)
	{
		fatura << std::left << setw(15) << Bname[i] << setw(15) << Pname[i] << setw(15) << Ptype[i] << setw(15) << price[i] << setw(15) << amount[i] << setw(5) << amount[i]* price[i] << endl;
	}

	
	fatura << std::right << setw(77) <<"SALE: " << "% " <<indirim * 100<<endl;

	fatura << right << setw(77) << total  << endl << endl;

	fatura << "Hepsi Surada CO. is a Kanatlý&Karabay company all its\n fairshares are classified by its share holders\n And after 3 milisecond after you get the Fee.txt the rights of \nrefunding the product(s) is(are) out of services" << endl;
	fatura << "Thank you for choosing Hepsi Surada as your retailer of products..." << endl;

	fatura.close();
}


Buying::~Buying()
{
	delete[]Bname;
	delete[]Pname;
	delete[]Ptype;
	delete[]price;
	delete[]amount;
}