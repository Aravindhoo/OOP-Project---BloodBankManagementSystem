#ifndef REQUESTOPERATION_H
#define REQUESTOPERATION_H

#include "BloodBankOperation.h"

// RequestOperation records a new blood request from a hospital or patient.
class RequestOperation : public BloodBankOperation
{
public:
    RequestOperation(int operationId,
                     int staffId,
                     BloodBankDatabase& database,
                     BloodStock& stock,
                     Screen& screen,
                     Keypad& keypad);

    void execute() override;
};

#endif
