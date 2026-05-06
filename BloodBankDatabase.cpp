#include "BloodBankDatabase.h"

// Seed the in-memory database with sample staff logins.
BloodBankDatabase::BloodBankDatabase()
    : nextDonorId(2001),
      nextRequestId(5001),
      nextUnitId(9001)
{
    staffMembers.emplace_back(1001, "Administrator", "admin123");
    staffMembers.emplace_back(1002, "Nurse Anita", "nurse123");
    staffMembers.emplace_back(1003, "Technician Ravi", "tech123");
}

// Check whether staff credentials are valid.
bool BloodBankDatabase::authenticateStaff(int id, const std::string& password) const
{
    for (const Staff& staffMember : staffMembers)
    {
        if (staffMember.getStaffId() == id && staffMember.validatePassword(password))
        {
            return true;
        }
    }

    return false;
}

// Add a newly registered donor to the database.
void BloodBankDatabase::addDonor(const Donor& donor)
{
    donors.push_back(donor);
}

// Find a donor by identifier.
Donor* BloodBankDatabase::findDonor(int donorId)
{
    for (Donor& donor : donors)
    {
        if (donor.getDonorId() == donorId)
        {
            return &donor;
        }
    }

    return nullptr;
}

// Find a donor by identifier in a const database object.
const Donor* BloodBankDatabase::findDonor(int donorId) const
{
    for (const Donor& donor : donors)
    {
        if (donor.getDonorId() == donorId)
        {
            return &donor;
        }
    }

    return nullptr;
}

// Add a request made by a hospital or patient.
void BloodBankDatabase::addRequest(const BloodRequest& request)
{
    requests.push_back(request);
}

// Find a request by identifier.
BloodRequest* BloodBankDatabase::findRequest(int requestId)
{
    for (BloodRequest& request : requests)
    {
        if (request.getRequestId() == requestId)
        {
            return &request;
        }
    }

    return nullptr;
}

// Find a request by identifier in a const database object.
const BloodRequest* BloodBankDatabase::findRequest(int requestId) const
{
    for (const BloodRequest& request : requests)
    {
        if (request.getRequestId() == requestId)
        {
            return &request;
        }
    }

    return nullptr;
}

// Add a staff record to the system.
void BloodBankDatabase::addStaff(const Staff& staff)
{
    staffMembers.push_back(staff);
}

// Add a hospital record to the system.
void BloodBankDatabase::addHospital(const Hospital& hospital)
{
    hospitals.push_back(hospital);
}

// Return a pointer to a staff member for the active session.
Staff* BloodBankDatabase::getStaff(int staffId)
{
    for (Staff& staffMember : staffMembers)
    {
        if (staffMember.getStaffId() == staffId)
        {
            return &staffMember;
        }
    }

    return nullptr;
}

// Return all donors for reporting or future expansion.
const std::vector<Donor>& BloodBankDatabase::getDonors() const
{
    return donors;
}

// Return all requests for reporting or future expansion.
const std::vector<BloodRequest>& BloodBankDatabase::getRequests() const
{
    return requests;
}

// Generate the next donor identifier.
int BloodBankDatabase::generateDonorId()
{
    return nextDonorId++;
}

// Generate the next request identifier.
int BloodBankDatabase::generateRequestId()
{
    return nextRequestId++;
}

// Generate the next blood unit identifier.
int BloodBankDatabase::generateUnitId()
{
    return nextUnitId++;
}
