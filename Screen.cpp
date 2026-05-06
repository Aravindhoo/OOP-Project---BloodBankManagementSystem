#include "Screen.h"

#include <iostream>

// Display a message without moving to a new line.
void Screen::displayMessage(const std::string& message) const
{
    std::cout << message;
}

// Display a message and move to a new line.
void Screen::displayMessageLine(const std::string& message) const
{
    std::cout << message << std::endl;
}

// Display the main menu for staff operations.
void Screen::displayMainMenu() const
{
    std::cout << "\n================ Blood Bank Main Menu ================\n"
              << "1. Register donor and record donation\n"
              << "2. Test blood unit\n"
              << "3. Receive hospital/patient blood request\n"
              << "4. Approve or issue blood request\n"
              << "5. View blood stock\n"
              << "6. Logout\n"
              << "0. Exit\n"
              << "Choose an option: ";
}

// Display the stock-related menu heading.
void Screen::displayStockMenu() const
{
    std::cout << "\n---------------- Blood Stock ----------------\n";
}

// Display the request-related menu heading.
void Screen::displayRequestMenu() const
{
    std::cout << "\n---------------- Blood Requests ----------------\n";
}
