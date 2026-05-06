#include "Staff.h"

#include <iostream>

// Initialize a staff member with login details.
Staff::Staff(int staffId, const std::string& name, const std::string& password)
    : staffId(staffId),
      name(name),
      password(password)
{
}

// Check whether a provided password matches the stored password.
bool Staff::validatePassword(const std::string& password) const
{
    return this->password == password;
}

// Return the staff member identifier.
int Staff::getStaffId() const
{
    return staffId;
}

// Return the staff member name.
std::string Staff::getName() const
{
    return name;
}

// Display staff details on the screen.
void Staff::displayDetails() const
{
    std::cout << "Staff ID: " << staffId << '\n'
              << "Name: " << name << std::endl;
}
