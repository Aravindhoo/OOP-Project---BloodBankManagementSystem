#include "Hospital.h"

#include "BloodRequest.h"

#include <iostream>

// Initialize a hospital with contact details.
Hospital::Hospital(int hospitalId,
                   const std::string& name,
                   const std::string& address,
                   const std::string& contactNumber)
    : hospitalId(hospitalId),
      name(name),
      address(address),
      contactNumber(contactNumber)
{
}

// Create a blood request for a patient from this hospital.
BloodRequest Hospital::createRequest(int requestId,
                                     const std::string& patientName,
                                     const std::string& requiredBloodGroup,
                                     int quantity) const
{
    return BloodRequest(requestId, name, patientName, requiredBloodGroup, quantity);
}

// Display hospital details on the console.
void Hospital::displayDetails() const
{
    std::cout << "Hospital ID: " << hospitalId << '\n'
              << "Name: " << name << '\n'
              << "Address: " << address << '\n'
              << "Contact Number: " << contactNumber << std::endl;
}
