#include "IssueOperation.h"

#include "BloodBankDatabase.h"
#include "BloodRequest.h"
#include "BloodStock.h"
#include "Keypad.h"
#include "Screen.h"

#include <string>

// Initialize the issue operation.
IssueOperation::IssueOperation(int operationId,
                               int staffId,
                               BloodBankDatabase& database,
                               BloodStock& stock,
                               Screen& screen,
                               Keypad& keypad)
    : BloodBankOperation(operationId, staffId, database, stock, screen, keypad)
{
}

// Approve a request when stock exists and issue the required units.
void IssueOperation::execute()
{
    screen.displayRequestMenu();
    screen.displayMessage("Enter request ID to process: ");
    const int requestId = keypad.getInput();

    BloodRequest* request = database.findRequest(requestId);

    if (request == nullptr)
    {
        screen.displayMessageLine("Request not found.");
        return;
    }

    if (request->getStatus() == "Issued")
    {
        screen.displayMessageLine("This request has already been issued.");
        return;
    }

    if (request->getStatus() == "Rejected")
    {
        screen.displayMessageLine("This request has already been rejected.");
        return;
    }

    if (!stock.checkAvailability(request->getRequiredBloodGroup(), request->getQuantity()))
    {
        screen.displayMessageLine("Required stock is not available right now.");
        screen.displayMessage("Enter 1 to reject the request or 2 to keep it pending: ");
        const int decision = keypad.getInput();

        if (decision == 1)
        {
            request->rejectRequest();
            screen.displayMessageLine("The request has been rejected.");
        }
        else
        {
            screen.displayMessageLine("The request will remain pending.");
        }

        return;
    }

    request->approveRequest();

    for (int count = 0; count < request->getQuantity(); ++count)
    {
        if (!stock.issueBloodUnit(request->getRequiredBloodGroup()))
        {
            screen.displayMessageLine("A stock update issue occurred while issuing blood.");
            return;
        }
    }

    request->markIssued();
    screen.displayMessageLine("Blood request approved and issued successfully.");
}
