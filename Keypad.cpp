#include "Keypad.h"

#include <iostream>
#include <limits>

// Read a valid integer value from the user.
int Keypad::getInput()
{
    int input = 0;

    while (!(std::cin >> input))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a valid number: ";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

// Read a full line of text from the user.
std::string Keypad::getStringInput()
{
    std::string input;
    std::getline(std::cin >> std::ws, input);
    return input;
}

// Read a valid floating-point value from the user.
double Keypad::getDoubleInput()
{
    double input = 0.0;

    while (!(std::cin >> input))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a valid number: ";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}
