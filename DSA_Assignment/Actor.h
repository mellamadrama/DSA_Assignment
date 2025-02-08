/*
* Name: Hervin Sie(S10262115C), Charlotte Lee(s10258027k)
* Group: 6
*/

#pragma once
#include <string>
#include "LinkedList.h"
#include "Global.h"
#include "Movie.h"
#include "Report.h"
using namespace std;

class Movie;

extern HashTable<Movie*> movieTable;

class Actor {
private:
    int id;
    string name;
    int yearOfBirth;
    float avgActorRating;
	LinkedList<Report*> listOfReports;
	LinkedList<float> listOfRatings;
    LinkedList<Movie*> listOfMovies;

public:
    // Constructor
    Actor(int id, string name, int yearOfBirth, float actorRating);

    // Destructor
    ~Actor();

    // Get the name of the actor
    // pre : none
    // post: returns the name of the actor
    string getName();

	//get the id of the actor
	//pre : none
	//post: returns the id of the actor
	int getId();

    // Get the year of birth of the actor
    // pre : none
    // post: returns the year of birth of the actor
    int getYearOfBirth();

	// Add a rating to the actor's ratings list
	// pre : rating is within a valid range
	// post: rating is added to the ratings list
	void addRating(float rating);

	// Get the rating of the actor
	// pre : none
	// post: returns the rating of the actor
    float getActorRating();

	// List all reports for the actor
	// pre : none
	// post: prints all reports for the actor
    bool listReports();

	// Display a report
	// pre : none
	// post: prints the details of the report
    void displayReport(Report* report);

	// Add a report to the actor
	// pre : none
	// post: report is added to the list of reports
    void addReport(Report* report);

	// Get the list of reports for the actor
	// pre : none
	// post: returns a reference to the list of reports
	LinkedList<Report*>& getReportList();

    // Add a movie to the actor's list of movies
    // pre : movie is a valid Movie object
    // post: movie is added to the actor's list of movies
    void addMovie(Movie* movie);

    // Display all movies the actor has acted in
    // pre : none
    // post: prints the titles of all movies the actor has acted in
    void displayMovies();

	// Get the age of the actor
	// pre : none
	// post: returns the age of the actor
    int getAge(); 

    // Update the actor's details
    // pre: newName is a valid string, newYearOfBirth is a positive integer
    // post: updates the name and year of birth of the actor
    void updateActorDetails(string& newName, int newYearOfBirth);
    // Get the list of movies the actor has acted in
    // pre : actor must have acted in movies
    // post: returns a constant reference to the list of movies
    LinkedList<Movie*>& getMovies();
};