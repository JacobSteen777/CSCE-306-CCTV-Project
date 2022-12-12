#pragma once
#include <string>

class Phone_Number {
private:
	std::string cell_number;
	std::string work_number;
	std::string other_number;
	std::string home_number;

public:
	// Constructor to initialize the phone numbers
	Phone_Number(std::string cell_number, std::string work_number, std::string other_number, std::string home_number) {
		this->cell_number = cell_number;
		this->work_number = work_number;
		this->other_number = other_number;
		this->home_number = home_number;
	}

	Phone_Number() {}

	// Method to get the cell phone number
	std::string getCell_Number() {
		return cell_number;
	}

	// Method to get the work phone number
	std::string getWork_Number() {
		return work_number;
	}

	// Method to get the other phone number
	std::string getOther_Number() {
		return other_number;
	}

	// Method to get the home phone number
	std::string getHome_Number() {
		return home_number;
	}

	// Method to set the cell phone number
	void setCell_Number(std::string cell_number) {
		this->cell_number = cell_number;
	}

	// Method to set the work phone number
	void setWork_Number(std::string work_number) {
		this->work_number = work_number;
	}

	// Method to set the other phone number
	void setOther_Number(std::string other_number) {
		this->other_number = other_number;
	}

	// Method to set the home phone number
	void setHome_Number(std::string home_number) {
		this->home_number = home_number;
	}
};