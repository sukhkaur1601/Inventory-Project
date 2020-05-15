#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>

using namespace std;

enum ProductType {SHOE, PIE};

class Product
{
	string _name;

public:
	Product();
	Product(const string& name);
	virtual ~Product();

	void setName(const string& name);
	const string& getName() const;
};

#endif