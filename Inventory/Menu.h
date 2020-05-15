//menu class


#ifndef __MENU_H
#define __MENU_H

#include <iostream>
using namespace std;
#include <string>
#include <windows.h>	//for Sleep and gotoXY and COORD
#include <conio.h>	//for getch
#include <ctype.h>	//for tolower

//the Menu class for managing arrow key input
class Menu{
	string _title;
	int _nbItem;
	string* _choiceList;
	COORD cornerUL;
	//internal management
	COORD _currentPos;
	COORD _lastPos;
	COORD _firstPos;
	int choice;

protected:
	void move(COORD origin, COORD target);
	int getMaxSize();
	void gotoXY(COORD pos);
	void init();


public:
	Menu(string title, string* choiceList, int nbItem, int startLine, int startColumn);
	~Menu();
	int displayMenu();
	void gotoXY(int c, int l);
};

#endif