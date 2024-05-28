#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include "basket.h"

using namespace std;

int Basket::counter = 0;

void Basket::Basket_display(int day, int month)
{
	total = 0;
	Sale_List s;
	double indirim = 0;
	int check;
	check = s.check(day, month);

	if (!(check == -1)) {

		indirim = s.saleper[check];
		cout<<endl << "We are in " << s.saledays[check] << "! %"<< s.saleper[check] <<" amount of dicount is active!"<< endl;
	}

	cout << endl;
	cout << std::left << setw(15) << "Brand Name:" << setw(15) << "Product Type:" << setw(15) << "Product Name:" << setw(20) <<"Product Number: "<< setw(10) << "Amount:" << setw(15) << "Discount %:" << setw(15) << "Total Price:" << endl;
	for (int i = 0; i < counter; i++)
	{
	  tot = amount[i] * Product_price[i] * 1.0;
	  tot = tot - (indirim * tot);
	  cout << left << setw(15) << Brand_N[i]<< setw(15) << Product_T[i] << setw(15) << Product_N[i] << setw(20) <<in[i] <<setw(20) <<amount[i] << setw(10) <<  indirim << setw(15) << tot << endl;
	  total += tot;
	}
	
}


void Basket::Basket_add(int day, int month) //Adding an Product to the customer's basket
{		
	Market m;
	int code, adet, check = 1, i, a, b,s = 0;
	string answer;
	int flag = 0;
	 count = m.Return_Count();
	 counter = 0;
	 string answer_add, answer_remove="lol";
	 int shop = 0;


	while (check)
	{

		cout << endl;
		cout << "Please enter the Product Number which you want to buy: ";
		cin >> code;

		for (i = 0; i < count; i++) {

			if (code == m.items[i].Product_number) {

				check = 1;
				break;
			}
		}

		if (check == 1) {

			cout << "How many products you want to buy: ";
			cin >> adet;

			if (m.items[i].Product_stock == 0)
			{
				
				cout << "Unfortunetly we don't have any stock for this product." << endl;
				cout << endl;
				cout << "If you want , we can send a message to manager to re-stock the product you want: ";
				cin >> answer;

				if ((answer == "Yes") || (answer == "yes")) {

					cout << "We are sending the message to manager." << endl
						<< "this situation can be long please come again later." << endl;

					m.restock(i);
				}

				else {

					cout << "We are also sending message to manager." << endl
						<< "Returning the main menu." << endl;
					cout << endl;
				}
			}

			else if (adet <= m.items[i].Product_stock) {
				    
				    shop = 1;
				
					m.items[i].Product_stock -= adet;
					kalan = m.items[i].Product_stock;
					indx = i;
					get_amount();
					get_i();
					
					cout << "Item has been added to your basket: \n" << endl;
					Brand_N[counter] = m.items[i].Brand_name;
					Product_N[counter] = m.items[i].Product_name;
					Product_T[counter] = m.items[i].Product_type;
					Product_price[counter] = m.items[i].Product_price;


					


					amount[counter] = adet;
					in[counter] = indx+1;
					counter++;
					
			}

			



			else {

				//asking for adding current stock to the basket
				cout << "Unfortunetly we don't have enough stock in this Product. Would you like to buy current stock: ";
				cin >> answer;

				if ((answer == "Yes") || (answer == "yes"))
				{
					shop = 1;
					amount[counter] = m.items[i].Product_stock;
					m.items[i].Product_stock = 0;
					indx = i;
					Brand_N[counter] = m.items[i].Brand_name;
					Product_N[counter] = m.items[i].Product_name;
					Product_T[counter] = m.items[i].Product_type;
					Product_price[counter] = m.items[i].Product_price;
					in[counter] = indx;
					counter++;	
					
				}

				//asking for restock the Product
				else {

					cout << "If you want we can send a message to manager to re-stock the product you want: ";
					cin >> answer;

					if ((answer == "Yes") || (answer == "yes")) {

						cout << "We are sending the message to manager." << endl
							<< "this situation can be long please come again later." << endl;

						m.restock(i);
					}

					else {

						cout << "We are also sending message to manager." << endl
							<< "Returning the main menu." << endl;

					}
				}
			
			}

		}
	
		//Error situation
		else {

			cout << "Unfortunetly we couldn't find the Product you mentioned." << endl
				<< "Returning the main menu." << endl;

			return;
		}
		
		cout << "Would you like to add another item to your basket: ";
		cin >> answer;

		if ((answer == "No") || (answer == "no")) {
			cout << "Would you like to remove an item from your basket: ";
			cin >> answer_remove;
			while (!(answer_remove == "no" || answer_remove == "No"))
			{
				int code, adet, check = 0, i, l;
				string answer;

				//checking
				cout << "Your current basket is: " << endl << endl;

				Basket_display(day, month);

				cout << "Please enter the Product Number which you want to remove: ";
				cin >> code;

				//Searching for the product
				for (i = 0; i < counter; i++) {

					if (code == in[i]) {

						check = 1;
						break;
					}
				}
		
				//if list have the product enough
				if (check == 1) {

					cout << "How many product you want to remove: ";
					cin >> adet;

					if (adet <= amount[i]) {

						for (int k = 0; k < m.Return_Count() ; k++) {

							if (code == m.items[k].Product_number) {

								m.items[k].Product_stock += adet;
								amount[i] -= adet;
								
								m.re_write_itemlist();

								if (amount[i] == 0) {

									for (k = i, l = i + 1 ; l < counter; l++, k++) {

										Brand_N[k] = Brand_N[l];
										Product_N[k] =	Product_N[l];
										Product_T[k] = Product_T[l];
										Product_price[k] = Product_price[l];
										amount[k] = amount[l];
										
									}

									counter--;
								}

								cout << "We removed Product Number " << code << " as you want." << endl;
								break;
							}
						}
					}

					//Error situation
					else {

						cout << "You don't have that many item in your basket. Please try again." << endl << "Returning the main menu." << endl;
						return;
					}
				}
				cout << "Would you like to remove another item from your basket: ";
				cin >> answer_remove;
			}

			
			check = 0;
			cout << "Your final basket is: " << endl;

			Basket_display(day, month);

			cout << endl;
			if (shop) {
				cout << "Would you like to purchase now: ";
				cin >> answer;

				if ((answer == "Yes") || (answer == "yes"))
				{
					cout << "Total payment is: " << total << endl;

					m.re_write_itemlist();
					Buying buy;
					buy.set_basket(counter, amount, in);
					buy.buying(day, month);
					empty_array();
					cout << "Thanks for choosing us!" << endl;
				}
				else
				{
					cout << endl;
					cout << "WARNING: Your order had canceled." << endl;
					cout << "Returning to the main menu..." << endl;
					return;
				}
			}
		}	
	}
	
}


void Basket::empty_array() {
	
	std::fill_n(Brand_N, counter, 0);
	std::fill_n(Product_N, counter, 0);
	std::fill_n(Product_T, counter, 0);
	std::fill_n(Product_price, counter, 0);
	std::fill_n(amount, counter, 0);
	counter = 0;

}


int Basket::get_i()
{
	return indx;
}

int Basket::get_amount()
{
	
	//cout << kalan<<endl;
	return kalan;
	
}


Basket::~Basket()
{

}

