#ifndef DONATIONOPERATION_H
#define DONATIONOPERATION_H

#include "BloodBankOperation.h"

// DonationOperation registers donors and records donated blood units.
class DonationOperation : public BloodBankOperation
{
public:
    DonationOperation(int operationId,
                      int staffId,
                      BloodBankDatabase& database,
                      BloodStock& stock,
                      Screen& screen,
                      Keypad& keypad);

    void execute() override;
};

#endif
