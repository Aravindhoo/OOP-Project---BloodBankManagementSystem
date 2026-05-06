#include "BloodStock.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>

namespace
{
std::string normalizeBloodGroup(std::string bloodGroup)
{
    bloodGroup.erase(
        std::remove_if(
            bloodGroup.begin(),
            bloodGroup.end(),
            [](unsigned char ch) { return std::isspace(ch) != 0; }),
        bloodGroup.end());

    std::transform(
        bloodGroup.begin(),
        bloodGroup.end(),
        bloodGroup.begin(),
        [](unsigned char ch) { return static_cast<char>(std::toupper(ch)); });

    return bloodGroup;
}
}

// Add a blood unit to stock after collection.
void BloodStock::addBloodUnit(const BloodUnit& bloodUnit)
{
    units.push_back(bloodUnit);
}

// Check whether enough available units exist for a blood group.
bool BloodStock::checkAvailability(const std::string& bloodGroup, int quantity) const
{
    const std::string normalizedGroup = normalizeBloodGroup(bloodGroup);
    int availableCount = 0;

    for (const BloodUnit& unit : units)
    {
        if (unit.getBloodGroup() == normalizedGroup && unit.isAvailable())
        {
            ++availableCount;
        }
    }

    return availableCount >= quantity;
}

// Issue one available blood unit for the requested blood group.
bool BloodStock::issueBloodUnit(const std::string& bloodGroup)
{
    const std::string normalizedGroup = normalizeBloodGroup(bloodGroup);

    for (BloodUnit& unit : units)
    {
        if (unit.getBloodGroup() == normalizedGroup && unit.isAvailable())
        {
            unit.markIssued();
            return true;
        }
    }

    return false;
}

// Display available stock grouped by blood group.
void BloodStock::displayStock() const
{
    static const std::array<std::string, 8> groups =
        {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};

    std::cout << "Available blood units by group:\n";

    for (const std::string& group : groups)
    {
        int count = 0;

        for (const BloodUnit& unit : units)
        {
            if (unit.getBloodGroup() == group && unit.isAvailable())
            {
                ++count;
            }
        }

        std::cout << "  " << group << ": " << count << '\n';
    }
}

// Return all units that belong to a specific blood group.
std::vector<BloodUnit> BloodStock::getUnitsByBloodGroup(const std::string& bloodGroup) const
{
    const std::string normalizedGroup = normalizeBloodGroup(bloodGroup);
    std::vector<BloodUnit> matchingUnits;

    for (const BloodUnit& unit : units)
    {
        if (unit.getBloodGroup() == normalizedGroup)
        {
            matchingUnits.push_back(unit);
        }
    }

    return matchingUnits;
}

// Find a unit by its identifier so it can be tested or inspected.
BloodUnit* BloodStock::findUnit(int unitId)
{
    for (BloodUnit& unit : units)
    {
        if (unit.getUnitId() == unitId)
        {
            return &unit;
        }
    }

    return nullptr;
}
