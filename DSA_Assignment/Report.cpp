#include "Report.h"
#include <iostream>
using namespace std;

// Constructor
Report::Report(string createdBy, string errorDescription, string type, int reportId) {
    this->createdBy = createdBy;
    this->errorDescription = errorDescription;
    this->type = type;
    this->reportId = reportId;
}

// Destructor
Report::~Report() {
}

// Get the name of the user who created the report
// pre: none
// post: returns the name of the user who created the report
string Report::getCreatedBy() const {
    return createdBy;
}

// Get the description of the error
// pre: none
// post: returns the description of the error
string Report::getErrorDescription() const {
    return errorDescription;
}

// Get the type of the report
// pre: none
// post: returns the type of the report
string Report::getType() const {
    return type;
}

// Get the ID of the report
// pre: none
// post: returns the ID of the report
int Report::getReportId() const {
    return reportId;
}

// Display the report
// pre: none
// post: prints the details of the report
void Report::displayReport() const {
    cout << "Report ID: " << reportId << endl;
    cout << "Created By: " << createdBy << endl;
    cout << "Type: " << type << endl;
    cout << "Error Description: " << errorDescription << endl;
}