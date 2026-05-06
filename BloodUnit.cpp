#include "BloodUnit.h"

#include <algorithm>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

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

std::string getCurrentDateString()
{
    const std::time_t rawTime = std::time(nullptr);
    const std::tm timeInfo = *std::localtime(&rawTime);

    std::ostringstream output;
    output << std::put_time(&timeInfo, "%Y-%m-%d");
    return output.str();
}
}

// Initialize a blood unit collected from a donor.
BloodUnit::BloodUnit(int unitId,
                     int donorId,
                     const std::string& bloodGroup,
                     const std::string& collectionDate,
                     const std::string& expiryDate,
                     const std::string& status)
    : unitId(unitId),
      donorId(donorId),
      bloodGroup(normalizeBloodGroup(bloodGroup)),
      collectionDate(collectionDate),
      expiryDate(expiryDate),
      status(status)
{
}

// Mark a tested unit as available for issue.
void BloodUnit::markTested()
{
    status = "Available";
}

// Mark an unsafe unit as rejected.
void BloodUnit::markRejected()
{
    status = "Rejected";
}

// Mark a unit as issued to a request.
void BloodUnit::markIssued()
{
    status = "Issued";
}

// Check whether a unit is ready to be used.
bool BloodUnit::isAvailable() const
{
    return status == "Available" && !isExpired();
}

// Check whether the unit has passed its expiry date.
bool BloodUnit::isExpired() const
{
    return !expiryDate.empty() && expiryDate < getCurrentDateString();
}

// Return the blood group of the unit.
std::string BloodUnit::getBloodGroup() const
{
    return bloodGroup;
}

// Return the unit identifier.
int BloodUnit::getUnitId() const
{
    return unitId;
}

// Return the current status string.
std::string BloodUnit::getStatus() const
{
    return status;
}

// Display blood unit information on the console.
void BloodUnit::displayDetails() const
{
    std::cout << "Unit ID: " << unitId << '\n'
              << "Donor ID: " << donorId << '\n'
              << "Blood Group: " << bloodGroup << '\n'
              << "Collection Date: " << collectionDate << '\n'
              << "Expiry Date: " << expiryDate << '\n'
              << "Status: " << status;

    if (isExpired() && status != "Issued")
    {
        std::cout << " (Expired)";
    }

    std::cout << std::endl;
}
