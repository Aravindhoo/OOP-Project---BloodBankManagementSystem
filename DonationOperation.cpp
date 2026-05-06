#include "DonationOperation.h"

#include "BloodBankDatabase.h"
#include "BloodStock.h"
#include "BloodUnit.h"
#include "Donor.h"
#include "Keypad.h"
#include "Screen.h"

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

namespace
{
std::string getCurrentDateString()
{
    const std::time_t rawTime = std::time(nullptr);
    const std::tm timeInfo = *std::localtime(&rawTime);

    std::ostringstream output;
    output << std::put_time(&timeInfo, "%Y-%m-%d");
    return output.str();
}

std::string getFutureDateString(int daysToAdd)
{
    std::time_t rawTime = std::time(nullptr);
    std::tm timeInfo = *std::localtime(&rawTime);
    timeInfo.tm_mday += daysToAdd;
    std::mktime(&timeInfo);

    std::ostringstream output;
    output << std::put_time(&timeInfo, "%Y-%m-%d");
    return output.str();
}
}

// Initialize the donation operation.
DonationOperation::DonationOperation(int operationId,
                                     int staffId,
                                     BloodBankDatabase& database,
                                     BloodStock& stock,
                                     Screen& screen,
                                     Keypad& keypad)
    : BloodBankOperation(operationId, staffId, database, stock, screen, keypad)
{
}

// Register a donor if needed and store the donated blood unit.
void DonationOperation::execute()
{
    screen.displayMessageLine("\n--- Donation Operation ---");
    screen.displayMessage("Enter 1 if the donor is already registered, otherwise enter 0: ");
    const int registeredChoice = keypad.getInput();

    Donor* donor = nullptr;

    if (registeredChoice == 1)
    {
        screen.displayMessage("Enter donor ID: ");
        const int donorId = keypad.getInput();
        donor = database.findDonor(donorId);

        if (donor == nullptr)
        {
            screen.displayMessageLine("Donor not found. Starting new registration.");
        }
    }

    if (donor == nullptr)
    {
        const int donorId = database.generateDonorId();

        screen.displayMessage("Enter donor name: ");
        const std::string name = keypad.getStringInput();

        screen.displayMessage("Enter donor age: ");
        const int age = keypad.getInput();

        screen.displayMessage("Enter donor blood group: ");
        const std::string bloodGroup = keypad.getStringInput();

        screen.displayMessage("Enter donor phone number: ");
        const std::string phone = keypad.getStringInput();

        screen.displayMessage("Enter last donation date (YYYY-MM-DD or N/A): ");
        const std::string lastDonationDate = keypad.getStringInput();

        Donor newDonor(donorId, name, age, bloodGroup, phone, lastDonationDate);
        database.addDonor(newDonor);
        donor = database.findDonor(donorId);

        screen.displayMessageLine("Donor registered successfully.");
        screen.displayMessageLine("Generated donor ID: " + std::to_string(donorId));
    }

    if (donor == nullptr)
    {
        screen.displayMessageLine("Unable to access donor details.");
        return;
    }

    if (!donor->checkEligibility())
    {
        screen.displayMessageLine("The donor is not eligible to donate at this time.");
        return;
    }

    const int unitId = database.generateUnitId();
    BloodUnit newUnit(
        unitId,
        donor->getDonorId(),
        donor->getBloodGroup(),
        getCurrentDateString(),
        getFutureDateString(35),
        "Collected");

    screen.displayMessage("Has the blood unit been tested now? (1 = Yes, 0 = No): ");
    const int testedChoice = keypad.getInput();

    if (testedChoice == 1)
    {
        screen.displayMessage("Enter test result (1 = Safe, 2 = Unsafe): ");
        const int result = keypad.getInput();

        if (result == 1)
        {
            newUnit.markTested();
        }
        else
        {
            newUnit.markRejected();
        }
    }

    stock.addBloodUnit(newUnit);

    screen.displayMessageLine("Donation recorded successfully.");
    screen.displayMessageLine("Generated blood unit ID: " + std::to_string(unitId));
    screen.displayMessageLine("Stored unit status: " + newUnit.getStatus());
}
