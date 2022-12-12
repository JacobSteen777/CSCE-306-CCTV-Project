#pragma once
#include <string>

class Address
{
private:

	std::string street;
	std::string street2;
	std::string city;
	std::string state;
	std::string zip;

public:

	Address();
	Address(std::string, std::string, std::string, std::string);
	Address(std::string, std::string, std::string, std::string, std::string);

	void setStreet(std::string);
	void setStreet2(std::string);
	void setCity(std::string);
	void setState(std::string);
	void setZip(std::string);

	std::string getStreet();
	std::string getStreet2();
	std::string getCity();
	std::string getState();
	std::string getZip();

	std::string toString();

};