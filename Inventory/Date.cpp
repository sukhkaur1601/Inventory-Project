#include "stdafx.h"
#include "Date.h"

Date::Date(int j, int m, int a)
{
	day=j;
	month=m;
	year=a;
}

string Date::getDate()
{
	stringstream s;
	s <<year<< "/" << month << "/"<<day;
	return s.str();
}