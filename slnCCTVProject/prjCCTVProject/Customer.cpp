#pragma once
#include "User.cpp"

class Customer : User {
private:
	std::string type;

public:
	// Constructor to initialize the customer type
	Customer(std::string type) {
		this->type = type;
	}

	Customer() {}

	// Method to get the customer type
	std::string getType() {
		return type;
	}

	// Method to set the customer's phone number
	void setPhone(Phone_Number phone) {
		// Set the customer's phone number
		getAccount().setPhone(phone);
	}

	// Method to set the customer's address
	void setAddress(Address address) {
		// Set the customer's address
		getAccount().setAddress(address);
	}

	// Method to get the customer's total sales number
	std::string getSalesNumber() {
		// Return the customer's total sales number
		return "773-202-7777";
	}

};