#include<string>
#include "Address.h"

Address::Address()
{
	setStreet("The Roadside");
}

Address::Address(std::string newstreet, std::string newcity, std::string newstate, std::string newzip)
{
	setStreet(newstreet);
	setCity(newcity);
	setState(newstate);
	setZip(newzip);
}

Address::Address(std::string newstreet, std::string newstreet2, std::string newcity, std::string newstate, std::string newzip)
{
	setStreet(newstreet);
	setStreet2(newstreet2);
	setCity(newcity);
	setState(newstate);
	setZip(newzip);
}

void Address::setStreet(std::string newstreet)
{
	street = newstreet;
}

void Address::setStreet2(std::string newstreet2)
{
	street2 = newstreet2;
}

void Address::setCity(std::string newcity)
{
	city = newcity;
}

void Address::setState(std::string newstate)
{
	state = newstate;
}

void Address::setZip(std::string newzip)
{
	zip = newzip;
}

std::string Address::getStreet()
{
	return street;
}

std::string Address::getStreet2()
{
	return street2;
}

std::string Address::getCity()
{
	return city;
}

std::string Address::getState()
{
	return state;
}

std::string Address::getZip()
{
	return zip;
}

std::string Address::toString()
{
	std::string toReturn = "";

	toReturn += "Street:\t\t" + getStreet() + "\n";
	toReturn += "Street2:\t" + getStreet2() + "\n";
	toReturn += "City:\t\t" + getCity() + "\n";
	toReturn += "State:\t\t" + getState() + "\n";
	toReturn += "Zip:\t\t" + getZip() + "\n";

	return toReturn;
}