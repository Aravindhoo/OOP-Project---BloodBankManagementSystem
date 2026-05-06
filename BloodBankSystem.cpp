#include "BloodBankSystem.h"

#include "BloodBankOperation.h"
#include "DonationOperation.h"
#include "IssueOperation.h"
#include "RequestOperation.h"
#include "Staff.h"
#include "StockInquiryOperation.h"
#include "TestingOperation.h"

#include <memory>
#include <string>

// Initialize the blood bank system state.
BloodBankSystem::BloodBankSystem()
    : staffAuthenticated(false),
      currentStaff(nullptr)
{
}

// Run the main application loop.
void BloodBankSystem::run()
{
    bool userExited = false;

    screen.displayMessageLine("\n# ================ Blood Bank Management System ================ #\n");
    screen.displayMessageLine("Sample staff logins:");
    screen.displayMessageLine("     1001 / admin123");
    screen.displayMessageLine("     1002 / nurse123");
    screen.displayMessageLine("     1003 / tech123");

    while (!userExited)
    {
        if (!staffAuthenticated)
        {
            authenticateStaff();
            continue;
        }

        displayMainMenu();
        userExited = !performOperation();
    }

    screen.displayMessageLine("Exiting Blood Bank Management System.");
}

// Authenticate a staff member before allowing access to operations.
void BloodBankSystem::authenticateStaff()
{
    screen.displayMessage("\nEnter staff ID: ");
    const int staffId = keypad.getInput();

    screen.displayMessage("Enter password: ");
    const std::string password = keypad.getStringInput();

    if (database.authenticateStaff(staffId, password))
    {
        staffAuthenticated = true;
        currentStaff = database.getStaff(staffId);

        if (currentStaff != nullptr)
        {
            screen.displayMessageLine("Authentication successful. Welcome, " + currentStaff->getName() + ".");
        }
        else
        {
            screen.displayMessageLine("Authentication successful.");
        }
    }
    else
    {
        screen.displayMessageLine("Invalid staff ID or password. Please try again.");
    }
}

// Display the main menu using the screen object.
void BloodBankSystem::displayMainMenu() const
{
    screen.displayMainMenu();
}

// Create and execute the operation selected by the user.
bool BloodBankSystem::performOperation()
{
    const int choice = keypad.getInput();

    if (choice == 0)
    {
        return false;
    }

    if (choice == 6)
    {
        staffAuthenticated = false;
        currentStaff = nullptr;
        screen.displayMessageLine("You have been logged out.");
        return true;
    }

    std::unique_ptr<BloodBankOperation> operation = createOperation(choice);

    if (operation == nullptr)
    {
        screen.displayMessageLine("Invalid menu choice.");
        return true;
    }

    operation->execute();
    return true;
}

// Create the correct derived operation using polymorphism.
std::unique_ptr<BloodBankOperation> BloodBankSystem::createOperation(int choice)
{
    const int activeStaffId = (currentStaff != nullptr) ? currentStaff->getStaffId() : 0;

    switch (choice)
    {
    case 1:
        return std::make_unique<DonationOperation>(
            choice, activeStaffId, database, bloodStock, screen, keypad);
    case 2:
        return std::make_unique<TestingOperation>(
            choice, activeStaffId, database, bloodStock, screen, keypad);
    case 3:
        return std::make_unique<RequestOperation>(
            choice, activeStaffId, database, bloodStock, screen, keypad);
    case 4:
        return std::make_unique<IssueOperation>(
            choice, activeStaffId, database, bloodStock, screen, keypad);
    case 5:
        return std::make_unique<StockInquiryOperation>(
            choice, activeStaffId, database, bloodStock, screen, keypad);
    default:
        return nullptr;
    }
}
