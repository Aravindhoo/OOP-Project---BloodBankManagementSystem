#ifndef TESTINGOPERATION_H
#define TESTINGOPERATION_H

#include "BloodBankOperation.h"

// TestingOperation updates the status of a blood unit after testing.
class TestingOperation : public BloodBankOperation
{
public:
    TestingOperation(int operationId,
                     int staffId,
                     BloodBankDatabase& database,
                     BloodStock& stock,
                     Screen& screen,
                     Keypad& keypad);

    void execute() override;
};

#endif
