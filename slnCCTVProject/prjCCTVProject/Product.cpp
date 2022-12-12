#pragma once
#include <string>

class Product {
private:
	float cost;
	int quantity;
	std::string name;
	std::string category;
	std::string subcategory;

public:
	// Constructor
	Product(float cost, int quantity, std::string name, std::string category, std::string subcategory)
		: cost(cost), quantity(quantity), name(name), category(category), subcategory(subcategory) {}

	// Getters
	float getCost() { return cost; }
	int getQuantity() { return quantity; }
	std::string getName() { return name; }
	std::string getCategory() { return category; }
	std::string getSubCategory() { return subcategory; }

	// Setters
	void setCost(float cost) { this->cost = cost; }
	void setQuantity(int quantity) { this->quantity = quantity; }
	void setName(std::string name) { this->name = name; }
	void setCategory(std::string category) { this->category = category; }
	void setSubCategory(std::string subcategory) { this->subcategory = subcategory; }
};