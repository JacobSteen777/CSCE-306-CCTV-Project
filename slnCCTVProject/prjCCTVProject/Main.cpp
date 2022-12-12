#include <iostream>
#include <fstream>
#include <string>
#include "Manager.cpp"
#include "Orders.cpp"

// Clears the command line
void Clear()
{
	std::cout << "\x1B[2J\x1B[H";
}

// Clears out Cin in order to detect new inputted ints
void clearCin()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Ensures only valid int inputs are returned
int getValidIntInput()
{
	int num;
	while (true)
	{
		if (std::cin >> num)
		{
			break;
		}
		else
		{
			clearCin();
			std::cout << "Please enter a valid number: ";
		}
	}
	clearCin();
	return num;
}

int main()
{
	bool programLoop = true;
	std::cout << "Loading CCTV Program" << std::endl;
	Clear();
	std::string username, password, permissions, firstname, lastname;
	std::ifstream filei;
	std::ifstream fileRead;
	std::ofstream fileWrite;
	std::string lineToCheck;
	std::string temp;
	bool invalid = true;
	while (programLoop == true)
	{
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
		if (permissions == "Manager")
		{
			Manager* user = new Manager();
		}
		else if (permissions == "Sales")
		{
			Sales* user = new Sales();
		}
		else
		{
			Customer* user = new Customer();
		}
		while (invalid == false)
		{

		}
		std::cout << "Welcome " << firstname << " to CCTV Purchasing Platform!\n";
		std::cout << "Welcome to the main menu of the CCTV Purchasing Platform!\nPlease select one of the below options.\nEnter 0 to log out and -1 to close program" << std::endl;
		std::cout << "1. View User Info Menu" << std::endl;
		std::cout << "2. View Products Menu" << std::endl;
		std::cout << "3. View Orders Menu" << std::endl;
		if (permissions == "Sales" || permissions == "Manager")
		{
			std::cout << "4. View Customer Info" << std::endl;
			std::cout << "5. View Customer Orders" << std::endl;
		}
		if (permissions == "Manager")
		{
			std::cout << "6. Update Customer Info" << std::endl;
			std::cout << "7. Edit Products Menu" << std::endl;
		}
		int choice = 1;
		int choice2 = 1;
		int choice3 = 1;
		if (permissions == "Manager")
		{
			choice = getValidIntInput();
			while (choice > 7 || choice < -1)
			{
				std::cout << "Please enter a valid option: ";
				choice = getValidIntInput();
			}
		}
		else if (permissions == "Sales")
		{
			choice = getValidIntInput();
			while (choice > 5 || choice < -1)
			{
				std::cout << "Please enter a valid option: ";
				choice = getValidIntInput();
			}
		}
		else
		{
			choice = getValidIntInput();
			while (choice > 3 || choice < -1)
			{
				std::cout << "Please enter a valid option: ";
				choice = getValidIntInput();
			}
		}
		Clear();
		switch (choice)
		{
		case -1:
			programLoop = false;
			std::cout << "Closing program, thanks for using the CCTV Purchasing Platform" << std::endl;
			break;
		case 0:
			invalid = true;
			break;
		case 1:
			std::cout << "This menu has limited information due to being incomplete.\n";
			std::cout << "User Info:\n";
			std::cout << "Name: " << firstname << " " << lastname << std::endl;
			std::cout << "\nEnter anything to go back to main menu\n";
			std::cin >> temp;
			break;
		case 2:
			std::cout << "Please enter one of the valid options:" << std::endl;
			std::cout << "1 - DVR's\n2 - Camera's\n3 - Accessories" << std::endl;
			choice2 = getValidIntInput();
			while (choice2 > 3 || choice2 < 1)
			{
				std::cout << "Please enter a valid option: ";
				choice2 = getValidIntInput();
			}
			Clear();
			fileWrite.open(firstname + ".txt", std::ios::app);
			if (choice2 == 1)
			{
				std::cout << "Displaying all available DVR's" << std::endl;
				fileRead.open("dvr.txt");
			}
			else if (choice2 == 2)
			{
				std::cout << "Displaying all available camera's" << std::endl;
				fileRead.open("camera.txt");
			}
			else
			{
				std::cout << "Displaying all available accessories's" << std::endl;
				fileRead.open("accessories.txt");
			}
			if (fileRead.fail())
			{
				std::cout << "There is no product file, please seek technical support" << std::endl;
				std::cin >> temp;
				fileRead.close();
				break;
			}
			while (!fileRead.eof())
			{
				Clear();
				if (choice2 == 1)
				{
					std::cout << "Displaying all available DVR's" << std::endl;
				}
				else if (choice2 == 2)
				{
					std::cout << "Displaying all available camera's" << std::endl;
				}
				else
				{
					std::cout << "Displaying all available accessories's" << std::endl;
				}
				getline(fileRead, temp);
				std::cout << temp << std::endl;
				std::cout << "Enter 1 to add 1 unit to orders, Enter 0 to continue" << std::endl;
				choice3 = getValidIntInput();
				while (choice3 > 1 || choice3 < 0)
				{
					std::cout << "Please enter a valid option" << std::endl;
				}
				if (choice3 == 1)
				{
					fileWrite << temp << std::endl;;
				}
			}
			fileRead.close();
			fileWrite.close();
			break;
		case 3:
			std::cout << "Displaying all orders" << std::endl;
			fileRead.open(firstname + ".txt");
			if (fileRead.fail())
			{
				std::cout << "You have no orders" << std::endl;
			}
			else
			{
				while (!fileRead.eof())
				{
					getline(fileRead, temp);
					std::cout << temp << std::endl;
				}
			}
			std::cout << "Due to incompletedness, you are unable to remove orders, please ask sales if you need one removed" << std::endl;
			std::cin >> temp;
			fileRead.close();
			break;
		case 4:
			std::cout << "This option has been disabled due to incompletedness.\nEnter anything to go back to menu" << std::endl;
			std::cin >> temp;
			break;
		case 5:
			std::cout << "Please enter a customers first name to read their orders" << std::endl;
			std::cin >> temp;
			Clear();
			std::cout << "Displaying all " << temp << "'s orders" << std::endl;
			fileRead.open(firstname + ".txt");
			if (fileRead.fail())
			{
				std::cout << "There are no orders" << std::endl;
			}
			else
			{
				while (!fileRead.eof())
				{
					getline(fileRead, temp);
					std::cout << temp << std::endl;
				}
			}
			std::cout << "Due to incompletedness, you are unable to remove orders" << std::endl;
			std::cin >> temp;
			fileRead.close();
			break;
		case 6:
			std::cout << "This option has been disabled due to incompletedness.\nEnter anything to go back to menu" << std::endl;
			std::cin >> temp;
			break;
		case 7:
			std::cout << "You are currently only able to add products, enter a category to add to" << std::endl;
			std::cout << "1 - DVR's\n2 - Camera's\n3 - Accessories" << std::endl;
			choice2 = getValidIntInput();
			while (choice2 > 3 || choice2 < 1)
			{
				std::cout << "Please enter a valid option: ";
				choice2 = getValidIntInput();
			}
			Clear();
			if (choice2 == 1)
			{
				fileWrite.open("dvr.txt", std::ios::app);
			}
			else if (choice2 == 2)
			{
				fileWrite.open("camera.txt", std::ios::app);
			}
			else
			{
				fileWrite.open("accessories.txt", std::ios::app);
			}
			std::cout << "Please enter an item to add\nSuggested Format: [Item Name] - [Item Price]" << std::endl;
			getline(std::cin, temp);
			fileWrite << "\n" << temp;
			std::cout << temp << " has been added!\nEnter anything to exit" << std::endl;
			std::cin >> temp;
			break;
		}
	}

	return 0;
}