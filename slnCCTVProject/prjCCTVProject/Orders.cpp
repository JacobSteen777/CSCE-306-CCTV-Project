#pragma once
#include "Product.cpp"

class Orders {
private:
	Product product;
	int amount;

public:
	// Constructor
	Orders(Product product, int amount) : product(product), amount(amount) {}

	// Getters
	Product getProduct() { return product; }
	int getAmount() { return amount; }

	// Setters
	void setAmount(int amount) { this->amount = amount; }
	void setProduct(Product product) { this->product = product; }

	// Other methods
	void removeOrder() { amount = 0; }
};