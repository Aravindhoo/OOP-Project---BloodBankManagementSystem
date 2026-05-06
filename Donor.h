#ifndef DONOR_H
#define DONOR_H

#include <string>

// Donor stores personal and eligibility details for a blood donor.
class Donor
{
public:
    Donor(int donorId = 0,
          const std::string& name = "",
          int age = 0,
          const std::string& bloodGroup = "",
          const std::string& phone = "",
          const std::string& lastDonationDate = "N/A");

    bool checkEligibility();
    int getDonorId() const;
    std::string getBloodGroup() const;
    bool isEligible() const;
    void displayDetails() const;
// Hi sir. :)
private:
    int donorId;
    std::string name;
    int age;
    std::string bloodGroup;
    std::string phone;
    std::string lastDonationDate;
    bool eligible;
};

#endif
