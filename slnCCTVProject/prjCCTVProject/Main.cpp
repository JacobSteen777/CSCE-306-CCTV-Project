#include <iostream>
#include <fstream>
#include <string>

void Clear()
{
	std::cout << "\x1B[2J\x1B[H";
}

int main()
{
	std::cout << "Loading CCTV Program" << std::endl;
	Clear();
	std::string username, password, permissions, firstname, lastname;
	std::ifstream filei;
	std::string lineToCheck;
	bool invalid = true;
	while (invalid == true)
	{
		filei.open("users.txt");
		if (filei.fail())
		{
			std::cout << "Missing users.txt. Seek technical support in order to be provided a users.txt." << std::endl;
			invalid = false;
			return 1;
		}
		std::cout << "Please enter Username:\n";
		std::cin >> username;
		Clear();
		std::cout << "Please enter Password:\n";
		std::cin >> password;
		Clear();
		std::cout << "Attempting to Login, please wait.\n";
		while (!filei.eof())
		{
			getline(filei, lineToCheck);
			std::string temp = lineToCheck.substr(0, lineToCheck.find(" "));
			if (username == temp)
			{
				lineToCheck = lineToCheck.substr(lineToCheck.find(" ") + 1);
				temp = lineToCheck.substr(0, lineToCheck.find(" "));
				if (password == temp)
				{
					lineToCheck = lineToCheck.substr(lineToCheck.find(" ") + 1);
					temp = lineToCheck.substr(0, lineToCheck.find(" "));
					permissions = temp;
					lineToCheck = lineToCheck.substr(lineToCheck.find(" ") + 1);
					temp = lineToCheck.substr(0, lineToCheck.find(" "));
					firstname = temp;
					lineToCheck = lineToCheck.substr(lineToCheck.find(" ") + 1);
					temp = lineToCheck.substr(0, lineToCheck.find(" "));
					lastname = temp;
					invalid = false;
				}
			}
		}
		if (invalid == true)
		{
			Clear();
			std::cout << "No such account, please try again\n";
		}
		filei.close();
	}
	Clear();
	std::cout << "Welcome " << firstname << " to CCTV Purchasing Platform!\n";

	return 0;
}