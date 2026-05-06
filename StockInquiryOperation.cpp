#include "StockInquiryOperation.h"

#include "BloodStock.h"
#include "Screen.h"

// Initialize the stock inquiry operation.
StockInquiryOperation::StockInquiryOperation(int operationId,
                                             int staffId,
                                             BloodBankDatabase& database,
                                             BloodStock& stock,
                                             Screen& screen,
                                             Keypad& keypad)
    : BloodBankOperation(operationId, staffId, database, stock, screen, keypad)
{
}

// Show the current available stock grouped by blood group.
void StockInquiryOperation::execute()
{
    screen.displayStockMenu();
    stock.displayStock();
}
