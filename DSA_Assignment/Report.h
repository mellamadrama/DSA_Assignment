#pragma once

#include <string>
#include <iostream>
using namespace std;

class Report {
private:
    string createdBy;
    string errorDescription;
    string type;
    int reportId;

public:
    Report(string createdBy, string errorDescription, string type, int reportId);

    string getCreatedBy() const;

    string getErrorDescription() const;

    string getType() const;

    int getReportId() const;

    void displayReport() const;

    ~Report() = default;
};