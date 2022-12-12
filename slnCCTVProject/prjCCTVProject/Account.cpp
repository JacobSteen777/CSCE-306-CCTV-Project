#pragma once
#include <string>
#include "Address.h"
#include "Phone_Number.cpp"

class Account {
private:
	std::string userID;
	Address address;
	Phone_Number phone;
	std::string name;

public:
	// Constructor to initialize the user ID, address, phone number, and name
	Account(std::string userID, Address address, Phone_Number phone, std::string name)
	{
		setUserID(userID);
		setAddress(address);
		setPhone(phone);
		setName(name);
	}

	// Method to get the user ID
	std::string getUserID() {
		return userID;
	}

	// Method to get the customer's address
	Address getAddress() {
		return address;
	}

	// Method to get the customer's phone number
	Phone_Number getPhone() {
		return phone;
	}

	// Method to get the customer's name
	std::string getName() {
		return name;
	}

	// Method to set the user ID
	void setUserID(std::string userID) {
		this->userID = userID;
	}

	// Method to set the customer's address
	void setAddress(Address address) {
		this->address = address;
	}

	// Method to set the customer's phone number
	void setPhone(Phone_Number phone) {
		this->phone = phone;
	}

	// Method to set the customer's name
	void setName(std::string name) {
		this->name = name;
	}

};