#ifndef BLOODBANKDATABASE_H
#define BLOODBANKDATABASE_H

#include "BloodRequest.h"
#include "Donor.h"
#include "Hospital.h"
#include "Staff.h"

#include <string>
#include <vector>

// BloodBankDatabase stores all application data in memory.
class BloodBankDatabase
{
public:
    BloodBankDatabase();

    bool authenticateStaff(int id, const std::string& password) const;
    void addDonor(const Donor& donor);
    Donor* findDonor(int donorId);
    const Donor* findDonor(int donorId) const;
    void addRequest(const BloodRequest& request);
    BloodRequest* findRequest(int requestId);
    const BloodRequest* findRequest(int requestId) const;
    void addStaff(const Staff& staff);
    void addHospital(const Hospital& hospital);
    Staff* getStaff(int staffId);
    const std::vector<Donor>& getDonors() const;
    const std::vector<BloodRequest>& getRequests() const;
    int generateDonorId();
    int generateRequestId();
    int generateUnitId();

private:
    std::vector<Donor> donors;
    std::vector<Staff> staffMembers;
    std::vector<Hospital> hospitals;
    std::vector<BloodRequest> requests;
    int nextDonorId;
    int nextRequestId;
    int nextUnitId;
};

#endif
