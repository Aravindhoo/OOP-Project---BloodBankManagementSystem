#ifndef BLOODUNIT_H
#define BLOODUNIT_H

#include <string>

// BloodUnit represents one stored donation unit in the blood bank.
class BloodUnit
{
public:
    BloodUnit(int unitId = 0,
              int donorId = 0,
              const std::string& bloodGroup = "",
              const std::string& collectionDate = "",
              const std::string& expiryDate = "",
              const std::string& status = "Collected");

    void markTested();
    void markRejected();
    void markIssued();
    bool isAvailable() const;
    bool isExpired() const;
    std::string getBloodGroup() const;
    int getUnitId() const;
    std::string getStatus() const;
    void displayDetails() const;

private:
    int unitId;
    int donorId;
    std::string bloodGroup;
    std::string collectionDate;
    std::string expiryDate;
    std::string status;
};

#endif
