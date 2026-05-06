#ifndef SCREEN_H
#define SCREEN_H

#include <string>

// Screen handles all console output for the blood bank system.
class Screen
{
public:
    void displayMessage(const std::string& message) const;
    void displayMessageLine(const std::string& message) const;
    void displayMainMenu() const;
    void displayStockMenu() const;
    void displayRequestMenu() const;
};

#endif
