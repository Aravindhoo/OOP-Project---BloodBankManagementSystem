#include "BloodBankOperation.h"

// Initialize the common data shared by all operations.
BloodBankOperation::BloodBankOperation(int operationId,
                                       int staffId,
                                       BloodBankDatabase& database,
                                       BloodStock& stock,
                                       Screen& screen,
                                       Keypad& keypad)
    : operationId(operationId),
      staffId(staffId),
      database(database),
      stock(stock),
      screen(screen),
      keypad(keypad)
{
}

// Provide a virtual destructor for safe polymorphic cleanup.
BloodBankOperation::~BloodBankOperation() = default;
