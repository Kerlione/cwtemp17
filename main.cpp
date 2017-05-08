#include <iostream>
#include "Client.h"
#include "Good.h"
#include "Order.h"

using namespace std;

enum Menu{EXIT=0,CLIENT,ORDER,STORAGE};

int main(int argc, char **argv)
{
	system("cls");
	cout << "---------------------------------FURNITURE SHOP APP---------------------------------" << endl;
	cout << "/n/n/t--MENU--/n/t/t1.Client base./n/t/t2.Order base./n/t/t3.Inventory./n/t/t0.Exit." << endl;
	cout << "Please select the option: ";
	int option;
	do
	{
	cin >> option;
	switch(option)
	{
		case CLIENT:
		{
			clientMenu();
		}
		case ORDER:
		{
			orderMenu();
		}
		case STORAGE:
		{
			goodMenu();
		}
		default: cout << endl << "An error occured. Please, enter your choise again: ";
	}
	}while(option<0||option>3);
	return 0;
}
