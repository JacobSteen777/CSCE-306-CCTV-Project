#pragma once
#include "Account.cpp"
#include "Permissions.cpp"


class User {
private:
	Account account;
	Permissions permissions;

public:
	// Constructor to initialize the account and permissions
	User(Account account, Permissions permissions) 
	{
		this->account = account;
		this->permissions = permissions;
	}

	// Method to get the user's account
	Account getAccount() {
		return account;
	}

	// Method to get the user's permissions
	Permissions getPermissions() {
		return permissions;
	}

};