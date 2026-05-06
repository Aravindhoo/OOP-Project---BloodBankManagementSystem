#ifndef STOCKINQUIRYOPERATION_H
#define STOCKINQUIRYOPERATION_H

#include "BloodBankOperation.h"

// StockInquiryOperation displays the currently available stock.
class StockInquiryOperation : public BloodBankOperation
{
public:
    StockInquiryOperation(int operationId,
                          int staffId,
                          BloodBankDatabase& database,
                          BloodStock& stock,
                          Screen& screen,
                          Keypad& keypad);

    void execute() override;
};

#endif
