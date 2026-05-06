#include "Donor.h"

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

// Initialize a donor with identity and health screening information.
Donor::Donor(int donorId,
             const std::string& name,
             int age,
             const std::string& bloodGroup,
             const std::string& phone,
             const std::string& lastDonationDate)
    : donorId(donorId),
      name(name),
      age(age),
      bloodGroup(normalizeBloodGroup(bloodGroup)),
      phone(phone),
      lastDonationDate(lastDonationDate),
      eligible(false)
{
    checkEligibility();
}

// Perform a simple beginner-friendly eligibility check.
bool Donor::checkEligibility()
{
    eligible = (age >= 18 && age <= 60);
    return eligible;
}

// Return the donor identifier.
int Donor::getDonorId() const
{
    return donorId;
}

// Return the donor blood group.
std::string Donor::getBloodGroup() const
{
    return bloodGroup;
}

// Return the current eligibility flag.
bool Donor::isEligible() const
{
    return eligible;
}

// Display donor details on the console.
void Donor::displayDetails() const
{
    std::cout << "Donor ID: " << donorId << '\n'
              << "Name: " << name << '\n'
              << "Age: " << age << '\n'
              << "Blood Group: " << bloodGroup << '\n'
              << "Phone: " << phone << '\n'
              << "Last Donation Date: " << lastDonationDate << '\n'
              << "Eligible: " << (eligible ? "Yes" : "No") << std::endl;
}
