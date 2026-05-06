#include "Admin.h"

#include <iostream>

// Initialize an admin user.
Admin::Admin(int staffId, const std::string& name, const std::string& password)
    : Staff(staffId, name, password)
{
}

// Display a simple admin action message for staff creation.
void Admin::addStaff() const
{
    std::cout << "Admin can add new staff members to the system." << std::endl;
}

// Display a simple admin action message for staff removal.
void Admin::removeStaff() const
{
    std::cout << "Admin can remove staff members from the system." << std::endl;
}

// Display a simple admin action message for reports.
void Admin::viewReports() const
{
    std::cout << "Admin can view blood bank reports." << std::endl;
}

// Display a simple admin action message for stock monitoring.
void Admin::monitorStock() const
{
    std::cout << "Admin can monitor current blood stock levels." << std::endl;
}

// Display admin details along with the inherited staff information.
void Admin::displayDetails() const
{
    std::cout << "Role: Admin" << std::endl;
    Staff::displayDetails();
}
