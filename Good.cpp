#import "Good.h"
#include <string.h>

enum Menu{BACK = 0, VIEW, ADD, DELETE, SEARCH, CHANGE};

goodMenu()
{
    cout << "---------------------------------FURNITURE SHOP APP---------------------------------" << endl;
	cout << "/n/n/t--MENU--/n/t/t1.View inventory./n/t/t2.Add an item./n/t/t3.Delete an item./n/t/t4.Search for an item./n/t/t5.Modify an item./n/t/t0.Back to main menu." << endl;
	cout << "Please select the option: ";
	int option;
	do
	{
	cin >> option;
	switch(option)
	{
		case VIEW:
		{
			viewInventory();
		}
		case ADD:
		{
			addGood();
		}
		case DELETE:
		{
			deleteGoodMenu();
		}
        case SEARCH:
        {
            goodSearchMenu();
        }
        case MODIFY:
        {
            goodModify();
        }
        case BACK:
        {
            main(NULL);
        }
        default: cout << endl << "An error occured. Please, enter your choise again: ";
	}
	}while(option<0||option>5);
}

viewInventory() // TODO normal databese view
{
	int size = 0;
	int goodCount = 0;
	system("cls");
	cout << "--------------------VIEW DATABASE--------------------" << endl;
	i.seekg(0, i.end);
	size = i.tellg();
	i.seekg(0);
	goodCount = size / sizeof(Good);
	Good *goods = new Good[goodCount];
	i.read((char *)goods, size);
	for (int i = 0; i < goodCount; i++)
	{
		cout << goods[i].goodnum << " " << goods[i].name << " " << goods[i].size << " " << goods[i].color << " " << goods[i].count << endl;
	}
	i.close();
	delete[] goods;
	system("pause");
	menu();
}

searchGoodMenu()
{
    int choice;
    cout << "--------------------GOOD SEARCH MENU--------------------" << endl;
    cout << "/t/t1.By code./n/t/t2.By name./n/t/t3.By size./n/t/t4.By availability./n/t/t0.Return back." << endl;
    cout << "Please, enter your choise> ";
    cin >> choise;
    switch (choise)
    {
        case 1: 
        {
            cout << "/n---------------------------------------------------------";
            cout << "Note: Good's code is TXXXX, where T is type of furniture and XXXX digits"
            cout << "Please, enter a code you want to search for> ";
            char code[6];
            cin.ignore();
            cin >> code;
            goodSearch(code);
        }
        break;
        case 2: nameSearch();
        break;
        case 3: sizeSearch();
        break;
        case 4: numSearch();
        break;
        case 0: menu();
        break;
        default: 
        {
            cout << "An invalid choise detected."<< endl;
            system("pause");
            searchGoodMenu();
        }
    }
}

goodSearch(char *code[6])
{
    int size = 0;
    int goodCount = 0;
    system("cls");
    cout << "--------------------SEARCH BY CODE--------------------" << endl;
    cout << "You were searching for " << code << ". Here are the results:" << endl;
    i.seekg(0, i.end);
    size = i.tellg();
    i.seekg(0);
    goodCount = size/sizeof(Good);
    Good *goods = new Good[goodCount];
    i.read((char*)goods, size);
    int result_count = 0;
    for (int i = 0; i < goodCount; i++)
    {
        if (!strcmp(code,goods[i].goodnum))
        {
            result_count++;
        }
    }
    if (result_count==0)
    {
        cout << "Nothing found by your criteria. Would you like to place a custom order?[y/n]" << endl;
        char answ;
        do
        {
        cin >> answ;
        switch (answ)
        {
            case 'y': customOrder(code);
            case 'Y': customOrder(code);
            case 'n': 
            {
                cout << "Taking you to the Search menu." << endl;
                system("pause");
                goodSearchMenu();
            }
            case 'N': 
            {
                cout << "Taking you to the Search menu." << endl;
                system("pause");
                goodSearchMenu();
            }
            default: cout << "Incorrect input detected. Please, enter your decision again: ";
        }
        }while(answ!='y'||answ!='Y'||answ!='n'||answ!='N');
    }
    else
    {
    int *results = new int[result_count];
    for (int i=0, n=0; i < goodCount; i++)
    {
        if(!strcmp(code, goods[i].goodnum))
        {
            results[n]=i;
            n++;
        }
    }
    for (int i = 0; i < result_count; i++)
    {
       cout << i+1 << " " << goods[results[i]].name << " " << goods[results[i]].size << " " << goods[results[i]].color << " " << goods[results[i]].count << endl; 
    }
    cout << "Have you found what you were looking for?[y/n]" << endl;
    char answ;
    cin >> answ;
    int chosen;
    switch (answ)
    {
        case 'y': 
        {
            cout << "Please, enter the chosen good number from the list above: ";
            cin >> chosen;
            system("cls");
            cout << "You have chosen this good:" << endl;
            cout << goods[i].goodnum << " " << goods[i].name << " " << goods[i].size << " " << goods[i].color << " " << goods[i].count << endl;
            cout << endl;
            if (goods[results[chosen]].count==0)
                cout << "Do you want to order it?" << endl;
                else
                cout << "Do you want to purchase it?" << endl;
                cin >> answ;
                switch (answ)
                {
                    case 'y':
                }
        }
        case 'Y':
        case 'n':
        case 'N':
        default:
    }
    }
    i.close();
    
}