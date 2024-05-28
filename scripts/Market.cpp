#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "Market.h"


using namespace std;

Market::Market() {								//Default constructor

	Read_Item_Info_Text();
	index = 0;
	C = 0;
}

Market::Market(char a) {						//starting market constructor
	
}


void Market::Read_Item_Info_Text()
{

	counter = 0;
	text_file_items.open("Items.txt", ios::in);//in -> text okumak için

	if (text_file_items.is_open() == true)
	{

		while (getline(text_file_items, file))
		{
			if (file == "------------------")
			{
				file = '\0';
				counter++;
			}

			//cout << file << endl;//seing account list 

		}

		//cout << index << endl;//TEST


	}

	//cout << counter << endl;//Test counter

	items = new Item[counter];

	text_file_items.close();

	setInfosfromText();

}


void Market::setInfosfromText()//Filling Account infos from text file.
{
	int c = 0;
	int i = 0;
	int j = 0;
	int b_n = 0, p_n = 0, p_t = 0, p_p = 0, m_s = 0, c_s = 0, p_num = 0;
	int* controler;
	controler = new int[counter];

	text_file_items.open("Items.txt", ios::in);
	if (text_file_items.is_open() == true)
	{
		while (getline(text_file_items, file))
		{
			i++;
			if (file == "------------------")
			{
				controler[c] = i;//Leaving check points where the line is  "------------------" .
								 //So we can track every single item position in text file.
				c++;

			}
		}
	}
	text_file_items.close();

	text_file_items.open("Items.txt", ios::in);

	if (text_file_items.is_open() == true)
	{
		c = 0;
		while (getline(text_file_items, file))
		{
			j++;

			if (j == (controler[c] - 7))
			{

				items[b_n].Brand_name = file;
				
				b_n++;

			}


			if (j == (controler[c] - 6))
			{

				items[p_n].Product_name = file;
				
				p_n++;

			}


			if (j == (controler[c] - 5))
			{

				items[p_t].Product_type = file;
				
				p_t++;

			}

			if (j == (controler[c] - 4))
			{

				items[p_p].Product_price = stod(file);
				
				p_p++;

			}

			if (j == (controler[c] - 3))
			{

				items[m_s].Product_stock_max = stoi(file);
				
				m_s++;

			}

			if (j == (controler[c] - 2))
			{

				items[c_s].Product_stock = stoi(file);
				
				c_s++;

			}

			if (j == (controler[c] - 1))
			{

				items[p_num].Product_number = stoi(file);
				
				p_num++;
				c++;
			}
		}
	}
	text_file_items.close();
	delete[] controler;

	
}

int Market::Return_Count()
{
	int count = 0;
	text_file_items.open("Items.txt", ios::in);

	if (text_file_items.is_open() == true)
	{
		while (getline(text_file_items, file))
		{

			if (file == "------------------")
			{

				count++;

			}
		}
	}

	text_file_items.close();

	return count;
}

void Market::re_write_itemlist()
{
	fstream f;
	f.open("Items.txt", ios::in|ios::out);
	int count= 0;
	for(int i = 0;i< Return_Count();i++)
	if (f.is_open() == true)
	{
		
		f << items[i].Brand_name<< endl;
		f << items[i].Product_name<< endl;
		f << items[i].Product_type<< endl;
		f << items[i].Product_price << endl;
		f << items[i].Product_stock_max << endl;
		f << items[i].Product_stock << endl;
		f << count+1 << endl;
		f << "------------------" << endl;
		count++;
	}
	
	f.close();
}

void Market::display(int day,int month) {						//Display menu
	Basket b;
	int a;
	
	cout <<"1) All Products" << endl
		<< "2) Search by Brand" << endl
		<< "3) Search by Type" << endl
		<< "4) Search by Name" << endl
		<< "5) ADD ITEMS TO YOUR BASKET"<<endl
		<< "6) Return to previous page" << endl
		<< "Please choose your action: ";
	cin >> a;


	switch (a)
	{
	case 1: {									//Display all products
		cout << endl << std::left << setw(15) << "Brand Name:" << setw(15) << "Product Type:" << setw(15) << "Product Name:" << setw(20) << "Product Number:" << setw(15) << "Stock:" << setw(5) << "Price:" << endl;
		Read_Item_Info_Text();
		for (int i = 0; i < Return_Count(); i++) {
			
			cout << left << setw(15) << items[i].Brand_name << setw(15) << items[i].Product_type << setw(15) << items[i].Product_name << setw(20) << items[i].Product_number << setw(15) << items[i].Product_stock << setw(5) << items[i].Product_price << endl;
		}
		break;
	}

	case 2: {									//Display via Brand

		Market::display_Brand();
		
		break;
	}

	case 3: {									//display via Type

		Market::display_Type();

		break;
	}

	case 4: {									//Display via Name

		Market::display_Name();
		break;
	}

	case 5: {
		b.Basket_add(day,month);
		wh_item = b.get_i();

		items[wh_item].Product_stock=b.get_amount();
		break;
	}

	case 6: {

		return;
		break;
	}

	default: {

		cout << "\nWe didn't understand the action so we are sending you back.\n";
		break;
	}
	}
}


void Market::display_Brand() {					//Display via Brand
	
	string a;
	int check = 0;

	cout << "Please enter the brand which you want to see: ";
	cin >> a;

	cout << endl << std::left << setw(15) << "Brand Name:" << setw(15) << "Product Type:" << setw(15) << "Product Name:" << setw(20) << "Product Number:" << setw(15) << "Stock:" << setw(5) << "Price:" << endl;
	cout << endl;
	for (int i = 0; i < Return_Count(); i++) {

		if (items[i].Brand_name == a) {

			cout << left << setw(15) << items[i].Brand_name << setw(15) << items[i].Product_type << setw(15) << items[i].Product_name << setw(20) << items[i].Product_number << setw(15) << items[i].Product_stock << setw(5) << items[i].Product_price << endl;
			check = 1;
		}
	}

	if (check == 0)
	{
		cout << endl;
		cout << "WARNING: There is no thing with this name of Brand in our stock. Please try to search again." << endl;
		return;
	}
	
}

void Market::display_Name() {					//Display via Name

	string a;
	int check = 0;

	cout << "Please enter the name of the product which you want to see: ";
	cin >> a;
	cout << endl << std::left << setw(15) << "Brand Name:" << setw(15) << "Product Type:" << setw(15) << "Product Name:" << setw(20) << "Product Number:" << setw(15) << "Stock:" << setw(5) << "Price:" << endl;
	cout << endl;
	for (int i = 0; i < Return_Count(); i++) {

		if (items[i].Product_name == a) {

			cout << left << setw(15) << items[i].Brand_name << setw(15) << items[i].Product_type << setw(15) << items[i].Product_name << setw(20) << items[i].Product_number << setw(15) << items[i].Product_stock << setw(5) << items[i].Product_price << endl;
			check = 1;
		}
	}

	if (check == 0)
	{
		cout << endl;
		cout << "WARNING: There is no thing with this name of product in our stock. Please try to search again." << endl;
		return;
	}
	

}

void Market::display_Type() {					//Display via Type

	string a;
	int check = 0;

	cout << "Please enter the type of the product which you want to see: ";
	cin >> a;

	cout << endl << std::left << setw(15) << "Brand Name:" << setw(15) << "Product Type:" << setw(15) << "Product Name:" << setw(20) << "Product Number:" << setw(15) << "Stock:" << setw(5) << "Price:" << endl;
	cout << endl;
	for (int i = 0; i < Return_Count(); i++) {

		if (items[i].Product_type == a) {

			cout << left << setw(15) << items[i].Brand_name << setw(15) << items[i].Product_type << setw(15) << items[i].Product_name << setw(20) << items[i].Product_number << setw(15) << items[i].Product_stock << setw(5) << items[i].Product_price << endl;
			check = 1;
		}
	}

	if (check == 0)
	{
		cout << endl;
		cout << "WARNING: There is no thing with this type of product in our stock. Please try to search again." << endl;
		return;
	}

}

void Market::item_rearrenge() {				//rearrenge the stock
	int b, check = 0;
	int c;
	string a;

	//display by permission
	cout << "Do you want us to show all Products: ";
	cin >> a;

	cout << endl;

	if (a.compare("Yes") == 0) {
		c = 0;
		display(Day,Month);
	}

	cout << "Please enter the Product number which you wanted to change: ";
	cin >> b;

	for (int i = 0; i < Return_Count(); i++) {

		//getting info for  Product arrangement
		if (b == items[i].Product_number) {

			check = 1;

			cout << "Please enter the new Type: ";
			cin >> items[i].Product_type;

			cout << "Please enter the new Brand name: ";
			cin >> items[i].Brand_name;

			cout << "Please enter the new Name: ";
			cin >> items[i].Product_name;

			cout << "Please enter the new Price: ";
			cin >> items[i].Product_price;

			cout << "Please enter the new max stock: ";
			cin >> items[i].Product_stock_max;

			cout << "Please enter the current stock: ";
			cin >> items[i].Product_stock;
		}
	}

	//Error Situation
	if (check == 0) {

		cout << "\nWe dont have this Product in our market." << endl;
	}

	re_write_itemlist();
}

void Market::item_add() {			//add Product

	int count;
	
	count = Return_Count();

	string brand,p_name,p_type;
	double price;
	int max, current, num;

	
	cout << "Enter brand name: ";
	cin>>brand;
	cout << "Enter product name: ";
	cin>>p_name;
	cout << "Enter product type: ";
	cin >> p_type;
	cout << "Enter product price: ";
	cin >> price;
	cout << "Enter max stock: ";
	cin >> max;
	cout << "Enter current stock: ";
	cin >> current;

	text_file_items.open("Items.txt", ios::in | ios::out | ios::ate);// Bu þekilde dosyamýz her seferin de yeniden oluþturulmuyor(in i eklememizin sebebi) in ->dosyayý okumak için açar, out -> text yazma modu, ate -> sonuna eklemek için açar

	if (text_file_items.is_open() == true)
	{
		text_file_items << brand << endl;
		text_file_items << p_name << endl;
		text_file_items << p_type << endl;
		text_file_items << price << endl;
		text_file_items << max << endl;
		text_file_items << current << endl;
		text_file_items << count+1 << endl;
		text_file_items << "------------------" << endl;
	}
	
	text_file_items.close();
	
}

void Market::restock(int code) {			//Restocking choosen product		

	int i;

	for (i = 0; i < Return_Count() ; i++) {

		if (code + 1 == items[i].Product_number) {

			items[i].Product_stock = items[i].Product_stock_max;
			break;
		}
	}
	re_write_itemlist();
	cout << "Product which Product Number is " << code + 1 << " is re-stocked." << endl;
}

Market::~Market() {						//Destroyer

	delete[] items;
}