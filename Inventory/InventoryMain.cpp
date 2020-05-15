#include "stdafx.h"
#include "Menu.h"
#include "Inventory.h"


int main()
{
	string menuItems[] = {"add","modify","remove","display a product","display list", "exit"};
	Menu m ("exam", menuItems, 6, 10,10);
	int choice = m.displayMenu();

	Inventory inv;
	return 0;
}