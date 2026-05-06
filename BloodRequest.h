#ifndef BLOODREQUEST_H
#define BLOODREQUEST_H

#include <string>

// BloodRequest stores a hospital or patient request for blood units.
class BloodRequest
{
public:
    BloodRequest(int requestId = 0,
                 const std::string& hospitalName = "",
                 const std::string& patientName = "",
                 const std::string& requiredBloodGroup = "",
                 int quantity = 0,
                 const std::string& status = "Pending");

    void approveRequest();
    void rejectRequest();
    void markIssued();
    std::string getRequiredBloodGroup() const;
    int getQuantity() const;
    int getRequestId() const;
    std::string getStatus() const;
    void displayDetails() const;

private:
    int requestId;
    std::string hospitalName;
    std::string patientName;
    std::string requiredBloodGroup;
    int quantity;
    std::string status;
};

#endif
