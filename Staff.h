#ifndef STAFF_H
#define STAFF_H

#include <string>

// Staff stores login and identity information for blood bank employees.
class Staff
{
public:
    Staff(int staffId = 0, const std::string& name = "", const std::string& password = "");
    virtual ~Staff() = default;

    bool validatePassword(const std::string& password) const;
    int getStaffId() const;
    std::string getName() const;
    virtual void displayDetails() const;

private:
    int staffId;
    std::string name;
    std::string password;
};

#endif
