#ifndef __INVENTORY_H
#define __INVENTORY_H

#include <iostream>
using namespace std;

#include "Product.h"

/* This class manages a linked list of Product items.

Requirements:
1-you must have a class named Product
2-In Product class you must have a public data member: Product *NextItem = NULL;
3-In Product class you must have a public function Display()
4-When creating a new product object, you must use dynamic memory allocation
*/

class Inventory
{
	Product** _products;
	int _productsCount;
	int _maxProductCount;

	Product** GetBeginProduct();
	Product** GetEndProduct();
	void DeleteRange(Product** first, Product** last);

public:
	Inventory();
	~Inventory();

	bool Add(Product *newProduct);			 // input is a pointer to the product to be added to the list. The product must have been created dynamically.
	Product* FindByName(const string& name); // output is a pointer to the product found, or NULL if not found
	Product* FindbyRank(int rank);			 // output is a pointer to the product found, or NULL if not found
	bool RemoveByName(const string& name);   // output is true if the product was removed, false if the porduct was not found. The memory allocated will be freed.
	void DisplayAll();						 // displays the list of all products using the Display() funtion you must provide in the Product class
};

#endif