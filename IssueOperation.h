#ifndef ISSUEOPERATION_H
#define ISSUEOPERATION_H

#include "BloodBankOperation.h"

// IssueOperation approves requests and issues available blood units.
class IssueOperation : public BloodBankOperation
{
public:
    IssueOperation(int operationId,
                   int staffId,
                   BloodBankDatabase& database,
                   BloodStock& stock,
                   Screen& screen,
                   Keypad& keypad);

    void execute() override;
};

#endif
