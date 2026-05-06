#ifndef ADMIN_H
#define ADMIN_H

#include "Staff.h"

// Admin extends Staff with higher-level management responsibilities.
class Admin : public Staff
{
public:
    Admin(int staffId = 0, const std::string& name = "", const std::string& password = "");

    void addStaff() const;
    void removeStaff() const;
    void viewReports() const;
    void monitorStock() const;
    void displayDetails() const override;
};

#endif
