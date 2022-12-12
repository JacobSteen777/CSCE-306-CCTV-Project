#pragma once
#include <string>

class Permissions {
private:
	std::string permission;

public:
	// Constructor to initialize the permission
	Permissions(std::string permission) {
		this->permission = permission;
	}

	Permissions() {}

	// Method to get the permission
	std::string getPermission() {
		return permission;
	}

	// Method to check the permission
	bool checkPermission() {
		// Check if the permission is valid and return the result
		return (permission == "read" || permission == "write" || permission == "execute");
	}

};