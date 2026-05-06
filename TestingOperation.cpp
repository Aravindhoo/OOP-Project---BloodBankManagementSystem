#include "TestingOperation.h"

#include "BloodStock.h"
#include "BloodUnit.h"
#include "Keypad.h"
#include "Screen.h"

// Initialize the testing operation.
TestingOperation::TestingOperation(int operationId,
                                   int staffId,
                                   BloodBankDatabase& database,
                                   BloodStock& stock,
                                   Screen& screen,
                                   Keypad& keypad)
    : BloodBankOperation(operationId, staffId, database, stock, screen, keypad)
{
}

// Record a safe or unsafe result for a blood unit.
void TestingOperation::execute()
{
    screen.displayMessageLine("\n--- Testing Operation ---");
    screen.displayMessage("Enter blood unit ID: ");
    const int unitId = keypad.getInput();

    BloodUnit* unit = stock.findUnit(unitId);

    if (unit == nullptr)
    {
        screen.displayMessageLine("Blood unit not found.");
        return;
    }

    screen.displayMessage("Enter test result (1 = Safe, 2 = Unsafe): ");
    const int result = keypad.getInput();

    if (result == 1)
    {
        unit->markTested();
        screen.displayMessageLine("The blood unit has been marked as available.");
    }
    else if (result == 2)
    {
        unit->markRejected();
        screen.displayMessageLine("The blood unit has been rejected.");
    }
    else
    {
        screen.displayMessageLine("Invalid test result. No changes were made.");
    }
}
