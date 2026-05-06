#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>

class BloodRequest;

// Hospital stores hospital information and can create blood requests.
class Hospital
{
public:
    Hospital(int hospitalId = 0,
             const std::string& name = "",
             const std::string& address = "",
             const std::string& contactNumber = "");

    BloodRequest createRequest(int requestId,
                               const std::string& patientName,
                               const std::string& requiredBloodGroup,
                               int quantity) const;
    void displayDetails() const;

private:
    int hospitalId;
    std::string name;
    std::string address;
    std::string contactNumber;
};

#endif
