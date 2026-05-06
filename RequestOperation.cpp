#include "RequestOperation.h"

#include "BloodBankDatabase.h"
#include "BloodRequest.h"
#include "Hospital.h"
#include "Keypad.h"
#include "Screen.h"

#include <string>

// Initialize the request operation.
RequestOperation::RequestOperation(int operationId,
                                   int staffId,
                                   BloodBankDatabase& database,
                                   BloodStock& stock,
                                   Screen& screen,
                                   Keypad& keypad)
    : BloodBankOperation(operationId, staffId, database, stock, screen, keypad)
{
}

// Collect request details and store the new blood request.
void RequestOperation::execute()
{
    screen.displayRequestMenu();

    screen.displayMessage("Enter hospital name: ");
    const std::string hospitalName = keypad.getStringInput();

    screen.displayMessage("Enter patient name: ");
    const std::string patientName = keypad.getStringInput();

    screen.displayMessage("Enter required blood group: ");
    const std::string requiredBloodGroup = keypad.getStringInput();

    screen.displayMessage("Enter quantity in units: ");
    const int quantity = keypad.getInput();

    if (quantity <= 0)
    {
        screen.displayMessageLine("Quantity must be greater than zero.");
        return;
    }

    const int requestId = database.generateRequestId();
    Hospital hospital(requestId, hospitalName, "Address not provided", "Contact not provided");
    database.addHospital(hospital);

    const BloodRequest request =
        hospital.createRequest(requestId, patientName, requiredBloodGroup, quantity);
    database.addRequest(request);

    screen.displayMessageLine("Blood request created successfully.");
    screen.displayMessageLine("Generated request ID: " + std::to_string(requestId));
}
