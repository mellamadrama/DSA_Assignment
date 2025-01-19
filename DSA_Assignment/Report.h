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
	// Constructor
    Report(string createdBy, string errorDescription, string type, int reportId);

	// Destructor
    ~Report();

	// Get the name of the user who created the report
	// pre : none
	// post: returns the name of the user who created the report
    string getCreatedBy() const;

	// Get the description of the error
	// pre : none
	// post: returns the description of the error
    string getErrorDescription() const;

	// Get the type of the report
	// pre : none
	// post: returns the type of the report
    string getType() const;

	// Get the ID of the report
	// pre : none
	// post: returns the ID of the report
    int getReportId() const;

	// Display the report
	// pre : none
	// post: prints the details of the report
    void displayReport() const;
};