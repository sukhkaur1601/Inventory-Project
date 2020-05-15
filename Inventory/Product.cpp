#include "stdafx.h"
#include "Product.h"

Product::Product() : Product(string{})
{}

Product::Product(const string& name) : _name{name}
{}

Product::~Product()
{}

void Product::setName(const string& name)
{
	_name = name;
}

const string& Product::getName() const
{
	return _name;
}