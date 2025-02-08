/*
* Name: Hervin Sie(S10262115C), Charlotte Lee(s10258027k)
* Group: 6
*/

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Report {
private:
    string createdBy;
    string reportDescription;
    int reportId;
	bool resolved;
	static int currentReportId;

public:
	// Constructor
    Report(string createdBy, string reportDescription);

	// Destructor
    ~Report();

	// Get the name of the user who created the report
	// pre : none
	// post: returns the name of the user who created the report
    string getCreatedBy();

	// Get the description of the error
	// pre : none
	// post: returns the description of the error
    string getReportDescription();

	// Get the ID of the report
	// pre : none
	// post: returns the ID of the report
    int getReportId();

	// Resolve the report
	// pre : none
	// post: sets the report as resolved
	void resolveReport();

	// Display the report
	// pre : none
	// post: prints the details of the report
    void displayReport();
};