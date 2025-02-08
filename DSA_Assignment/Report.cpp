#include "Report.h"
#include <iostream>
using namespace std;

// Static variable to auto increment report IDs
int Report::currentReportId = 0;

Report::Report(string createdBy, string reportDescription) {
    this->createdBy = createdBy;
    this->reportDescription = reportDescription;
    this->reportId = ++currentReportId;
	this->resolved = false;
}

Report::~Report() {
}

string Report::getCreatedBy() {
    return createdBy;
}

string Report::getReportDescription() {
    return reportDescription;
}

int Report::getReportId() {
    return reportId;
}

void Report::resolveReport() {
	resolved = true;
}

void Report::displayReport() {
    cout << "Report ID: " << reportId << endl;
    cout << "Created By: " << createdBy << endl;
    cout << "Report Description: " << reportDescription << endl;
	cout << "Resolved: " << (resolved ? "Yes" : "No") << endl;
}