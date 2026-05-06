#ifndef BLOODSTOCK_H
#define BLOODSTOCK_H

#include "BloodUnit.h"

#include <vector>

// BloodStock manages the blood units currently stored in the blood bank.
class BloodStock
{
public:
    void addBloodUnit(const BloodUnit& bloodUnit);
    bool checkAvailability(const std::string& bloodGroup, int quantity) const;
    bool issueBloodUnit(const std::string& bloodGroup);
    void displayStock() const;
    std::vector<BloodUnit> getUnitsByBloodGroup(const std::string& bloodGroup) const;
    BloodUnit* findUnit(int unitId);

private:
    std::vector<BloodUnit> units;
};

#endif
