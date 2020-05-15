#include "stdafx.h"
#include "Inventory.h"
#include <algorithm>
#include <iostream>

Product** Inventory::GetBeginProduct()
{
	return _products;
}

Product** Inventory::GetEndProduct()
{
	return _products + _productsCount;
}

void Inventory::DeleteRange(Product** first, Product** last)
{
	for_each(
		first, last,
		// A lambda for deleting each individual product.
		[](Product* product) {if (product != nullptr) delete product; });
}

Inventory::Inventory()
{
	_productsCount = 0;
	_maxProductCount = 1;
	_products = new Product*[1];
}

Inventory::~Inventory()
{
	if (_productsCount > 0)
		DeleteRange(GetBeginProduct(), GetEndProduct());

	delete _products;
}

bool Inventory::Add(Product *newProduct)
{
	if (newProduct == nullptr)
		return false;

	if (_productsCount == _maxProductCount)
	{
		// Expand the vector of products.
		Product** newProducts;
		int newMaxProductCount = 2 * _maxProductCount;

		try
		{ 
			// Attempt to allocate a new larger array.
			newProducts = new Product*[newMaxProductCount];
		}
		catch (bad_alloc ex)
		{
			// Whenever no heap memory available, nothing change.
			return false;
		}

		// Copy the existing products in the new larger array.
		copy(GetBeginProduct(), GetEndProduct(), newProducts);
		
		// Delete the old products array and upddate with new larger array and maximum size.
		delete _products;
		_products = newProducts;
		_maxProductCount = newMaxProductCount;
	}

	// Save the new product and increment the counter.
	_products[_productsCount] = newProduct;
	++_productsCount;
	return true;
}
Product* Inventory::FindByName(const string& name) {
	auto first = GetBeginProduct();
	auto last = GetEndProduct();
	auto productOfName = find_if(
		_products, last,
		// A lambda for searching a product with the specified name.
		// The [&] allows reference to local variables and parameters.
		[&](const Product* product) { return product != nullptr && product->getName() == name; });

	return productOfName == last ? nullptr : *productOfName;
}
Product* Inventory::FindbyRank(int rank)
{
	if (rank < 0 || rank >= _productsCount)
		return nullptr;

	return _products[rank];
}

bool Inventory::RemoveByName(const string& name)
{
	auto first = GetBeginProduct();
	auto last = GetEndProduct();
	auto productOfName = find_if(
		_products, last,
		// A lambda for searching a product with the specified name.
		// The [&] allows reference to local variables and parameters.
		[&](const Product* product) { return product != nullptr && product->getName() == name; });

	if (productOfName == last)
		return false;

	// Delete the product.
	auto nextOfProductOfName = productOfName + 1;
	DeleteRange(productOfName, nextOfProductOfName);

	// Pack the array of products.
	copy(nextOfProductOfName, last, productOfName);
	_productsCount -= 1;
	return true;
}

void Inventory::DisplayAll()
{
}
