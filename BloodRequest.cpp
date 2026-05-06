#include "BloodRequest.h"

#include <algorithm>
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

// Initialize a blood request with patient and hospital details.
BloodRequest::BloodRequest(int requestId,
                           const std::string& hospitalName,
                           const std::string& patientName,
                           const std::string& requiredBloodGroup,
                           int quantity,
                           const std::string& status)
    : requestId(requestId),
      hospitalName(hospitalName),
      patientName(patientName),
      requiredBloodGroup(normalizeBloodGroup(requiredBloodGroup)),
      quantity(quantity),
      status(status)
{
}

// Approve a pending blood request.
void BloodRequest::approveRequest()
{
    status = "Approved";
}

// Reject a blood request.
void BloodRequest::rejectRequest()
{
    status = "Rejected";
}

// Mark a request as fully issued.
void BloodRequest::markIssued()
{
    status = "Issued";
}

// Return the required blood group.
std::string BloodRequest::getRequiredBloodGroup() const
{
    return requiredBloodGroup;
}

// Return the number of requested units.
int BloodRequest::getQuantity() const
{
    return quantity;
}

// Return the request identifier.
int BloodRequest::getRequestId() const
{
    return requestId;
}

// Return the request status.
std::string BloodRequest::getStatus() const
{
    return status;
}

// Display request details on the console.
void BloodRequest::displayDetails() const
{
    std::cout << "Request ID: " << requestId << '\n'
              << "Hospital Name: " << hospitalName << '\n'
              << "Patient Name: " << patientName << '\n'
              << "Required Blood Group: " << requiredBloodGroup << '\n'
              << "Quantity: " << quantity << '\n'
              << "Status: " << status << std::endl;
}
