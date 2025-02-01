#include "Report.h"
#include <iostream>
using namespace std;

// Static variable to auto increment report IDs
int Report::currentReportId = 0;

// Constructor
Report::Report(string createdBy, string reportDescription) {
    this->createdBy = createdBy;
    this->reportDescription = reportDescription;
    this->reportId = ++currentReportId;
	this->resolved = false;
}

// Destructor
Report::~Report() {
}

// Get the name of the user who created the report
// pre: none
// post: returns the name of the user who created the report
string Report::getCreatedBy() {
    return createdBy;
}

// Get the description of the error
// pre: none
// post: returns the description of the error
string Report::getReportDescription() {
    return reportDescription;
}

// Get the ID of the report
// pre: none
// post: returns the ID of the report
int Report::getReportId() {
    return reportId;
}

void Report::resolveReport() {
	resolved = true;
}

// Display the report
// pre: none
// post: prints the details of the report
void Report::displayReport() {
    cout << "Report ID: " << reportId << endl;
    cout << "Created By: " << createdBy << endl;
    cout << "Report Description: " << reportDescription << endl;
	cout << "Resolved: " << (resolved ? "Yes" : "No") << endl;
}