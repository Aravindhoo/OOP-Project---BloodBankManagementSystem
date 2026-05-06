#ifndef BLOODBANKSYSTEM_H
#define BLOODBANKSYSTEM_H

#include "BloodBankDatabase.h"
#include "BloodStock.h"
#include "Keypad.h"
#include "Screen.h"

#include <memory>

class BloodBankOperation;
class Staff;

// BloodBankSystem controls authentication, menus, and operation execution.
class BloodBankSystem
{
public:
    BloodBankSystem();

    void run();

private:
    bool staffAuthenticated;
    BloodStock bloodStock;
    BloodBankDatabase database;
    Staff* currentStaff;
    Screen screen;
    Keypad keypad;

    void authenticateStaff();
    void displayMainMenu() const;
    bool performOperation();
    std::unique_ptr<BloodBankOperation> createOperation(int choice);
};

#endif
