#pragma once
#include <iostream>

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