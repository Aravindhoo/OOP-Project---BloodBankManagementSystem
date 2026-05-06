#ifndef BLOODBANKOPERATION_H
#define BLOODBANKOPERATION_H

class BloodBankDatabase;
class BloodStock;
class Screen;
class Keypad;

// BloodBankOperation is the abstract base for all menu operations.
class BloodBankOperation
{
public:
    BloodBankOperation(int operationId,
                       int staffId,
                       BloodBankDatabase& database,
                       BloodStock& stock,
                       Screen& screen,
                       Keypad& keypad);
    virtual ~BloodBankOperation();

    virtual void execute() = 0;

protected:
    int operationId;
    int staffId;
    BloodBankDatabase& database;
    BloodStock& stock;
    Screen& screen;
    Keypad& keypad;
};

#endif
