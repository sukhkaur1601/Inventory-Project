#ifndef __DATE_H
#define __DATE_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int j, int m, int a);
	string getDate();
};

#endif